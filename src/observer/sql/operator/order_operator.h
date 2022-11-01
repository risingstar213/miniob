#pragma once

#include <vector>
#include "sql/operator/operator.h"
#include "rc.h"

class OrderOperator : public Operator
{
public:
  OrderOperator(std::vector<OrderCol *> *order_col_)
  : cols_(order_col_)
  {}

  virtual ~OrderOperator() = default;

  RC open() override;
  RC next(std::vector<Tuple *> *context = nullptr) override;
  RC close() override;

  int tuple_cell_num() const
  {
    return tuple_.cell_num();
  }
    
  RC tuple_cell_spec_at(int index, const TupleCellSpec *&spec) const;

  std::vector<Tuple *> current_tuples() override;
private:
  ProjectTuple tuple_;
  std::vector<Tuple> tuples_;
  std::vector<OrderCol *> *cols_;
};