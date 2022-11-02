#include "common/log/log.h"
#include "sql/operator/group_operator.h"

void GroupOperator::append_ref_cells()
{
  auto tuples = children_[0]->current_tuples();
  for (size_t i = 0; i < group_expressions_.size(); i++) {
    TupleCell cell1;
    TupleCell cell2;
    group_expressions_[i]->get_value(tuples, cell1);
    cell2.deep_set(cell1);
    ref_cells_.push_back(cell2);
    LOG_INFO("append ref cells :%s", cell2.to_string().c_str());
  }
}

bool GroupOperator::compare_cells()
{
  auto tuples = children_[0]->current_tuples();
  for (size_t i = 0; i < group_expressions_.size(); i++) {
    TupleCell cell;
    group_expressions_[i]->get_value(tuples, cell);

    if ((ref_cells_[i].is_null()) && (cell.is_null())) {
      continue;
    }
    if (cell.compare(ref_cells_[i]) != 0) {
      return false;
    }
  }
  return true;
}

void GroupOperator::clear_ref_cells()
{
  for (size_t i = 0; i < ref_cells_.size(); i++) {
    delete []ref_cells_[i].data();
  }
  ref_cells_.clear();
}

void GroupOperator::update_having_datas()
{
  if (having_filter_ == nullptr) {
    return;
  }
  for (FilterUnit *unit : having_filter_->filter_units()) {
    unit->left()->update_value(children_[0]->current_tuples());
    unit->right()->update_value(children_[0]->current_tuples());
  }
}

void GroupOperator::reset_having_datas()
{
  if (having_filter_ == nullptr) {
    return;
  }
  for (FilterUnit *unit : having_filter_->filter_units()) {
    unit->left()->reset_value();
    unit->right()->reset_value();
  }
}

RC GroupOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("group operator must has one child");
    return RC::INTERNAL;
  }
  started_ = true;
  ended_ = false;
  if (group_expressions_.size() > 0) {
    group_complete_ = false;
    group_valid_ = false;
    data_valid_ = false;
    count_this_cycle_ = 0;
  } else if (is_aggregation_) {
    group_complete_ = false;
    group_valid_ = true;
    data_valid_ = true;
  } else {
    group_complete_ = true;
    group_valid_ = true;
    data_valid_ = true;
  }
  return children_[0]->open();
}

RC GroupOperator::next(std::vector<Tuple *> *context)
{
  if (ended_) {
    return RC::RECORD_EOF;
  }
  if (group_expressions_.size() > 0) {
    if (!started_) {
      children_[0]->open();
      started_ = true;
    }
    RC rc;
    while ((rc = children_[0]->next(context)) == RC::SUCCESS) {
      if (set_.find(count_this_cycle_) != set_.end()) {
        count_this_cycle_++;
        continue;
      }
      if (ref_cells_.size() == 0) { // get first
        append_ref_cells();
        set_.insert(count_this_cycle_);
        count_this_cycle_++;
        break;
      } else if (compare_cells()) { // get new 
        set_.insert(count_this_cycle_);
        count_this_cycle_++;
        break;
      }
      count_this_cycle_ ++;
    }
    if (rc == RC::SUCCESS) { // find data
      update_having_datas();
      group_complete_ = false;
      group_valid_ = false;
      data_valid_ = true;
      return rc;
    } else if (rc == RC::RECORD_EOF) { // group find
      group_complete_ = true;
      data_valid_ = false;
      group_valid_ = do_having();
      reset_having_datas();

      if (ref_cells_.size() == 0) {
        ended_ = true;
        group_valid_ = false;
      }
      clear_ref_cells();

      children_[0]->close();
      started_ = false;
      count_this_cycle_ = 0;
      return RC::SUCCESS;
    } else {
      return rc;
    }
  } else if (is_aggregation_) {
    RC rc;
    if ((rc = children_[0]->next(context)) == RC::RECORD_EOF) {
      ended_ = true;
      group_complete_ = true;
      data_valid_ = false;
      return RC::SUCCESS;
    }
    return rc;
  } else {
    return children_[0]->next(context);
  }
}

RC GroupOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}

std::vector<Tuple *> GroupOperator::current_tuples()
{
  return children_[0]->current_tuples();
}

bool GroupOperator::do_having()
{
  if (having_filter_ == nullptr) {
    return true;
  }
  std::vector<Tuple *> tuples; // stub valuable
  for (FilterUnit *unit : having_filter_->filter_units()) {
    TupleCell left_cell, right_cell;
    unit->left()->get_value(tuples, left_cell);
    unit->right()->get_value(tuples, right_cell);
    CompOp comp = unit->comp();
    int compare = left_cell.compare(right_cell);
    if (is_null((char *)&compare)) {
      return false;
    }
    bool filter_result = false;
    switch (comp) {
    case EQUAL_TO: {
      filter_result = (0 == compare); 
    } break;
    case LESS_EQUAL: {
      filter_result = (compare <= 0); 
    } break;
    case NOT_EQUAL: {
      filter_result = (compare != 0);
    } break;
    case LESS_THAN: {
      filter_result = (compare < 0);
    } break;
    case GREAT_EQUAL: {
      filter_result = (compare >= 0);
    } break;
    case GREAT_THAN: {
      filter_result = (compare > 0);
    } break;
    default: {
      LOG_ERROR("not supported!");
    } break;
    }
    if (!filter_result) {
      return false;
    }
  }
  return true;
}