#pragma once

#include <unordered_set>

#include "sql/operator/operator.h"
#include "sql/expr/expression.h"
#include "sql/stmt/filter_stmt.h"

class GroupOperator : public Operator
{
public:
  GroupOperator() = default;
  GroupOperator(std::vector<Expression *> group_expressions,
        FilterStmt *having_filter, bool is_aggregation)
  {
    group_expressions_ = group_expressions;
    having_filter_ = having_filter;
    is_aggregation_ = is_aggregation;
  }

  RC open() override;
  RC next(std::vector<Tuple *> *context = nullptr) override;
  RC close() override;

  std::vector<Tuple *> current_tuples();
  // for having
  RC do_having(std::vector<Tuple *> tuples, bool &result);

  bool group_complete() { return group_complete_; }
  bool group_valid() { return group_valid_; }
  bool data_valid() { return data_valid_; }
private:
  std::unordered_set<int> set_;
  int count_this_cycle_;
  bool started_;
  bool ended_;
  bool data_valid_;
  bool group_valid_;
  bool group_complete_;

  std::vector<Expression *> group_expressions_;
  FilterStmt *having_filter_;
  bool is_aggregation_;
};

