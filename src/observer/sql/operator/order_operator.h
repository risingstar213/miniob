#pragma once

#include <vector>
#include "sql/operator/operator.h"
#include "rc.h"

class OrderOperator : public Operator
{
public:
  OrderOperator(std::vector<OrderCol *> order_col_, std::vector<Field> order_fields, std::vector<Table*> tables)
  : cols_(order_col_), fields_(order_fields), tables_(tables)
  {}

  virtual ~OrderOperator() = default;

  RC open() override;
  RC next(std::vector<Tuple *> *context = nullptr) override;
  RC close() override;
    
  RC tuple_cell_spec_at(int index, const TupleCellSpec *&spec) const;

  std::vector<Tuple *> current_tuples() override;
  //bool cmp(std::vector<TupleCell> &a, std::vector<TupleCell> &b);
private:
  OrderTuple orderTuple;
  std::vector<OrderCol *> cols_;
  std::vector<Field> fields_;
  std::vector<Table*> tables_;
};