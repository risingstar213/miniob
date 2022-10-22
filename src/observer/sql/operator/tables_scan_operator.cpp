#include "common/log/log.h"
#include "sql/operator/tables_scan_operator.h"
#include "storage/common/table.h"
#include "rc.h"


RC TablesScanOperator::open()
{
  RC rc = RC::SUCCESS;
  for (int i = 0; i < children_.size(); i++) {
    rc = children_[i]->open();
    if (rc != RC::SUCCESS) {
      LOG_WARN("one of table scan operator cannot be opened");
      return rc;
    }
  }

  return rc;
}

RC TablesScanOperator::next()
{
  RC rc = RC::SUCCESS;
}

RC TablesScanOperator::close()
{
  for (int i = 0; i < children_.size(); i++) {
    children_[i]->close();
  }

  return RC::SUCCESS;
}

std::vector<Tuple *> TablesScanOperator::current_tuple()
{
  std::vector<Tuple *> tuples;
  tuples.push_back(nullptr);
  return tuples;
}