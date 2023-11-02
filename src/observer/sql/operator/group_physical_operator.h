#pragma once

#include "sql/parser/parse.h"
#include "sql/operator/physical_operator.h"
#include "sql/expr/expression.h"

class GroupPhysicalOperator : public PhysicalOperator
{
public:
  GroupPhysicalOperator(std::vector<Field> &all_fields, std::vector<Field> &group_fields, std::unique_ptr<Expression> &having_filters);

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
  Trx *trx_;
  GroupTuple tuple_;
  bool is_first_;
  bool has_group_;
  bool is_end_;
  std::vector<Field>          group_fields_;
  std::vector<Value>          group_values_;
  std::unique_ptr<Expression> having_filters_;
};