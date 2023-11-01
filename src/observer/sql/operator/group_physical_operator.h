#pragma once

#include "sql/parser/parse.h"
#include "sql/operator/physical_operator.h"

class GroupPhysicalOperator : public PhysicalOperator
{
public:
  GroupPhysicalOperator(std::vector<Field> &fields);

  virtual ~GroupPhysicalOperator() = default;

  PhysicalOperatorType type() const override
  {
    return PhysicalOperatorType::GROUP;
  }
  
  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override;
private:
  GroupTuple tuple_;
  bool all_group_;
  bool is_end_;
};