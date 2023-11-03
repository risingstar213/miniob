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
// Created by Wangyunlai on 2021/5/14.
//

#pragma once

#include <memory>
#include <vector>
#include <string>

#include "common/log/log.h"
#include "sql/expr/tuple_cell.h"
#include "sql/parser/parse.h"
#include "sql/parser/value.h"
#include "sql/expr/expression.h"
#include "storage/record/record.h"

class Table;

/**
 * @defgroup Tuple
 * @brief Tuple 元组，表示一行数据，当前返回客户端时使用
 * @details 
 * tuple是一种可以嵌套的数据结构。
 * 比如select t1.a+t2.b from t1, t2;
 * 需要使用下面的结构表示：
 * @code {.cpp}
 *  Project(t1.a+t2.b)
 *        |
 *      Joined
 *      /     \
 *   Row(t1) Row(t2)
 * @endcode
 * 
 */

/**
 * @brief 元组的结构，包含哪些字段(这里成为Cell)，每个字段的说明
 * @ingroup Tuple
 */
class TupleSchema 
{
public:
  void append_cell(const TupleCellSpec &cell)
  {
    cells_.push_back(cell);
  }
  void append_cell(const char *table, const char *field)
  {
    append_cell(TupleCellSpec(table, field));
  }
  void append_cell(const char *alias)
  {
    append_cell(TupleCellSpec(alias));
  }
  int cell_num() const
  {
    return static_cast<int>(cells_.size());
  }
  const TupleCellSpec &cell_at(int i) const
  {
    return cells_[i];
  }

private:
  std::vector<TupleCellSpec> cells_;
};

/**
 * @brief 元组的抽象描述
 * @ingroup Tuple
 */
class Tuple 
{
public:
  Tuple() = default;
  virtual ~Tuple() = default;

  /**
   * @brief 获取元组中的Cell的个数
   * @details 个数应该与tuple_schema一致
   */
  virtual int cell_num() const = 0;

  /**
   * @brief 获取指定位置的Cell
   * 
   * @param index 位置
   * @param[out] cell  返回的Cell
   */
  virtual RC cell_at(int index, Value &cell) const = 0;

  /**
   * @brief 根据cell的描述，获取cell的值
   * 
   * @param spec cell的描述
   * @param[out] cell 返回的cell
   */
  virtual RC find_cell(const TupleCellSpec &spec, Value &cell) const = 0;

  virtual std::string to_string() const
  {
    std::string str;
    const int cell_num = this->cell_num();
    for (int i = 0; i < cell_num - 1; i++) {
      Value cell;
      cell_at(i, cell);
      str += cell.to_string();
      str += ", ";
    }

    if (cell_num > 0) {
      Value cell;
      cell_at(cell_num - 1, cell);
      str += cell.to_string();
    }
    return str;
  }
};

/**
 * @brief 一行数据的元组
 * @ingroup Tuple
 * @details 直接就是获取表中的一条记录
 */
class RowTuple : public Tuple 
{
public:
  RowTuple() = default;
  virtual ~RowTuple()
  {
    for (FieldExpr *spec : speces_) {
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
    this->speces_.clear();
    this->speces_.reserve(fields->size());
    for (const FieldMeta &field : *fields) {
      speces_.push_back(new FieldExpr(table, &field));
    }
  }

  int cell_num() const override
  {
    return speces_.size();
  }

  RC cell_at(int index, Value &cell) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }

    FieldExpr *field_expr = speces_[index];
    const FieldMeta *field_meta = field_expr->field().meta();

    if (field_meta->type() == TEXTS) {
      std::string text_data;
      TextDataMeta *meta = (TextDataMeta *)(this->record_->data() + field_meta->offset());
      table_->get_text_record(meta, text_data);
      cell.set_text(text_data.c_str(), text_data.length());
    } else {
      cell.set_type(field_meta->type());
      cell.set_data(this->record_->data() + field_meta->offset(), field_meta->len());
    }
    if (field_meta->nullable()) {
      cell.set_null(*(bool *)(this->record_->data() + field_meta->offset() - 1));
    } else {
      cell.set_null(false);
    }
    return RC::SUCCESS;
  }

  RC find_cell(const TupleCellSpec &spec, Value &cell) const override
  {
    const char *table_name = spec.table_name();
    const char *field_name = spec.field_name();
    if (0 != strcmp(table_name, table_->name())) {
      return RC::NOTFOUND;
    }

    for (size_t i = 0; i < speces_.size(); ++i) {
      const FieldExpr *field_expr = speces_[i];
      const Field &field = field_expr->field();
      if (0 == strcmp(field_name, field.field_name())) {
        return cell_at(i, cell);
      }
    }
    return RC::NOTFOUND;
  }

