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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <vector>

#include "rc.h"
#include "sql/stmt/stmt.h"
#include "storage/common/field.h"

class FieldMeta;
class FilterStmt;
class JoinStmt;
class Db;
class Table;

class SelectStmt : public Stmt
{
public:

  SelectStmt() = default;
  ~SelectStmt() override;

  StmtType type() const override { return StmtType::SELECT; }
public:
  static RC create(Db *db, Selects &select_sql, Stmt *&stmt);

public:
  const std::vector<Table *> &tables() const { return tables_; }
  // const std::vector<Field> &query_fields() const { return query_fields_; }
  // const std::vector<Aggregation> &aggregations() const { return aggregations_; }
  std::vector<SelectExpr> &select_exprs() { return select_exprs_; }
  FilterStmt *filter_stmt() const { return filter_stmt_; }
  std::vector<JoinStmt *> join_stmts() { return join_stmts_; }
  bool is_aggregations() { return is_aggregations_; }

private:
  // std::vector<Field> query_fields_;
  // std::vector<Aggregation> aggregations_;
  bool is_aggregations_;
  std::vector<Table *> tables_;
  std::vector<SelectExpr> select_exprs_;
  std::vector<JoinStmt *> join_stmts_;
  FilterStmt *filter_stmt_ = nullptr;
};

