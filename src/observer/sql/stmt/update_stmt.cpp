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
// Created by Wangyunlai on 2022/5/22.
//

#include "sql/stmt/update_stmt.h"
#include "common/log/log.h"
#include "storage/common/db.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/common/table.h"

UpdateStmt::UpdateStmt(Table *table, const char * field_name, Value *values, int value_amount, FilterStmt *filter_stmt)
    : table_(table), field_name_(field_name), values_(values), value_amount_(value_amount), filter_stmt_(filter_stmt)
{}

RC UpdateStmt::create(Db *db, Updates &update, Stmt *&stmt)
{
  // TODO
  const char *table_name = update.relation_name;
  const char *column_name = update.attribute_name;
  if (nullptr == db || nullptr == table_name || nullptr == column_name) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, column_name=%p", db, table_name, column_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  // check whether the column exists
  const FieldMeta *field_meta = table->table_meta().field(column_name);
  if (nullptr == field_meta) {
    LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), column_name);
    return RC::SCHEMA_FIELD_MISSING;
  }

  // check whether the type of the value is correct
  const AttrType field_type = field_meta->type();
  const AttrType value_type = update.value.type;
  if (field_type != value_type) {  // TODO try to convert the value type to field type
    LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d",
        table_name,
        field_meta->name(),
        field_type,
        value_type);
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, table, nullptr, update.conditions, update.condition_num, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }

  // everything alright
  stmt = new UpdateStmt(table, column_name, (Value *)&update.value, 1, filter_stmt);
  return RC::SUCCESS;
}
