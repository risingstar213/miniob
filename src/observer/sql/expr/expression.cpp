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
// Created by Wangyunlai on 2022/07/05.
//

#include "sql/expr/tuple.h"
#include "sql/operator/operator.h"
#include "sql/stmt/select_stmt.h"
#include "util/comparator.h"
#include "util/util.h"


RC FieldExpr::get_value(const std::vector<Tuple *> tuples, TupleCell &cell) const
{
  if (agg_ ==AGG_NONE) {
    for (uint i = 0; i < tuples.size(); i++) {
      if (tuples[i]->find_cell(field_, cell) == RC::SUCCESS) {
        return RC::SUCCESS;
      }
    }
  } else {
    cell.set_data(AggFunc::get_data(agg_, data_, field_.attr_type()));
    cell.set_type(AggFunc::get_attrtype(agg_, field_.attr_type()));
    if (cell.attr_type() == CHARS || cell.attr_type() == TEXTS) {
        cell.set_length(cell_.length());
    } else {
      cell.set_length(4);
    }
    return RC::SUCCESS;
  }
  LOG_INFO("not found tuples");
  return RC::NOTFOUND;
}

void FieldExpr::update_value(const std::vector<Tuple *> tuples)
{
  for (uint i = 0; i < tuples.size(); i++) {
    if (tuples[i]->find_cell(field_, cell_) == RC::SUCCESS) {
      break;
    }
  }
  if (agg_ != AGG_NONE) {
    AggFunc::add_data(agg_, data_, cell_.attr_type(), (char *)cell_.data(), cell_.length());
  }
}

RC ValueExpr::get_value(const std::vector<Tuple *> tuples, TupleCell & cell) const
{
  cell = tuple_cell_;
  return RC::SUCCESS;
}

RC ComplexExpr::get_value(const std::vector<Tuple *> tuples, TupleCell &cell) const
{
  TupleCell left_cell, right_cell;
  float left_value, right_value;
  if (left_ != nullptr) {
    left_->get_value(tuples, left_cell);
    if (left_cell.attr_type() == INTS) {
      left_value = *(int *)left_cell.data();
    } else if (left_cell.attr_type() == FLOATS) {
      left_value = *(float *)left_cell.data();
    }
  }
  if (right_ != nullptr) {
    right_->get_value(tuples, right_cell);
    if (right_cell.attr_type() == INTS) {
      right_value = *(int *)right_cell.data();
    } else if (right_cell.attr_type() == FLOATS) {
      right_value = *(float *)right_cell.data();
    }
  }
  switch (expr_->arithOp) {
    case ARITH_ADD: {
      *(float *)data_ = left_value + right_value;
    } break;
    case ARITH_SUB: {
      *(float *)data_ = left_value - right_value;
    } break;
    case ARITH_MUL: {
      *(float *)data_ = left_value * right_value;
    } break;
    case ARITH_DIV: {
      *(float *)data_ = left_value / right_value;
    } break;
    case ARITH_NEG: {
      *(float *)data_ = - right_value;
    } break;
    default:
      break;
  }
  cell.set_data(data_);
  cell.set_type(FLOATS);
  cell.set_length(4);
  return RC::SUCCESS;
}

RC SqueryExpr::get_value(const std::vector<Tuple *> tuples, TupleCell &cell) const
{
  if (is_list_) {
    return RC::INVALID_ARGUMENT;
  }
  if (stmt_->select_exprs().size() != 1) {
    LOG_INFO("This type of select sq is not allowed");
    return RC::INVALID_ARGUMENT;
  }
  RC rc = RC::SUCCESS;
  rc = oper_->open();
  if (rc != RC::SUCCESS) {
    return rc;
  }
  int count = 0;
  while ((rc = oper_->next(const_cast<std::vector<Tuple *>* >(&tuples))) == RC::SUCCESS) {
    Tuple *tuple = oper_->current_tuples()[0];
    tuple->cell_at(0, cell);
    count += 1;
  }
  // LOG_INFO("SqueryExpr::get_value %d", count);
  if (count != 1) {
    oper_->close();
    LOG_WARN("This type of select sq is not allowed");
    return RC::INVALID_ARGUMENT;
  }

  // if (count == 0) {
  //   int *data = new int;
  //   *data = NULL_CONST;
  //   cell.set_data((char *)data);
  //   cell.set_length(4);
  //   cell.set_type(INTS);
  // }

  oper_->close();
  if (rc != RC::RECORD_EOF) {
    return RC::INVALID_ARGUMENT;
  } else {
    return RC::SUCCESS;
  }
}

