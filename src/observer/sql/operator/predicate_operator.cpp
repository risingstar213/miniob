/* Copyright (c) 2021 Xie Meiyi(xiemeiyi@hust.edu.cn) and OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by WangYunlai on 2022/6/27.
//

#include "common/log/log.h"
#include "sql/operator/predicate_operator.h"
#include "storage/record/record.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/field.h"
#include "util/like.h"
#include "util/util.h"

RC PredicateOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("predicate operator must has one child");
    return RC::INTERNAL;
  }

  return children_[0]->open();
}

RC PredicateOperator::next(std::vector<Tuple *> *context)
{
  RC rc = RC::SUCCESS;
  Operator *oper = children_[0];
  
  while (RC::SUCCESS == (rc = oper->next(context))) {
    std::vector<Tuple *> tuples = oper->current_tuples();
    if (nullptr == tuples[0]) {
      rc = RC::INTERNAL;
      LOG_WARN("failed to get tuple from operator");
      break;
    }
    bool result;
    if (context != nullptr) {
      tuples.insert(tuples.end(), context->begin(), context->end());
    }
    rc = do_predicate(tuples, result);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    if (result) {
      return rc;
    }
  }
  return rc;
}

RC PredicateOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}

std::vector<Tuple *> PredicateOperator::current_tuples()
{
  return children_[0]->current_tuples();
}

RC PredicateOperator::do_predicate(std::vector<Tuple *> tuples, bool &result)
{
  RC rc = RC::SUCCESS;
  if (filter_stmt_ == nullptr || filter_stmt_->filter_units().empty()) {
    result = true;
    return rc;
  }

  for (const FilterUnit *filter_unit : filter_stmt_->filter_units()) {
    Expression *left_expr = filter_unit->left();
    Expression *right_expr = filter_unit->right();
    CompOp comp = filter_unit->comp();
    TupleCell left_cell;
    TupleCell right_cell;
    if (comp <= NOT_IN_SQ) {
      rc = left_expr->get_value(tuples, left_cell);
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }
    if (comp <= IS_NOT_NULL) {
      rc = right_expr->get_value(tuples, right_cell);
      if (rc != RC::SUCCESS) {
        return rc;
      }
    }
    int compare;
    if (comp <= GREAT_THAN) {
      compare = left_cell.compare(right_cell);
      if (is_null((char *)&compare)) {
        result =  false;
        return rc;
      }
    }
    bool filter_result = false;
    switch (comp) {
    case EQUAL_TO: {
      filter_result = (0 == compare); 
    } break;
    case LESS_EQUAL: {
      filter_result = (compare <= 0); 
    } break;
    case NOT_EQUAL: {
      filter_result = (compare != 0);
    } break;
    case LESS_THAN: {
      filter_result = (compare < 0);
    } break;
    case GREAT_EQUAL: {
      filter_result = (compare >= 0);
    } break;
    case GREAT_THAN: {
      filter_result = (compare > 0);
    } break;
    case LIKE_SCH: {
      filter_result = LikeUnit::like_schema(left_cell.data(),
                                            strlen(left_cell.data()),
                                            right_cell.data(),
                                            strlen(right_cell.data()));
    } break;
    case UNLIKE_SCH: {
      filter_result = LikeUnit::unlike_schema(left_cell.data(),
                                              strlen(left_cell.data()),
                                              right_cell.data(),
                                              strlen(right_cell.data()));
    } break;
    case IS_NULL: {
      if (left_cell.attr_type() == CHARS && left_cell.length() < 4) {
        filter_result = false;
      } else {
        filter_result = is_null(left_cell.data());
      }
    } break;
    case IS_NOT_NULL: {
      if (left_cell.attr_type() == CHARS && left_cell.length() < 4) {
        filter_result = true;
      } else {
        filter_result = !is_null(left_cell.data());
      }
    } break;
    case EXISTS_SQ: {
      if (right_expr->type() != ExprType::SUBQUERY) {
        return RC::INVALID_ARGUMENT;
      }
      SqueryExpr *rexpr = (SqueryExpr *)right_expr;
      rc = rexpr->exsits_cmp(tuples, filter_result);
      if (rc != RC::SUCCESS) {
        return rc;
      }
    } break;
    case NOT_EXISTS_SQ: {
      if (right_expr->type() != ExprType::SUBQUERY) {
        return RC::INVALID_ARGUMENT;
      }
      SqueryExpr *rexpr = (SqueryExpr *)right_expr;
      rc = rexpr->exsits_cmp(tuples, filter_result);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      filter_result = !filter_result;
    } break;
    case IN_SQ: {
      if (right_expr->type() != ExprType::SUBQUERY) {
        return RC::INVALID_ARGUMENT;
      }
      if (left_cell.length() >= 4 && ::is_null(left_cell.data())) {
        filter_result = false;
      } else {
        SqueryExpr *rexpr = (SqueryExpr *)right_expr;
        rc = rexpr->in_cmp(left_cell, tuples, filter_result);
        if (rc != RC::SUCCESS) {
          return rc;
        }
      }
    } break;
    case NOT_IN_SQ: {
      if (right_expr->type() != ExprType::SUBQUERY) {
        return RC::INVALID_ARGUMENT;
      }
      if (left_cell.length() >= 4 && ::is_null(left_cell.data())) {
        filter_result = false;
      } else {
        SqueryExpr *rexpr = (SqueryExpr *)right_expr;
        rc = rexpr->not_in_cmp(left_cell, tuples, filter_result);
        if (rc != RC::SUCCESS) {
          return rc;
        }
      }
    } break;
    default: {
      LOG_WARN("invalid compare type: %d", comp);
    } break;
    }
    if (!filter_result) {
      result = false;
      return rc;;
    }
  }
  result = true;
  return rc;
}

// int PredicateOperator::tuple_cell_num() const
// {
//   return children_[0]->tuple_cell_num();
// }
// RC PredicateOperator::tuple_cell_spec_at(int index, TupleCellSpec &spec) const
// {
//   return children_[0]->tuple_cell_spec_at(index, spec);
// }
