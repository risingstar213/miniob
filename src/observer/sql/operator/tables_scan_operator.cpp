#include "common/log/log.h"
#include "sql/operator/tables_scan_operator.h"
#include "storage/common/table.h"
#include "rc.h"


RC TablesScanOperator::open()
{
  RC rc = RC::SUCCESS;
  stop_ = false;
  for (uint i = 0; i < children_.size(); i++) {
    rc = children_[i]->open();
    if (rc != RC::SUCCESS) {
      LOG_WARN("one of table scan operator cannot be opened");
      return rc;
    }
    if (i < children_.size() - 1) {
      rc_ = children_[i]->next();
      if (rc_ != RC::SUCCESS) {
        // There is no record in this table
        stop_ = true;
        break;
      }
      tuples_.push_back(children_[i]->current_tuples()[0]);
    } else {
      tuples_.push_back(nullptr);
    }
  }
  start_ = true;
  return rc;
}

RC TablesScanOperator::next(std::vector<Tuple *> *context)
{
  // if there is any empty tuple
  if (stop_) {
    return rc_;
  }
  RC rc;
  int stack_top = children_.size() - 1;
  while((rc = children_[stack_top]->next(context)) != RC::SUCCESS) {
    if (start_ || stack_top == 0) {
      return rc;
    }
    stack_top --;
  }
  for (uint i = stack_top+1; i < children_.size(); i++) {
    children_[i]->close();
    children_[i]->open();
    children_[i]->next(context);
  }
  for (uint i = stack_top; i < children_.size(); i++) {
    tuples_[i] = children_[i]->current_tuples()[0];
  }
  start_ = false;
  return RC::SUCCESS;
}

RC TablesScanOperator::close()
{
  for (uint i = 0; i < children_.size(); i++) {
    children_[i]->close();
  }

  return RC::SUCCESS;
}

std::vector<Tuple *> TablesScanOperator::current_tuples()
{
  return tuples_;
}