#if 0
  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      LOG_WARN("invalid argument. index=%d", index);
      return RC::INVALID_ARGUMENT;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }
#endif

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
  std::vector<FieldExpr *> speces_;
};

/**
 * @brief 从一行数据中，选择部分字段组成的元组，也就是投影操作
 * @ingroup Tuple
 * @details 一般在select语句中使用。
 * 投影也可以是很复杂的操作，比如某些字段需要做类型转换、重命名、表达式运算、函数计算等。
 * 当前的实现是比较简单的，只是选择部分字段，不做任何其他操作。
 */
class ProjectTuple : public Tuple 
{
public:
  ProjectTuple(std::vector<std::unique_ptr<Expression>> &expressions) {
    expressions_.swap(expressions);
  }
  virtual ~ProjectTuple()
  {
    // for (TupleCellSpec *spec : speces_) {
    //   delete spec;
    // }
    // speces_.clear();
  }

  void set_tuple(Tuple *tuple)
  {
    this->tuple_ = tuple;
  }

  // void add_cell_spec(TupleCellSpec *spec)
  // {
  //   speces_.push_back(spec);
  // }
  int cell_num() const override
  {
    return expressions_.size();
  }

  RC cell_at(int index, Value &cell) const override
  {
    // if (index < 0 || index >= static_cast<int>(speces_.size())) {
    //   return RC::INTERNAL;
    // }
    // if (tuple_ == nullptr) {
    //   return RC::INTERNAL;
    // }

    // const TupleCellSpec *spec = speces_[index];
    // return tuple_->find_cell(*spec, cell);

    if (index < 0 || index >= static_cast<int>(expressions_.size())) {
      return RC::INTERNAL;
    }

    const Expression *expr = expressions_[index].get();
    return expr->get_value(*tuple_, cell);
  }

  RC find_cell(const TupleCellSpec &spec, Value &cell) const override
  {
    // return tuple_->find_cell(spec, cell);
    for (const std::unique_ptr<Expression> &expr : expressions_) {
      if (0 == strcmp(spec.alias(), expr->name().c_str())) {
        return expr->get_value(*tuple_, cell);
      }
    }
    return RC::NOTFOUND;
  }

#if 0
  RC cell_spec_at(int index, const TupleCellSpec *&spec) const override
  {
    if (index < 0 || index >= static_cast<int>(speces_.size())) {
      return RC::NOTFOUND;
    }
    spec = speces_[index];
    return RC::SUCCESS;
  }
#endif
private:
  std::vector<std::unique_ptr<Expression>> expressions_;
  Tuple *tuple_ = nullptr;
};

class ExpressionTuple : public Tuple 
{
public:
  ExpressionTuple(std::vector<std::unique_ptr<Expression>> &expressions)
    : expressions_(expressions)
  {
  }
  
  virtual ~ExpressionTuple()
  {
  }

  int cell_num() const override
  {
    return expressions_.size();
  }

  RC cell_at(int index, Value &cell) const override
  {
    if (index < 0 || index >= static_cast<int>(expressions_.size())) {
      return RC::INTERNAL;
    }

    const Expression *expr = expressions_[index].get();
    return expr->try_get_value(cell);
  }

  RC find_cell(const TupleCellSpec &spec, Value &cell) const override
  {
    for (const std::unique_ptr<Expression> &expr : expressions_) {
      if (0 == strcmp(spec.alias(), expr->name().c_str())) {
        return expr->try_get_value(cell);
      }
    }
    return RC::NOTFOUND;
  }


private:
  const std::vector<std::unique_ptr<Expression>> &expressions_;
};

/**
 * @brief 一些常量值组成的Tuple
 * @ingroup Tuple
 */
class ValueListTuple : public Tuple 
{
public:
  ValueListTuple() = default;
  virtual ~ValueListTuple() = default;

  void set_cells(const std::vector<Value> &cells)
  {
    cells_ = cells;
  }

  virtual int cell_num() const override
  {
    return static_cast<int>(cells_.size());
  }

  virtual RC cell_at(int index, Value &cell) const override
  {
    if (index < 0 || index >= cell_num()) {
      return RC::NOTFOUND;
    }

    cell = cells_[index];
    return RC::SUCCESS;
  }

