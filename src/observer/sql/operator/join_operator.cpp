#include "common/log/log.h"
#include "sql/operator/join_operator.h"

RC JoinOperator::open()
{
  RC rc;
  rc = left_->open();
  if (rc != RC::SUCCESS) {
    return rc;
  }
  rc = right_->open();
  if (rc != RC::SUCCESS) {
    return rc;
  }
  if ((rc_ = left_->next()) != RC::SUCCESS) {
    stop_ = true;
  } else {
    stop_ = false;
  }
  start_ = true;
  return RC::SUCCESS;
}

RC JoinOperator::next()
{
  LOG_INFO("join next");
  if (stop_) {
    return rc_;
  }

  RC rc;
  while ((rc = right_->next()) != RC::SUCCESS) {
    if (start_) {
      return rc;
    }
    if ((rc = left_->next()) != RC::SUCCESS) {
      return rc;
    }
    right_->close();
    right_->open();
  }
  start_ = false;
  return RC::SUCCESS;
}

RC JoinOperator::close()
{
  left_->close();
  right_->close();
  return RC::SUCCESS;
}

std::vector<Tuple *> JoinOperator::current_tuples()
{
  LOG_INFO("join current_tuples");
  std::vector<Tuple *> left_tuples = left_->current_tuples();
  std::vector<Tuple *> right_tuples = right_->current_tuples();
  left_tuples.push_back(right_tuples[0]);
  return left_tuples;
}