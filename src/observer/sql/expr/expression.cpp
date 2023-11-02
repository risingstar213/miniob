/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2022/07/05.
//

#include "sql/expr/expression.h"
#include "sql/expr/tuple.h"
#include "sql/parser/parse_defs.h"

#include "sql/optimizer/logical_plan_generator.h"
#include "sql/optimizer/physical_plan_generator.h"

#include "sql/utils/like.h"

using namespace std;

RC FieldExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  return tuple.find_cell(TupleCellSpec(table_name(), field_name()), value);
}

RC ValueExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  value = value_;
  return RC::SUCCESS;
}

/////////////////////////////////////////////////////////////////////////////////
CastExpr::CastExpr(unique_ptr<Expression> child, AttrType cast_type)
    : child_(std::move(child)), cast_type_(cast_type)
{
  set_name(child_->name());
}

CastExpr::~CastExpr()
{}

RC CastExpr::cast(const Value &value, Value &cast_value) const
{
  RC rc = RC::SUCCESS;
  if (this->value_type() == value.attr_type()) {
    cast_value = value;
    return rc;
  }

  switch (cast_type_) {
    case BOOLEANS: {
      bool val = value.get_boolean();
      cast_value.set_boolean(val);
    } break;
    default: {
      rc = RC::INTERNAL;
      LOG_WARN("unsupported convert from type %d to %d", child_->value_type(), cast_type_);
    }
  }
  return rc;
}

RC CastExpr::get_value(const Tuple &tuple, Value &cell, Trx *trx) const
{
  RC rc = child_->get_value(tuple, cell, trx);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return cast(cell, cell);
}

RC CastExpr::try_get_value(Value &value) const
{
  RC rc = child_->try_get_value(value);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  return cast(value, value);
}

////////////////////////////////////////////////////////////////////////////////

ComparisonExpr::ComparisonExpr(CompOp comp, unique_ptr<Expression> left, unique_ptr<Expression> right)
    : comp_(comp), left_(std::move(left)), right_(std::move(right))
{}

ComparisonExpr::~ComparisonExpr()
{}

RC ComparisonExpr::compare_value(const Value &left, const Value &right, bool &result) const
{
  RC rc = RC::SUCCESS;
  if (left.is_null() || right.is_null()) {
    result = false;
    return rc;
  }
  int cmp_result = left.compare(right);
  result = false;
  switch (comp_) {
    case EQUAL_TO: {
      result = (0 == cmp_result);
    } break;
    case LESS_EQUAL: {
      result = (cmp_result <= 0);
    } break;
    case NOT_EQUAL: {
      result = (cmp_result != 0);
    } break;
    case LESS_THAN: {
      result = (cmp_result < 0);
    } break;
    case GREAT_EQUAL: {
      result = (cmp_result >= 0);
    } break;
    case GREAT_THAN: {
      result = (cmp_result > 0);
    } break;
    
    default: {
      LOG_WARN("unsupported comparison. %d", comp_);
      rc = RC::INTERNAL;
    } break;
  }

  return rc;
}

RC ComparisonExpr::try_get_value(Value &cell) const
{
  bool simple_comp = comp_ <= GREAT_THAN;
  if (simple_comp && left_->type() == ExprType::VALUE && right_->type() == ExprType::VALUE) {
    ValueExpr *left_value_expr = static_cast<ValueExpr *>(left_.get());
    ValueExpr *right_value_expr = static_cast<ValueExpr *>(right_.get());
    const Value &left_cell = left_value_expr->get_value();
    const Value &right_cell = right_value_expr->get_value();

    bool value = false;
    RC rc = compare_value(left_cell, right_cell, value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to compare tuple cells. rc=%s", strrc(rc));
    } else {
      cell.set_boolean(value);
    }
    return rc;
  }

  return RC::INVALID_ARGUMENT;
}

