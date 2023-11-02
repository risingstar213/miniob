#include "sql/operator/group_physical_operator.h"

GroupPhysicalOperator::GroupPhysicalOperator(std::vector<Field> &fields) : tuple_(fields) {}

RC GroupPhysicalOperator::open(Trx *trx) 
{
  if (children_.size() != 1) {
    LOG_WARN("group operator must has one child");
    return RC::INTERNAL;
  }
  is_end_ = false;

  return children_[0]->open(trx);
}
RC GroupPhysicalOperator::next() 
{
  if (is_end_) {
    return RC::RECORD_EOF;
  }
  RC rc = RC::SUCCESS;
  PhysicalOperator *oper = children_.front().get();
  tuple_.reset_value();
  while (RC::SUCCESS == (rc = (oper->next()))) {
    rc = RC::SUCCESS;
    Tuple *tuple = oper->current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get tuple from operator");
      break;
    }
    
    tuple_.update_value(tuple);
  }
  is_end_ = true;
  if (rc != RC::RECORD_EOF) {
    return rc;
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
