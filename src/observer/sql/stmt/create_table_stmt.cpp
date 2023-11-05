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

#include <unordered_map>

#include "sql/stmt/create_table_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "event/sql_debug.h"
#include "sql/expr/expression.h"

RC CreateTableStmt::create(Db *db, const CreateTableSqlNode &create_table, Stmt *&stmt)
{
  SelectStmt* as_select_stmt = nullptr;
  std::deque<AttrInfoSqlNode> attr_infos = create_table.attr_infos;
  bool has_attr_defs = attr_infos.size() > 0;
  if (create_table.as_select != nullptr) {
    Stmt* as_stmt = nullptr;
    std::unordered_map<std::string, Table *> empty_table_map;
    RC rc = SelectStmt::create(db, *create_table.as_select, empty_table_map, as_stmt, true);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    as_select_stmt = static_cast<SelectStmt *>(as_stmt);

    auto &exprs = as_select_stmt->query_exprs();
    auto &alias = as_select_stmt->query_alias();

    if (has_attr_defs && exprs.size() != attr_infos.size()) {
      return RC::INVALID_ARGUMENT;
    }

    for (int i = 0; i < exprs.size(); i++) {
      AttrType type = exprs[i]->value_type();
      if (attr_infos[i].type_unsolved) {
        return RC::INVALID_ARGUMENT;
      } else if (has_attr_defs && type == attr_infos[i].type) {
        continue;
      } else if (has_attr_defs) {
        return RC::INVALID_ARGUMENT;
      }

      size_t length = 4;
      if (type == DATES) {
        length = 12;
      } else if (type == TEXTS) {
        length = 50;
      }
      attr_infos.emplace_back(AttrInfoSqlNode{
        type,
        alias[i],
        length,
        false,
        -1,
        false
      });
    }
  }
  
  stmt = new CreateTableStmt(create_table.relation_name, attr_infos, as_select_stmt);
  sql_debug("create table statement: table name %s", create_table.relation_name.c_str());
  return RC::SUCCESS;
}