RC ComparisonExpr::compare_with_set(const Tuple &tuple, Value &value, Trx *trx) const
{
  LOG_INFO("compare_with_set");
  SQueryExpr *expr = dynamic_cast<SQueryExpr *>(right_.get());
  Value left, right;
  if (comp_ == IN_SQ || comp_ == NOT_IN_SQ) {
    left_->get_value(tuple, left, trx);
  }

  RC rc = expr->open_sub_query(tuple, trx);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  // TODO: NULL
  switch (comp_) 
  {
    case IN_SQ: {
      if (left.is_null()) {
        value.set_boolean(false);
        break;
      }
      // if left is not null
      value.set_boolean(false);
      while ((rc = expr->next_sub_query(right)) == RC::SUCCESS) {
        if (right.is_null()) {
          continue;
        }
        if (left.compare(right) == 0) {
          value.set_boolean(true);
          break;
        }
      }
    } break;
    case NOT_IN_SQ: {
      if (left.is_null()) {
        value.set_boolean(false);
        break;
      }
      // if left is not null
      value.set_boolean(true);
      while ((rc = expr->next_sub_query(right)) == RC::SUCCESS) {
        if (right.is_null()) {
          value.set_boolean(false);
          break;
        }
        if (left.compare(right) == 0) {
          value.set_boolean(false);
          break;
        }
      }
    } break;
    case EXISTS_SQ: {
      value.set_boolean(false);
      while ((rc = expr->next_sub_query(right)) == RC::SUCCESS) {
        if (!right.is_null()) {
          value.set_boolean(true);
          break;
        }
      }
    } break;
    case NOT_EXISTS_SQ: {
      value.set_boolean(true);
      while ((rc = expr->next_sub_query(right)) == RC::SUCCESS) {
        if (!right.is_null()) {
          value.set_boolean(false);
          break;
        }
      }
    } break;
  }

  LOG_INFO("successfully compare_with_set %s", strrc(rc));

  RC close_rc = expr->close_sub_query();
  if (close_rc != RC::SUCCESS) {
    return close_rc;
  }

  if (rc != RC::RECORD_EOF) {
    return rc;
  } else {
    return RC::SUCCESS;
  }
}

RC ComparisonExpr::compare_null(const Tuple &tuple, Value &value, Trx *trx) const
{
  Value left_value;
  RC rc = left_->get_value(tuple, left_value, trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }

  if (comp_ == IS_NULL) {
    value.set_boolean(left_value.is_null());
  } else {
    value.set_boolean(!left_value.is_null());
  }
  return rc;
}

RC ComparisonExpr::compare_like(const Tuple &tuple, Value &value, Trx *trx) const
{
  Value left_value;
  Value right_value;
  RC rc = left_->get_value(tuple, left_value, trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }
  if (right_->type() != ExprType::VALUE) {
    LOG_WARN("right expr is not schema in like!" );
    return RC::INVALID_ARGUMENT;
  }
  rc = right_->get_value(tuple, right_value, trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }

  std::string left_str = left_value.get_string();
  std::string right_str = right_value.get_string();

  if (comp_ == LIKE_SCH) {
    value.set_boolean(LikeUnit::like_schema(left_str.c_str(), left_str.length(), right_str.c_str(), right_str.length()));
  } else {
    value.set_boolean(LikeUnit::unlike_schema(left_str.c_str(), left_str.length(), right_str.c_str(), right_str.length()));
  }
  return RC::SUCCESS;
}

RC ComparisonExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  if (comp_ == LIKE_SCH || comp_ == NOT_LIKE_SCH) {
    return compare_like(tuple, value, trx);
  }
  
  if (comp_ >= IN_SQ && comp_ <= NOT_EXISTS_SQ) {
    return compare_with_set(tuple, value, trx);
  }

  if (comp_ == IS_NULL || comp_ == IS_NOT_NULL) {
    return compare_null(tuple, value, trx);
  }
  
  Value left_value;
  Value right_value;

  RC rc = left_->get_value(tuple, left_value, trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
    return rc;
  }
  rc = right_->get_value(tuple, right_value, trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }

  bool bool_value = false;
  rc = compare_value(left_value, right_value, bool_value);
  if (rc == RC::SUCCESS) {
    value.set_boolean(bool_value);
  }
  return rc;
}

