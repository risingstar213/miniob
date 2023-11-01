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
// Created by Wangyunlai on 2023/4/25.
//

#pragma once

#include <string>

#include "sql/stmt/stmt.h"

struct CreateIndexSqlNode;
class Table;
class FieldMeta;

/**
 * @brief 创建索引的语句
 * @ingroup Statement
 */
class CreateIndexStmt : public Stmt
{
public:
  CreateIndexStmt(Table *table, std::vector<const FieldMeta *> &field_metas, const std::string &index_name, const int is_unique)
        : table_(table),
          index_name_(index_name),
          is_unique_(is_unique)
  {
    field_metas_.swap(field_metas);
  }

  virtual ~CreateIndexStmt() = default;

  StmtType type() const override { return StmtType::CREATE_INDEX; }

  Table *table() const { return table_; }
  const std::vector<const FieldMeta *> &field_metas() const { return field_metas_; }
  const std::string &index_name() const { return index_name_; }
  const bool is_unique() const { return is_unique_; }

public:
  static RC create(Db *db, const CreateIndexSqlNode &create_index, Stmt *&stmt);

private:
  Table *table_ = nullptr;
  std::vector<const FieldMeta *>field_metas_;
  std::string index_name_;
  bool is_unique_;
};