  virtual RC find_cell(const TupleCellSpec &spec, Value &cell) const override
  {
    return RC::INTERNAL;
  }

private:
  std::vector<Value> cells_;
};

/**
 * @brief 将两个tuple合并为一个tuple
 * @ingroup Tuple
 * @details 在join算子中使用, 子查询时也使用该tuple
 */
class JoinedTuple : public Tuple 
{
public:
  JoinedTuple() = default;
  virtual ~JoinedTuple() = default;

  void set_left(Tuple *left)
  {
    left_ = left;
  }
  void set_right(Tuple *right)
  {
    right_ = right;
  }

  int cell_num() const override
  {
    return left_->cell_num() + right_->cell_num();
  }

  RC cell_at(int index, Value &value) const override
  {
    const int left_cell_num = left_->cell_num();
    if (index >= 0 && index < left_cell_num) {
      return left_->cell_at(index, value);
    }

    if (index >= left_cell_num && index < left_cell_num + right_->cell_num()) {
      return right_->cell_at(index - left_cell_num, value);
    }

    return RC::NOTFOUND;
  }

  RC find_cell(const TupleCellSpec &spec, Value &value) const override
  {
    RC rc = left_->find_cell(spec, value);
    if (rc == RC::SUCCESS || rc != RC::NOTFOUND) {
      return rc;
    }

    return right_->find_cell(spec, value);
  }

private:
  Tuple *left_ = nullptr;
  Tuple *right_ = nullptr;
};


class GroupTuple : public Tuple {
public:
  GroupTuple(std::vector<Field> &fields)
  {
    for (int i = 0; i < fields.size(); i++) {
      cells_.push_back(TupleCellSpec(fields[i].table_name(), fields[i].field_name()));
    }
  }
  virtual ~GroupTuple() = default;

  int cell_num() const override
  {
    return cells_.size();
  }

  RC cell_at(int index, Value &value) const override
  {
    const int cell_num = cells_.size();
    if (index >= 0 && index < cell_num) {
      value = lasts_[index];
      return RC::SUCCESS;
    }

    return RC::NOTFOUND;
  }

  RC find_cell(const TupleCellSpec &spec, Value &value) const override
  {
    const char *table_name = spec.table_name();
    const char *field_name = spec.field_name();

    for (size_t i = 0; i < cells_.size(); ++i) {
      if (0 != strcmp(table_name, cells_[i].table_name())) {
        continue;
      }
      if (0 == strcmp(field_name, cells_[i].field_name())) {
        if (count_ == 0) {
          value.set_null(true);
        } else {
          value = lasts_[i];
        }
        return RC::SUCCESS;
      }
    }
    LOG_INFO("not found find_cell");
    return RC::NOTFOUND;
  }

