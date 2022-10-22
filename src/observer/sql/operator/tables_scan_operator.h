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

  std::vector<Tuple *> current_tuple() override;

private:
};
