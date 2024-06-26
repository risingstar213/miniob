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
// Created by Wangyunlai on 2023/6/13.
//

#pragma once

#include <string>
#include <vector>

#include "sql/stmt/stmt.h"

class Db;
class SelectStmt;

/**
 * @brief 表示创建表的语句
 * @ingroup Statement
 * @details 虽然解析成了stmt，但是与原始的SQL解析后的数据也差不多
 */
class CreateTableStmt : public Stmt
{
public:
  CreateTableStmt(const std::string &table_name, const std::deque<AttrInfoSqlNode> &attr_infos, SelectStmt *stmt)
        : table_name_(table_name), select_stmt_(std::unique_ptr<SelectStmt>(stmt))
  {
    for (size_t i = 0; i < attr_infos.size(); i++) {
      attr_infos_.push_back(attr_infos[i]);
      if (attr_infos[i].null_unsolved == 0) {
        attr_infos_[i].nullable = false;
      } else if (attr_infos[i].null_unsolved == 1) {
        attr_infos_[i].nullable = true;
      } else if (i == 0) {
        attr_infos_[i].nullable = false;
      } else {
        attr_infos_[i].nullable = true;
      }
    }
  }
  virtual ~CreateTableStmt() = default;

  StmtType type() const override { return StmtType::CREATE_TABLE; }

  const std::string &table_name() const { return table_name_; }
  const std::vector<AttrInfoSqlNode> &attr_infos() const { return attr_infos_; }

  std::unique_ptr<SelectStmt> &select_stmt() { return select_stmt_; }

  static RC create(Db *db, const CreateTableSqlNode &create_table, Stmt *&stmt);

private:
  std::string table_name_;
  std::vector<AttrInfoSqlNode> attr_infos_;
  std::unique_ptr<SelectStmt> select_stmt_ = nullptr;
};