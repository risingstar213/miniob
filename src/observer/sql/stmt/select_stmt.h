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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <vector>
#include <memory>
#include <unordered_map>

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "storage/field/field.h"

class FieldMeta;
class FilterStmt;
class Db;
class Table;

/**
 * @brief 表示select语句
 * @ingroup Statement
 */
class SelectStmt : public Stmt 
{
public:
  SelectStmt() = default;
  ~SelectStmt() override;

  StmtType type() const override
  {
    return StmtType::SELECT;
  }

public:
  static RC create(Db *db, SelectSqlNode &select_sql, std::unordered_map<std::string, Table *> &ctx_tables_map, Stmt *&stmt, bool create_table = false);

public:
  const std::vector<Table *> &tables() const
  {
    return tables_;
  }
  const std::vector<std::string>  &table_alias() const
  {
    return table_alias_;
  }
  const std::vector<Expression *> &query_exprs() const
  {
    return query_exprs_;
  }
  const std::vector<std::string> &query_alias() const
  {
    return query_alias_;
  }
  FilterStmt *filter_stmt() const
  {
    return filter_stmt_;
  }
  const std::vector<FilterStmt *> &join_filters() const
  {
    return join_filters_;
  }

  std::vector<Field> &order_fields() 
  {
    return order_fields_;
  }

  std::vector<Field> &group_fields()
  {
    return group_fields_;
  }

  FilterStmt * having_filter_stmt()
  {
    return having_filter_stmt_;
  }

  std::vector<uint8_t> &order_ascs()
  {
    return order_ascs_;
  }

  const bool has_aggregation() const
  {
    return has_aggregation_;
  }

private:
  // std::vector<Field> query_fields_;
  std::vector<Expression *> query_exprs_;
  std::vector<std::string>  query_alias_;
  std::vector<Table *>      tables_;
  std::vector<std::string>  table_alias_;
  std::vector<FilterStmt *> join_filters_;
  std::vector<Field>        group_fields_;
  FilterStmt *having_filter_stmt_ = nullptr;
  std::vector<Field>        order_fields_;
  std::vector<uint8_t>      order_ascs_;
  bool has_aggregation_;
  FilterStmt *filter_stmt_ = nullptr;
};
