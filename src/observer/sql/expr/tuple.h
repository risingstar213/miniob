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
// Created by Wangyunlai on 2021/5/14.
//

#pragma once

#include <memory>
#include <vector>
#include <string>

#include "common/log/log.h"
#include "sql/parser/parse.h"
#include "sql/expr/tuple_cell.h"
#include "sql/expr/expression.h"
#include "storage/record/record.h"
#include "util/agg.h"

class Table;

class TupleCellSpec
{
public:
  TupleCellSpec() = default;
  TupleCellSpec(Expression *expr) : expression_(expr)
  {}

  ~TupleCellSpec()
  {
    if (expression_) {
      delete expression_;
      expression_ = nullptr;
    }
  }

  void set_alias(std::string alias)
  {
    this->alias_ = alias;
  }
  std::string alias() const
  {
    return alias_;
  }

  Expression *expression() const
  {
    return expression_;
  }

private:
  std::string alias_;
  Expression *expression_ = nullptr;
};

class Tuple
{
public:
  Tuple() = default;
  virtual ~Tuple() = default;

  virtual int cell_num() const = 0; 
  virtual RC  cell_at(int index, TupleCell &cell) const = 0;
  virtual RC  find_cell(const Field &field, TupleCell &cell) const = 0;

  virtual RC  cell_spec_at(int index, const TupleCellSpec *&spec) const = 0;
};

class RowTuple : public Tuple
{
public:
  RowTuple() = default;
  virtual ~RowTuple()
  {
    for (TupleCellSpec *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }
  
  void set_record(Record *record)
  {
    this->record_ = record;
  }

  void set_schema(const Table *table, const std::vector<FieldMeta> *fields)
  {
    table_ = table;
    this->speces_.reserve(fields->size());
    for (const FieldMeta &field : *fields) {
      speces_.push_back(new TupleCellSpec(new FieldExpr(table, &field)));
    }
  }

  int cell_num() const override
  {
    return speces_.size();
  }

  RC cell_at(int index, TupleCell &cell) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }

    const TupleCellSpec *spec = speces_[index];
    FieldExpr *field_expr = (FieldExpr *)spec->expression();
    const FieldMeta *field_meta = field_expr->field().meta();
    cell.set_type(field_meta->type());
    cell.set_data(this->record_->data() + field_meta->offset());
    cell.set_length(field_meta->len());
    return RC::SUCCESS;
  }

  RC find_cell(const Field &field, TupleCell &cell) const override
  {
    const char *table_name = field.table_name();
    if (0 != strcmp(table_name, table_->name())) {
      return RC::NOTFOUND;
    }

    const char *field_name = field.field_name();
    for (size_t i = 0; i < speces_.size(); ++i) {
      const FieldExpr * field_expr = (const FieldExpr *)speces_[i]->expression();
      const Field &field = field_expr->field();
      if (0 == strcmp(field_name, field.field_name())) {
	return cell_at(i, cell);
      }
    }
    return RC::NOTFOUND;
  }

  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }

  Record &record()
  {
    return *record_;
  }

  const Record &record() const
  {
    return *record_;
  }
private:
  Record *record_ = nullptr;
  const Table *table_ = nullptr;
  std::vector<TupleCellSpec *> speces_;
};

/*
class CompositeTuple : public Tuple
{
public:
  int cell_num() const override; 
  RC  cell_at(int index, TupleCell &cell) const = 0;
private:
  int cell_num_ = 0;
  std::vector<Tuple *> tuples_;
};
*/

class ProjectTuple : public Tuple
{
public:
  ProjectTuple() = default;
  virtual ~ProjectTuple()
  {
    for (size_t i = 0; i < agg_.size(); i++) {
      if (agg_[i] != AGG_NONE) {
        AggFunc::destroy_data(agg_[i], values_[i],speces_[i]->expression()->get_valuetype());
        delete values_[i];
      }
    }
    agg_.clear();
    values_.clear();
    for (TupleCellSpec *spec : speces_) {
      delete spec;
    }
    speces_.clear();
  }

  void set_tuples(std::vector<Tuple *> tuples)
  {
    if (is_aggregation_) {
      for (size_t i = 0; i < speces_.size(); i++) {
        if (agg_[i] != AGG_NONE) {
          TupleCell cell;
          speces_[i]->expression()->get_value(tuples, cell);
          AggFunc::add_data(agg_[i], values_[i], cell.attr_type(), (char *)cell.data(), cell.length());
        }
      }
    }
    this->tuples_ = tuples;
  }

  void add_cell_spec(TupleCellSpec *spec, Aggregation agg)
  {
    speces_.push_back(spec);
    agg_.push_back(agg);
    if (agg != Aggregation::AGG_NONE) {
      is_aggregation_ = is_aggregation_ || true;
      AggData *d = new AggData;
      AggFunc::init_data(agg, d, spec->expression()->get_valuetype());
      values_.push_back(d);
    } else {
      values_.push_back(nullptr);
    }
  }
  int cell_num() const override
  {
    return speces_.size();
  }

  RC cell_at(int index, TupleCell &cell) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::GENERIC_ERROR;
    }
    if (tuples_.size() == 0) {
      return RC::GENERIC_ERROR;
    }

    const TupleCellSpec *spec = speces_[index];
    if (agg_[index] != AGG_NONE) {
      LOG_INFO("cell at aggregation");
      cell.set_data(AggFunc::get_data(agg_[index], values_[index], speces_[index]->expression()->get_valuetype()));
      cell.set_type(AggFunc::get_attrtype(agg_[index], speces_[index]->expression()->get_valuetype()));
      if (cell.attr_type() == CHARS) {
          TupleCell cell1;
          speces_[index]->expression()->get_value(tuples_, cell1);
          cell.set_length(cell1.length());
      } else {
        cell.set_length(4);
      }
      return RC::SUCCESS;
    } else {
      return spec->expression()->get_value(tuples_, cell);
    }
  }

  RC find_cell(const Field &field, TupleCell &cell) const override
  {
    RC rc;
    for (uint i = 0; i < tuples_.size(); i++) {
      if ((rc = tuples_[i]->find_cell(field, cell)) == RC::SUCCESS) {
        return rc;
      }
    }
    return rc;
  }
  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::NOTFOUND;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }
private:
  std::vector<TupleCellSpec *> speces_;
  std::vector<Aggregation> agg_;
  std::vector<AggData *> values_;
  std::vector<Tuple *> tuples_;
  bool is_aggregation_ = false;
};
