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

#pragma once

#include <string.h>
#include <vector>
#include "storage/common/field.h"
#include "sql/parser/parse_defs.h"
#include "sql/expr/tuple_cell.h"
#include "sql/stmt/select_stmt.h"
#include "util/agg.h"
#include "util/operator_helper.h"
#include "util/util.h"

class Tuple;
class Operator;

enum class ExprType {
  NONE,
  FIELD,
  VALUE,
  COMPLEX,
  SUBQUERY
};

class Expression
{
public: 
  Expression() = default;
  virtual ~Expression() = default;
  
  virtual RC get_value(const std::vector<Tuple *> tuples, TupleCell &cell) const = 0;
  virtual AttrType get_valuetype() const = 0;
  virtual ExprType type() const = 0;
  virtual void update_value(const std::vector<Tuple *> tuples) = 0;
  virtual bool is_null() const = 0;
};

class FieldExpr : public Expression
{
public:
  FieldExpr() = default;
  FieldExpr(const Table *table, const FieldMeta *field, Aggregation agg = AGG_NONE) : field_(table, field), agg_(agg)
  {
    if (agg_ != AGG_NONE) {
      data_ = new AggData;
      AggFunc::init_data(agg, data_, field_.attr_type());
    }
  }

  ~FieldExpr() {
    AggFunc::destroy_data(agg_, data_, field_.attr_type());
  };

  ExprType type() const override
  {
    return ExprType::FIELD;
  }

  Field &field()
  {
    return field_;
  }

  const Field &field() const
  {
    return field_;
  }

  const char *table_name() const
  {
    return field_.table_name();
  }

  const char *field_name() const
  {
    return field_.field_name();
  }

  RC get_value(const std::vector<Tuple *> tuples, TupleCell &cell) const override;

  AttrType get_valuetype() const {
    return field_.attr_type();
  }

  void update_value(const std::vector<Tuple *> tuples) override;

  bool is_null() const {
    return false;
  }
private:
  Field field_;
  TupleCell cell_;
  Aggregation agg_;
  AggData *data_;
};

class ValueExpr : public Expression
{
public:
  ValueExpr() = default;
  ValueExpr(const Value &value) : tuple_cell_(value.type, (char *)value.data)
  {
    if (value.type == CHARS || value.type == TEXTS) {
      tuple_cell_.set_length(strlen((const char *)value.data));
    }
  }

  virtual ~ValueExpr() = default;

  ExprType type() const override
  {
    return ExprType::VALUE;
  }

  void get_tuple_cell(TupleCell &cell) const {
    cell = tuple_cell_;
  }

  RC get_value(const std::vector<Tuple *> tuples, TupleCell & cell) const override;

  AttrType get_valuetype() const {
    return tuple_cell_.attr_type();
  }
  void update_value(const std::vector<Tuple *> tuples) {};

  bool is_null() const {
    if (tuple_cell_.length() < 4 && tuple_cell_.attr_type() == CHARS) {
      return false;
    }
    return ::is_null(tuple_cell_.data());
  }

private:
  TupleCell tuple_cell_;
};

class ComplexExpr : public Expression
{
public:
  ComplexExpr() = default;
  ComplexExpr(SelectExpr *expr, Expression *left, Expression *right)
    : expr_(expr), left_(left), right_(right)
  {
    data_ = (char *)new float;
  }
  ~ComplexExpr() {
    if (left_ != nullptr) {
      delete left_;
      left_ = nullptr;
    }
    if (right_ != nullptr) {
      delete right_;
      right_ = nullptr;
    }
    if (data_ != nullptr) {
      delete (float *)data_;
      data_ = nullptr;
    }
  }
  RC get_value(const std::vector<Tuple *> tuples, TupleCell &cell) const override;
  AttrType get_valuetype() const {
    return FLOATS;
  }
  ExprType type() const {
    return ExprType::COMPLEX;
  }
  void update_value(const std::vector<Tuple *> tuples) {
    if (left_ != nullptr) {
      left_->update_value(tuples);
    }
    if (right_ != nullptr) {
      right_->update_value(tuples);
    }
  }

  bool is_null() const {
    return false;
  }
private:
  SelectExpr *expr_;
  Expression *left_ = nullptr;
  Expression *right_ = nullptr;
  char *data_ = nullptr;
};

class SqueryExpr : public Expression
{
public:
  SqueryExpr() = default;
  SqueryExpr(SelectStmt *stmt) : stmt_(stmt) {
    oper_ = get_select_operator(stmt);
    is_list_ = false;
  }
  SqueryExpr(ValueList *list) : list_(list) {
    is_list_ = true;
  }
  ~SqueryExpr();

  ExprType type() const {
    return ExprType::SUBQUERY;
  }

  AttrType get_valuetype() const;
  // Get Context
  RC get_value(const std::vector<Tuple *> tuples, TupleCell &cell) const override;
  void update_value(const std::vector<Tuple *> tuples) {}

  RC exsits_cmp(bool &result);
  RC in_cmp(TupleCell cell, bool &result);
  RC not_in_cmp(TupleCell cell, bool &result);

  bool is_null() const {
    return false;
  }
private:
  bool is_list_;
  SelectStmt *stmt_ = nullptr;
  Operator *oper_ = nullptr;
  ValueList *list_ = nullptr;
};