////////////////////////////////////////////////////////////////////////////////
ConjunctionExpr::ConjunctionExpr(Type type, vector<unique_ptr<Expression>> &children)
    : conjunction_type_(type), children_(std::move(children))
{}

RC ConjunctionExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    value.set_boolean(true);
    return rc;
  }

  Value tmp_value;
  for (const unique_ptr<Expression> &expr : children_) {
    rc = expr->get_value(tuple, tmp_value, trx);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value by child expression. rc=%s", strrc(rc));
      return rc;
    }
    bool bool_value = tmp_value.get_boolean();
    if ((conjunction_type_ == Type::AND && !bool_value) || (conjunction_type_ == Type::OR && bool_value)) {
      value.set_boolean(bool_value);
      return rc;
    }
  }

  bool default_value = (conjunction_type_ == Type::AND);
  value.set_boolean(default_value);
  return rc;
}

////////////////////////////////////////////////////////////////////////////////

ArithmeticExpr::ArithmeticExpr(ArithmeticExpr::Type type, Expression *left, Expression *right)
    : arithmetic_type_(type), left_(left), right_(right)
{}
ArithmeticExpr::ArithmeticExpr(ArithmeticExpr::Type type, unique_ptr<Expression> left, unique_ptr<Expression> right)
    : arithmetic_type_(type), left_(std::move(left)), right_(std::move(right))
{}

AttrType ArithmeticExpr::value_type() const
{
  if (!left_) {
    return right_->value_type();
  }

  if (left_->value_type() == AttrType::INTS &&
      right_->value_type() == AttrType::INTS &&
      arithmetic_type_ != Type::DIV) {
    return AttrType::INTS;
  }
  
  return AttrType::FLOATS;
}

RC ArithmeticExpr::calc_value(const Value &left_value, const Value &right_value, Value &value) const
{
  RC rc = RC::SUCCESS;

  if (left_value.is_null() || right_value.is_null()) {
    value.set_null(true);
    return rc;
  }

  const AttrType target_type = value_type();

  switch (arithmetic_type_) {
    case Type::ADD: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() + right_value.get_int());
      } else {
        value.set_float(left_value.get_float() + right_value.get_float());
      }
    } break;

    case Type::SUB: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() - right_value.get_int());
      } else {
        value.set_float(left_value.get_float() - right_value.get_float());
      }
    } break;

    case Type::MUL: {
      if (target_type == AttrType::INTS) {
        value.set_int(left_value.get_int() * right_value.get_int());
      } else {
        value.set_float(left_value.get_float() * right_value.get_float());
      }
    } break;

    case Type::DIV: {
      if (target_type == AttrType::INTS) {
        if (right_value.get_int() == 0) {
          // NOTE: 设置为整数最大值是不正确的。通常的做法是设置为NULL，但是当前的miniob没有NULL概念，所以这里设置为整数最大值。
          // value.set_int(numeric_limits<int>::max());
          value.set_null(true);
        } else {
          value.set_int(left_value.get_int() / right_value.get_int());
        }
      } else {
        if (right_value.get_float() > -EPSILON && right_value.get_float() < EPSILON) {
          // NOTE: 设置为浮点数最大值是不正确的。通常的做法是设置为NULL，但是当前的miniob没有NULL概念，所以这里设置为浮点数最大值。
          // value.set_float(numeric_limits<float>::max());
          value.set_null(true);
        } else {
          value.set_float(left_value.get_float() / right_value.get_float());
        }
      }
    } break;

    case Type::NEGATIVE: {
      if (target_type == AttrType::INTS) {
        value.set_int(-right_value.get_int());
      } else {
        value.set_float(-right_value.get_float());
      }
    } break;

    default: {
      rc = RC::INTERNAL;
      LOG_WARN("unsupported arithmetic type. %d", arithmetic_type_);
    } break;
  }
  return rc;
}

