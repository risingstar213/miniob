#pragma once

#include "sql/operator/operator.h"

#include <vector>
#include <stack>

class Table;
class TableScanOperator;

class TablesScanOperator : public Operator
{
public:
  TablesScanOperator()
  {

  }

  virtual ~TablesScanOperator() = default;

  RC open() override;
  RC next() override;
  RC close() override;

  std::vector<Tuple *> current_tuples() override;

private:
  std::vector<Tuple *> tuples_;
  bool start_ = false;
  bool stop_ = false;
  RC rc_;
};
