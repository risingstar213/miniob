#include "common/log/log.h"
#include "sql/operator/group_operator.h"

RC GroupOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("group operator must has one child");
    return RC::INTERNAL;
  }
  started_ = true;
  ended_ = false;
  if (group_expressions_.size() > 0) {

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

RC GroupOperator::do_having(std::vector<Tuple *> tuples, bool &result)
{
  return RC::SUCCESS;
}