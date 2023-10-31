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
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/update_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/parser/parse_defs.h"
#include "storage/db/db.h"
#include "sql/utils/expression_helpers.h"

// UpdateStmt::UpdateStmt(Table *table)
// {}

RC UpdateStmt::create(Db *db, UpdateSqlNode &update, Stmt *&stmt)
{
  // TODO
  std::string table_name = update.relation_name;
  if (nullptr == db || table_name.empty()) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", db, table_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name.c_str());
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  std::vector<std::string> update_names;
  std::vector<Expression *> update_exprs;
  std::vector<const FieldMeta *> update_fields;

  for (size_t i = 0; i < update.attr_values.size(); i++) {
    // check whether the column exists
    const FieldMeta *field_meta = table->table_meta().field(update.attr_values[i].attr.attribute_name.c_str());
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), update.attr_values[i].attr.attribute_name.c_str());
      return RC::SCHEMA_FIELD_MISSING;
    }

    Expression *expr = nullptr;
    bool is_null = false;
    if (!update.attr_values[i].is_select) {
      // check whether the type of the value is correct
      expr = new ValueExpr(update.attr_values[i].value);
      is_null = update.attr_values[i].value.is_null();
    } else {
      // select
      Stmt *stmt;
      std::unordered_map<std::string, Table *> empty;
      RC rc = SelectStmt::create(db, update.attr_values[i].select_value, empty, stmt);
      // update_value.value.select = static_cast<SelectStmt *>(stmt);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot create sub select stmt for update");
        return rc;
      }
      expr = new SQueryExpr(static_cast<SelectStmt *>(stmt));
    }

    if (is_null && !field_meta->nullable()) {
      LOG_WARN("update null is not valid!");
      return RC::INTERNAL;
    } else if (expr->value_type() != field_meta->type() && !is_null) {
      LOG_WARN("update type is not valid!");
      return RC::INTERNAL;
    }
    update_names.push_back(update.attr_values[i].attr.attribute_name.c_str());
    update_fields.push_back(field_meta);
    update_exprs.push_back(expr);
  }

  std::unordered_map<std::string, Table *> table_map;
  table_map.insert(std::pair<std::string, Table *>(std::string(table_name), table));

  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, table, &table_map, update.conditions, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }

  UpdateStmt *update_stmt = new UpdateStmt();
  update_stmt->table_ = table;
  update_stmt->update_names_.swap(update_names);
  update_stmt->update_exprs_.swap(update_exprs);
  update_stmt->update_fields_.swap(update_fields);
  update_stmt->filter_stmt_ = filter_stmt;
  stmt = update_stmt;
  return RC::SUCCESS;
}