RC ArithmeticExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  RC rc = RC::SUCCESS;

  Value left_value;
  Value right_value;

  if (left_) {
    rc = left_->get_value(tuple, left_value, trx);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
      return rc;
    }
  }
  rc = right_->get_value(tuple, right_value, trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }
  return calc_value(left_value, right_value, value);
}

RC ArithmeticExpr::try_get_value(Value &value) const
{
  RC rc = RC::SUCCESS;

  Value left_value;
  Value right_value;

  if (left_) {
    rc = left_->try_get_value(left_value);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to get value of left expression. rc=%s", strrc(rc));
      return rc;
    }
  }

  // if (right_) {
  rc = right_->try_get_value(right_value);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to get value of right expression. rc=%s", strrc(rc));
    return rc;
  }
  // }

  return calc_value(left_value, right_value, value);
}

AggregationExpr::AggregationExpr(AggregationType type, Field field)
    : agg_type_(type), field_(field)
{}


AttrType AggregationExpr::value_type() const 
{
  if (agg_type_ == A_COUNT) {
    return INTS;
  } else if (agg_type_ == A_MAX || agg_type_ == A_MIN || agg_type_ == A_UNDEFINED) {
    return field_.attr_type();
  } else if (agg_type_ == A_SUM && field_.attr_type() == INTS) {
    return INTS;
  } else {
    return FLOATS;
  }
}

RC AggregationExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const 
{
  // it must be group tuple !!!
  const GroupTuple *group_tuple = dynamic_cast<const GroupTuple *>(&tuple);
  
  if (group_tuple == nullptr) {
    LOG_ERROR("Cannot pass AggregationExpr with Tuple which is not GroupTuple");
    return RC::INTERNAL;
  }
  Value temp;
  int count;
  TupleCellSpec cell(TupleCellSpec(field_.table_name(), field_.field_name()));
  switch (agg_type_)
  {
  case A_COUNT:
    return group_tuple->find_cell_count(cell, value);
    break;
  case A_SUM:
    return group_tuple->find_cell_sum(cell, value);
    break;
  case A_AVG:
    group_tuple->find_cell_count(cell, temp);
    count = temp.get_int();
    group_tuple->find_cell_sum(cell, temp);

    if (count == 0) {
      value.set_null(true);
    } else {
      value.set_float(temp.get_float() / count);
    }
    
    return RC::SUCCESS;
    break;
  case A_MAX:
    return group_tuple->find_cell_max(cell, value);
    break;
  case A_MIN:
    return group_tuple->find_cell_min(cell, value);
    break;
  default:
    return group_tuple->find_cell(cell, value);
    break;
  }
}

RC AggregationExpr::try_get_value(Value &value) const 
{
  return RC::UNIMPLENMENT;
}

SQueryExpr::SQueryExpr(SelectStmt *stmt)
  : stmt_(stmt)
{
  is_list_ = false;
  if (operator_ == nullptr) {
    std::unique_ptr<LogicalOperator> logical_oper;
    LogicalPlanGenerator logical_generator;
    logical_generator.create(stmt_.get(), logical_oper);
    PhysicalPlanGenerator physical_generator;
    std::unique_ptr<PhysicalOperator> physical_oper;
    physical_generator.create(*logical_oper, physical_oper);
    operator_ = physical_oper.release();
  }
}

SQueryExpr::SQueryExpr(std::vector<Value> &value_list)
{
  is_list_ = true;
  value_list_.swap(value_list);
  count_ = 0;
}

SQueryExpr::~SQueryExpr()
{
  if (operator_ != nullptr) {
    delete operator_;
    operator_ = nullptr;
  }
}

