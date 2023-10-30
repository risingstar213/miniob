#include "sql/operator/group_physical_operator.h"

GroupPhysicalOperator::GroupPhysicalOperator(std::vector<Field> &fields) : tuple_(fields) {};

RC GroupPhysicalOperator::open(Trx *trx) 
{
  if (children_.size() != 1) {
    LOG_WARN("group operator must has one child");
    return RC::INTERNAL;
  }

  return children_[0]->open(trx);
}
RC GroupPhysicalOperator::next() 
{
  RC rc = RC::RECORD_EOF;
  PhysicalOperator *oper = children_.front().get();
  tuple_.reset_value();
  while (RC::SUCCESS == (oper->next())) {
    rc = RC::SUCCESS;
    Tuple *tuple = oper->current_tuple();
    if (nullptr == tuple) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get tuple from operator");
      break;
    }
    
    tuple_.update_value(tuple);
  }
  return rc;
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