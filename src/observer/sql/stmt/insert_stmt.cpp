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

#include "sql/stmt/insert_stmt.h"
#include "util/cast.h"
#include "common/log/log.h"
#include "storage/common/db.h"
#include "storage/common/table.h"
#include "util/date.h"
#include "util/util.h"

InsertStmt::InsertStmt(Table *table, const Rows *rows, int value_amount, int row_amount)
  : table_ (table), rows_(rows), value_amount_(value_amount), row_amount_(row_amount)
{}

RC InsertStmt::create(Db *db, Inserts &inserts, Stmt *&stmt)
{
  const char *table_name = inserts.relation_name;
  if (nullptr == db || nullptr == table_name || inserts.row_num <= 0) {
    LOG_WARN("invalid argument. db=%p, table_name=%p, row_num=%d", 
             db, table_name, inserts.row_num);
    return RC::INVALID_ARGUMENT;
  }

  // t_log -> t_clog
  if (strcmp(table_name, "t_log") == 0) {
    table_name = "t_clog";
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num() - table_meta.sys_field_num();

  Rows *rows = inserts.rows;

  int row_num = inserts.row_num;
  for (int j = 0; j < row_num; j++) {
    // check the fields number
    LOG_INFO("CHECK FIELD ROW %d", j);
    Value *values = inserts.rows[j].values;

    const int value_num = inserts.rows[j].value_num;
    if (field_num != value_num) {
      LOG_WARN("schema mismatch. value num=%d, field num in schema=%d", value_num, field_num);
      return RC::SCHEMA_FIELD_MISSING;
    }

    // check fields type && valid
    const int sys_field_num = table_meta.sys_field_num();
    for (int i = 0; i < value_num; i++) {
      LOG_INFO("CHECK FIELD VALUE %d", i);
      const FieldMeta *field_meta = table_meta.field(i + sys_field_num);
      const AttrType field_type = field_meta->type();
      if (values[i].type == INTS && is_null((char *)values[i].data)) { // check if null is permitted
        if (field_meta->nullable() == false) {
          LOG_WARN("NULL is not permitted");
          return RC::INVALID_ARGUMENT;
        } else {
          values[i].type = field_type;
          LOG_INFO("%s", values);
          continue;
        }
      } 
      CastUnit::cast_to(values[i], field_type);
      const AttrType value_type = values[i].type;
      if (values[i].type == DATES) {
        Date *d = (Date *)values[i].data;
        if (!d->is_valid()) {
          LOG_WARN("The date %s is not valid", d->toString().c_str());
          return RC::SQL_SYNTAX;
        }
      }
      if (value_type != field_type) { // TODO try to convert the value type to field type
        LOG_WARN("field type mismatch. table=%s, field=%s, field type=%d, value_type=%d", 
                table_name, field_meta->name(), field_type, value_type);
        return RC::SCHEMA_FIELD_TYPE_MISMATCH;
      }
    }
  }

  // everything alright
  stmt = new InsertStmt(table, rows, inserts.rows[0].value_num, row_num);
  return RC::SUCCESS;
}