AttrType SQueryExpr::value_type() const
{
  if (is_list_) {
    return value_list_[0].attr_type();
  }
  return stmt_->query_exprs()[0]->value_type();
}

// get only one value, used for comparison
RC SQueryExpr::get_value(const Tuple &tuple, Value &value, Trx *trx) const
{
  // TODO: store tuple in ctx.
  LOG_INFO("SQueryExpr::get_value");
  if (is_list_) {
    LOG_ERROR("Value List cannot get value");
    return RC::INTERNAL;
  }

  if (operator_ == nullptr) {
    return RC::INTERNAL;
  }
  RC rc = RC::SUCCESS;
  if (trx == nullptr) {
    LOG_ERROR("SQueryExpr should get a trx!");
    return RC::INTERNAL;
  }
  // important
  operator_->set_ctx_tuple(const_cast<Tuple *>(&tuple));

  rc = operator_->open(trx);
  if (rc != RC::SUCCESS) {
    return RC::INTERNAL;
  }
  rc = operator_->next();
  // return NULL !!!
  if (rc == RC::RECORD_EOF) {
    // LOG_WARN("SQueryExpr::get_value should have one row, not zero");
    operator_->close();
    value.set_null(true);
    return RC::SUCCESS;
  } else if (rc != RC::SUCCESS) {
    operator_->close();
    return rc;
  }
  Tuple *project_tuple = operator_->current_tuple();
  if (project_tuple->cell_num() != 1) {
     LOG_WARN("SQueryExpr::get_value should have only one column");
    operator_->close();
    return RC::INTERNAL;
  }
  // the first
  rc = project_tuple->cell_at(0, value);
  if (rc != RC::SUCCESS) {
    operator_->close();
    return rc;
  }
  rc = operator_->next();
  if (rc != RC::RECORD_EOF) {
    LOG_WARN("SQueryExpr::get_value should have only one row");
    operator_->close();
    return RC::INTERNAL;
  }
  operator_->close();
  return RC::SUCCESS;
}

RC SQueryExpr::open_sub_query(const Tuple &tuple, Trx *trx)
{
  // TODO: store tuple in ctx.
  if (is_list_) {
    LOG_INFO("SQueryExpr::open_sub_query is list !!!");
    count_ = 0;
    return RC::SUCCESS;
  }
  if (operator_ == nullptr) {
    return RC::INTERNAL;
  }
  RC rc = RC::SUCCESS;
  if (trx == nullptr) {
    LOG_ERROR("SQueryExpr should get a trx!");
    return RC::INTERNAL;
  }
  // important
  operator_->set_ctx_tuple(const_cast<Tuple *>(&tuple));
  rc = operator_->open(trx);
  if (rc != RC::SUCCESS) {
    return RC::INTERNAL;
  }
  return RC::SUCCESS;
}

RC SQueryExpr::next_sub_query(Value &value)
{
  if (is_list_) {
    if (count_ >= value_list_.size()) {
      return RC::RECORD_EOF;
    }
    value = value_list_[count_];
    count_ += 1;
    return RC::SUCCESS;
  }
  RC rc = operator_->next();
  // return NULL !!!
  if (rc == RC::RECORD_EOF) {
    return RC::RECORD_EOF;
  } else if (rc != RC::SUCCESS) {
    return rc;
  }
  Tuple *project_tuple = operator_->current_tuple();
  if (project_tuple->cell_num() != 1) {
    LOG_WARN("SQueryExpr::get_value should have only one column");
    return RC::INTERNAL;
  }
  // the first
  rc = project_tuple->cell_at(0, value);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  return RC::SUCCESS;
}

RC SQueryExpr::close_sub_query()
{
  if (is_list_) {
    count_ = 0;
    return RC::SUCCESS;
  }
  return operator_->close();
}

RC SQueryExpr::try_get_value(Value &value) const
{
  return RC::INTERNAL;
}