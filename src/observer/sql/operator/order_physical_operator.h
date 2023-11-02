#pragma once

#include "sql/parser/parse.h"
#include "sql/operator/physical_operator.h"

class OrderPhysicalOperator : public PhysicalOperator
{
public:
  OrderPhysicalOperator(std::vector<Field> &all_fields, std::vector<Field> &order_fields, std::vector<uint8_t> &ascs);

  virtual ~OrderPhysicalOperator() = default;

  PhysicalOperatorType type() const override
  {
    return PhysicalOperatorType::ORDER;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override;

private:
  int order_fields_num_;
  int all_fields_num_;
  std::vector<uint8_t> ascs_;
  std::vector<std::vector<Value>> row_list_;
  std::vector<int>   order_idxes_;
  std::vector<int>   order_fields_idxes_;
  OrderTuple tuple_;
  int now_count_;
};