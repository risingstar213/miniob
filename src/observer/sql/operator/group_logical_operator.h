#pragma once


#include <vector>

#include "sql/operator/logical_operator.h"
#include "sql/parser/parse_defs.h"

#include "storage/field/field.h"

class TupleCellSpec;

class GroupLogicalOperator : public LogicalOperator
{
public:
  GroupLogicalOperator(std::vector<Field> &all_fields, std::vector<Field> &group_fields, Expression *having_filters);
  virtual ~GroupLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::GROUP;
  }

  std::vector<Field> &all_fields()
  {
    return all_fields_;
  }

  std::vector<Field> &group_fields()
  {
    return group_fields_;
  }

  std::unique_ptr<Expression> &having_filters()
  {
    return having_filters_;
  }

private:
  std::vector<Field> all_fields_;
  std::vector<Field> group_fields_;
  std::unique_ptr<Expression> having_filters_;
};