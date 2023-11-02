#include "sql/operator/group_physical_operator.h"

GroupPhysicalOperator::GroupPhysicalOperator(std::vector<Field> &all_fields, std::vector<Field> &group_fields, std::unique_ptr<Expression> &having_filters)
  : tuple_(all_fields)
{
  group_fields_.swap(group_fields);
  having_filters_.swap(having_filters);
  LOG_INFO("all_field size: %d", all_fields.size());
}

RC GroupPhysicalOperator::open(Trx *trx) 
{
  if (children_.size() != 1) {
    LOG_WARN("group operator must has one child");
    return RC::INTERNAL;
  }
  is_first_= true;
  is_end_ = false;
  has_new_group_ = true;

  trx_ = trx;
  return children_[0]->open(trx);
}

RC GroupPhysicalOperator::next() 
{
  if (is_end_) {
    return RC::RECORD_EOF;
  }

  RC rc = RC::SUCCESS;
  PhysicalOperator *oper = children_.front().get();
//  tuple_.reset_value();

  Tuple *tuple = oper->current_tuple();
  Value value;

  while (true) {
    tuple_.reset_value();
    group_values_.clear();
    if (!is_first_) {
      tuple_.update_value(tuple);
      for (int i = 0; i < group_fields_.size(); i++) {
        TupleCellSpec spec(group_fields_[i].table_name(), group_fields_[i].field_name());
        rc = tuple->find_cell(spec, value);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        group_values_.push_back(value);
      }
    }
    while (RC::SUCCESS == (rc = (oper->next()))) {
      // LOG_INFO("get tuple !!!, group num: %d", group_fields_.size());
      rc = RC::SUCCESS;
      tuple = oper->current_tuple();
      if (nullptr == tuple) {
        rc = RC::INTERNAL;
        LOG_WARN("failed to get tuple from operator");
        return rc;
      }
      bool is_new_group = false;
      for (int i = 0; i < group_fields_.size(); i++) {
        TupleCellSpec spec(group_fields_[i].table_name(), group_fields_[i].field_name());
        rc = tuple->find_cell(spec, value);
        if (rc != RC::SUCCESS) {
          return rc;
        }
        if (is_first_) {
          group_values_.push_back(value);
          continue;
        }
        if (value.is_null() && group_values_[i].is_null()) {
          continue;
        }
        if (value.is_null() || group_values_[i].is_null()) {
          is_new_group = true;
          break;
        }
        // LOG_INFO("compare with group_values_");
        if (value.compare(group_values_[i]) != 0) {
          is_new_group = true;
          break;
        }
      }
      is_first_ = false;
      if (is_new_group) {
        break;
      }
      tuple_.update_value(tuple);
    }
    // meet new group
    if (rc == RC::SUCCESS) {
      if (having_filters_ == nullptr) {
        LOG_INFO("get one group, %s", tuple_.to_string().c_str());
        return RC::SUCCESS;
      }
      rc = having_filters_->get_value(tuple_, value, trx_);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      if (value.get_boolean()) {
        LOG_INFO("get one group");
        return RC::SUCCESS;
      } else {
        continue;
      }
    } else if (rc != RC::RECORD_EOF) {
      return rc;
    } else {
      is_end_ = true;

      if (having_filters_ == nullptr) {
        // LOG_INFO("end with one group");
        return RC::SUCCESS;
      }

      rc = having_filters_->get_value(tuple_, value, trx_);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      if (value.get_boolean()) {
        // LOG_INFO("end with one group");
        return RC::SUCCESS;
      } else {
        return RC::RECORD_EOF;
      }
    }
  }
  return RC::SUCCESS;
}
RC GroupPhysicalOperator::close() 
{
  children_[0]->close();
  return RC::SUCCESS;
}


Tuple *GroupPhysicalOperator::current_tuple()
{
  return &tuple_;
}
