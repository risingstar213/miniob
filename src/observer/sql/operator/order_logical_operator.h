#pragma once

#include "sql/operator/logical_operator.h"
#include "sql/parser/parse_defs.h"

#include "storage/field/field.h"

class OrderLogicalOperator : public LogicalOperator
{
public:
  OrderLogicalOperator(std::vector<Field> &all_fields, std::vector<Field> &order_fields, std::vector<uint8_t> &ascs);
  virtual ~OrderLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::ORDER;
  }


  std::vector<Field> &all_fields() 
  {
    return all_fields_;
  }

  std::vector<Field> &order_fields() 
  {
    return order_fields_;
  }

  std::vector<uint8_t> &ascs()
  {
    return ascs_;
  }

private:
  std::vector<Field> all_fields_;
  std::vector<Field> order_fields_;
  std::vector<uint8_t> ascs_;
};