RC SqueryExpr::exsits_cmp(const std::vector<Tuple *> tuples, bool &result)
{
  RC rc = RC::SUCCESS;
  if (is_list_) {
    return RC::INVALID_ARGUMENT;
  }
  rc = oper_->open();
  if (rc != RC::SUCCESS) {
    return rc;
  }
  int count = 0;
  while ((rc = oper_->next(const_cast<std::vector<Tuple *>* >(&tuples))) == RC::SUCCESS) {
    Tuple *tuple = oper_->current_tuples()[0];
    TupleCell cell;
    bool null_record = true;
    for (int i = 0; i < tuple->cell_num(); i++) {
      tuple->cell_at(i, cell);
      if (!::is_null(cell.data())) {
        null_record = false;
      }
    }
    if (!null_record) {
      count += 1;
    }
  }
  if (count > 0) {
    result = true;
  } else {
    result = false;
  }
  oper_->close();
  // *** maybe invalid argument ***
  if (rc != RC::RECORD_EOF) {
    return RC::INVALID_ARGUMENT;
  } else {
    return RC::SUCCESS;
  }
}
RC SqueryExpr::in_cmp(TupleCell cell, const std::vector<Tuple *> tuples, bool &result)
{
  result = false;
  if (is_list_) {
    for (auto &value : *list_) {
      bool cond = value.type != CHARS || (value.type == CHARS && strlen((char *)value.data) >= 4);
      bool right_null = cond && ::is_null((const char *)value.data);
      if (right_null) {
        continue;
      }
      TupleCell cmp_cell(value.type, (char *)value.data);
      if (cell.compare(cmp_cell) == 0) {
        result = true;
        break;
      }
    }
    return RC::SUCCESS;
  }
  if (stmt_->select_exprs().size() != 1) {
    LOG_INFO("This type of select sq is not allowed");
    return RC::INVALID_ARGUMENT;
  }
  RC rc = RC::SUCCESS;
  rc = oper_->open();
  if (rc != RC::SUCCESS) {
    return rc;
  }
  while ((rc = oper_->next(const_cast<std::vector<Tuple *>* >(&tuples))) == RC::SUCCESS) {
    Tuple *tuple = oper_->current_tuples()[0];
    TupleCell cmp_cell;
    tuple->cell_at(0, cmp_cell);
    // judge null
    bool right_null = cmp_cell.length() >= 4 && ::is_null(cmp_cell.data());
    if (right_null) {
      continue;
    }
    if (cell.compare(cmp_cell) == 0) {
      result = true;
      break;
    }
  }
  oper_->close();
  if (rc != RC::RECORD_EOF && rc != RC::SUCCESS) {
    return RC::INVALID_ARGUMENT;
  } else {
    return RC::SUCCESS;
  }
}

RC SqueryExpr::not_in_cmp(TupleCell cell, const std::vector<Tuple *> tuples, bool &result)
{
  result = true;
  if (is_list_) {
    for (auto &value : *list_) {
      bool cond = value.type != CHARS || (value.type == CHARS && strlen((char *)value.data) >= 4);
      bool right_null = cond && ::is_null((const char *)value.data);
      if (right_null) {
        result = false;
        break;
      }
      TupleCell cmp_cell(value.type, (char *)value.data);
      if (cell.compare(cmp_cell) == 0) {
        result = false;
        break;
      }
    }
    return RC::SUCCESS;
  }
  if (stmt_->select_exprs().size() != 1) {
    LOG_INFO("This type of select sq is not allowed");
    return RC::INVALID_ARGUMENT;
  }
  RC rc = RC::SUCCESS;
  rc = oper_->open();
  if (rc != RC::SUCCESS) {
    return rc;
  }
  while ((rc = oper_->next(const_cast<std::vector<Tuple *>* >(&tuples))) == RC::SUCCESS) {
    Tuple *tuple = oper_->current_tuples()[0];
    TupleCell cmp_cell;
    tuple->cell_at(0, cmp_cell);
    // judge null
    bool right_null = cmp_cell.length() >= 4 && ::is_null(cmp_cell.data());
    if (right_null) {
      result = false;
      break;
    }
    if (cell.compare(cmp_cell) == 0) {
      result = false;
      break;
    }
  }
  oper_->close();
  if (rc != RC::RECORD_EOF && rc != RC::SUCCESS) {
    return RC::INVALID_ARGUMENT;
  } else {
    return RC::SUCCESS;
  }
}

SqueryExpr::~SqueryExpr() {
  if (oper_ != nullptr) {
    delete oper_;
  }
  if (stmt_ != nullptr) {
    delete stmt_;
  }
}

AttrType SqueryExpr::get_valuetype() const {
  if (is_list_) {
    return (*list_)[0].type;
  } else {
    return stmt_->select_exprs()[0].type;
  }
}