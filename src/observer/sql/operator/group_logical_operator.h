#pragma once


#include <vector>

#include "sql/operator/logical_operator.h"
#include "sql/parser/parse_defs.h"

#include "storage/field/field.h"

class TupleCellSpec;

class GroupLogicalOperator : public LogicalOperator
{
public:
  GroupLogicalOperator(std::vector<Field> &fields);
  virtual ~GroupLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::GROUP;
  }

  std::vector<Field> &fields()
  {
    return fields_;
  }

private:
  std::vector<Field> fields_;
};