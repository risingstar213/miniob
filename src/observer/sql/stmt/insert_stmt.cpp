/* Copyright (c) 2021OceanBase and/or its affiliates. All rights reserved.
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

#include "sql/stmt/insert_stmt.h"
#include "common/log/log.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

InsertStmt::InsertStmt(Table *table,  std::vector<Value> &values)
    : table_(table)
{
  values_.swap(values);
}

RC InsertStmt::create(Db *db, const InsertSqlNode &inserts, Stmt *&stmt)
{
  const char *table_name = inserts.relation_name.c_str();
  if (nullptr == db || nullptr == table_name || inserts.rows[0].values.empty()) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, value_num=%d",
        db, table_name, static_cast<int>(inserts.rows[0].values.size()));
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  // check the fields number
  auto &values = inserts.rows[0].values;
  const int value_num = static_cast<int>(inserts.rows[0].values.size());
  for (int i = 0; i < value_num; i++) {
    if (!values[i].check_valid()) {
      LOG_WARN("not valid data: %s", values[i].to_string());
      return RC::VARIABLE_NOT_VALID;
    }
  }
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num() - table_meta.sys_field_num();
  if (field_num != value_num) {
    LOG_WARN("schema mismatch. value num=%d, field num in schema=%d", value_num, field_num);
    return RC::SCHEMA_FIELD_MISSING;
  }

  // check fields type
  std::vector<Value> new_values;
  const int sys_field_num = table_meta.sys_field_num();
  for (int i = 0; i < value_num; i++) {
    new_values.push_back(values[i]);
    const FieldMeta *field_meta = table_meta.field(i + sys_field_num);

    if (values[i].is_null() && !field_meta->nullable()) {
      LOG_WARN("cannot insert null to not null columns!");
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }

    const AttrType field_type = field_meta->type();
    const AttrType value_type = values[i].attr_type();

    bool can_compare = true;
    bool left_cast = field_type == CHARS || field_type == INTS || field_type == FLOATS;
    bool right_cast = value_type == CHARS || value_type == INTS || value_type == FLOATS;
    if (left_cast && right_cast) {
      can_compare = true;
    } else if (field_type == value_type) {
      can_compare = true;
    } else if (values[i].is_null()) {
      can_compare = true;
    } else {
      can_compare = false;
    }
    if (!can_compare) {  // TODO try to convert the value type to field type
      LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d",
          table_name, field_meta->name(), field_type, value_type);
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }

    if (field_type != value_type) {
      switch (field_type) {
        case INTS:
          new_values[i].set_int(values[i].get_int());
          break;
        case FLOATS:
          new_values[i].set_float(values[i].get_float());
          break;
        case CHARS:
          new_values[i].set_string(values[i].get_string().c_str(), values[i].get_string().length());
          break;
        case DATES:
          new_values[i].set_date("2023-01-01");
        default:
          break;
      }
      if (values[i].is_null()) {
        new_values[i].set_null(true);
      }
    }
  }

  // everything alright
  stmt = new InsertStmt(table, new_values);
  return RC::SUCCESS;
}