  void update_value(Tuple *tuple) 
  {
    Value temp;
    for (int i = 0; i < cells_.size(); i++) {
      RC rc = tuple->find_cell(cells_[i], temp);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot find from group tuples!!!");
      }
      if (count_ == 0) {
        if (temp.is_null()) {
          sums_.emplace_back(Value(0));
          counts_.emplace_back(Value(0));
        } else {
          sums_.emplace_back(temp);
          counts_.emplace_back(Value(1));
        }
        maxs_.emplace_back(temp);
        mins_.emplace_back(temp);
        lasts_.emplace_back(temp);
      } else {
        if (maxs_[i].is_null() || maxs_[i].compare(temp) < 0) {
          maxs_[i] = temp;
        }
        if (mins_[i].is_null() || mins_[i].compare(temp) > 0) {
          mins_[i] = temp;
        }
        if (!temp.is_null()) {
          if (temp.attr_type() == INTS) {
            sums_[i].set_int(sums_[i].get_int() + temp.get_int());
          } else {
            sums_[i].set_float(sums_[i].get_float() + temp.get_float());
          }
          counts_[i].set_int(counts_[i].get_int() + 1);
        }
        lasts_[i] = temp;
      }
    }
    count_ = count_ + 1;
  }

  void reset_value() {
    count_ = 0;
    counts_.clear();
    sums_.clear();
    maxs_.clear();
    mins_.clear();
    lasts_.clear();
  }

  RC find_cell_max(const TupleCellSpec &spec, Value &value) const
  {
    const char *table_name = spec.table_name();
    const char *field_name = spec.field_name();

    for (size_t i = 0; i < cells_.size(); ++i) {
      if (0 != strcmp(table_name, cells_[i].table_name())) {
        continue;
      }
      if (0 == strcmp(field_name, cells_[i].field_name())) {
        if (count_ == 0) {
          value.set_null(true);
        } else {
          value = maxs_[i];
        }
        return RC::SUCCESS;
      }
    }
    LOG_INFO("not found find_cell_max");
    return RC::NOTFOUND;
  }

  RC find_cell_min(const TupleCellSpec &spec, Value &value) const
  {
    const char *table_name = spec.table_name();
    const char *field_name = spec.field_name();

    for (size_t i = 0; i < cells_.size(); ++i) {
      if (0 != strcmp(table_name, cells_[i].table_name())) {
        continue;
      }
      if (0 == strcmp(field_name, cells_[i].field_name())) {
        if (count_ == 0) {
          value.set_null(true);
        } else {
          value = mins_[i];
        }
        return RC::SUCCESS;
      }
    }
    LOG_INFO("not found find_cell_min");
    return RC::NOTFOUND;
  }

  RC find_cell_sum(const TupleCellSpec &spec, Value &value) const
  {
    const char *table_name = spec.table_name();
    const char *field_name = spec.field_name();

    for (size_t i = 0; i < cells_.size(); ++i) {
      if (0 != strcmp(table_name, cells_[i].table_name())) {
        continue;
      }
      if (0 == strcmp(field_name, cells_[i].field_name())) {
        if (count_ == 0) {
          value.set_null(true);
        } else if (counts_[i].get_int() == 0) {
          value.set_null(true);
        } else {
          value = sums_[i];
        }
        return RC::SUCCESS;
      }
    }
    LOG_INFO("not found find_cell_sum");
    return RC::NOTFOUND;
  }
  // there is null !!!
  RC find_cell_count(const TupleCellSpec &spec, Value &value) const
  {
    const char *table_name = spec.table_name();
    const char *field_name = spec.field_name();

    for (size_t i = 0; i < cells_.size(); ++i) {
      if (0 != strcmp(table_name, cells_[i].table_name())) {
        continue;
      }
      if (0 == strcmp(field_name, cells_[i].field_name())) {
        if (count_ == 0) {
          value.set_int(0);
        } else {
          value.set_int(counts_[i].get_int());
        }
        return RC::SUCCESS;
      }
    }
    LOG_INFO("not found find_cell_count");
    return RC::NOTFOUND;
  }

  std::vector<TupleCellSpec> get_speces_()
  {
    return cells_;
  }

private:
  // A group of Tuple
  int count_;
  std::vector<Value> counts_;
  std::vector<Value> sums_;
  std::vector<Value> maxs_;
  std::vector<Value> mins_;
  std::vector<Value> lasts_;
  std::vector<TupleCellSpec> cells_;

  // std::vector<Tuple *> tuples_;
};

// Order Operator 使用， 将多表 Join 结果拍扁输出
// 一种简化实现，目前 OrderTuple 中只实现了对 Field 的索引
// 不能与 sub-query 和 group-by 兼容
class OrderTuple : public Tuple 
{
public:
  OrderTuple(std::vector<Field> &fields)
  {
    for (int i = 0; i < fields.size(); i++) {
      cells_.push_back(TupleCellSpec(fields[i].table_name(), fields[i].field_name()));
    }
  }
  virtual ~OrderTuple() = default;

  int cell_num() const override
  {
    return cells_.size();
  }

  RC cell_at(int index, Value &value) const override
  {
    const int cell_num = cells_.size();
    if (index >= 0 && index < cell_num) {
      value = values_[index];
      return RC::SUCCESS;
    }

    return RC::NOTFOUND;
  }

  RC find_cell(const TupleCellSpec &spec, Value &value) const override
  {
    const char *table_name = spec.table_name();
    const char *field_name = spec.field_name();

    for (size_t i = 0; i < cells_.size(); ++i) {
      if (0 != strcmp(table_name, cells_[i].table_name())) {
        continue;
      }
      if (0 == strcmp(field_name, cells_[i].field_name())) {
        value = values_[i];
        return RC::SUCCESS;
      }
    }
    LOG_INFO("Not found in OrderTuple !");
    return RC::NOTFOUND;
  }

  // Order Operator 用于放入values
  void set_values(std::vector<Value> &values)
  {
    values_.clear();
    values_.swap(values);
  }

  std::vector<TupleCellSpec> get_speces_()
  {
    return cells_;
  }

private:
  std::vector<TupleCellSpec> cells_;
  std::vector<Value>         values_;
};