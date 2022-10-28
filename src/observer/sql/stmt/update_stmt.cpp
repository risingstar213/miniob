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

#include "common/log/log.h"
#include "storage/common/db.h"
#include "storage/common/table.h"
#include "sql/stmt/update_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/select_stmt.h"

UpdateStmt::UpdateStmt(Table *table, std::vector<char *> field_name, std::vector<UpdateValueStmt> update_values, FilterStmt *filter_stmt)
    : table_(table), field_name_(field_name), update_values_(update_values), filter_stmt_(filter_stmt)
{}

UpdateStmt::~UpdateStmt()
{
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }

  for (size_t i = 0; i < update_values_.size(); i++) {
    if (update_values_[i].is_select) {
      delete update_values_[i].value.select;
    }
  }
  update_values_.clear();
}

RC UpdateStmt::create(Db *db, Updates &update, Stmt *&stmt)
{
  LOG_INFO("UpdateStmt");
  const char *table_name = update.relation_name;
  char **column_name = update.attribute_name;
  if (nullptr == db || nullptr == table_name) {
    LOG_WARN("invalid argument. db=%p, table_name=%p", db, table_name);
    return RC::INVALID_ARGUMENT;
  }

  // check whether the table exists
  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  
  std::vector<char *> field_name;
  std::vector<UpdateValueStmt> update_values;
  for (int i = 0; i < update.attribute_num; i++) {
    // check whether the column exists
    const FieldMeta *field_meta = table->table_meta().field(column_name[i]);
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), column_name[i]);
      return RC::SCHEMA_FIELD_MISSING;
    }

    UpdateValueStmt update_value;
    update_value.is_select = update.update_value[i].is_select;

    if (!update.update_value[i].is_select) {
      // check whether the type of the value is correct
      const AttrType field_type = field_meta->type();
      AttrType value_type = update.update_value[i].value.value.type;
      update_value.value.value = update.update_value[i].value.value;
    } else {
      // select
      Stmt *stmt;
      RC rc = SelectStmt::create(db, update.update_value[i].value.select, stmt);
      update_value.value.select = static_cast<SelectStmt *>(stmt);
      if (rc != RC::SUCCESS) {
        LOG_WARN("cannot create sub select stmt for update");
        return rc;
      }
    }
    field_name.push_back(column_name[i]);
    update_values.push_back(update_value);
  }

  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, table, nullptr, update.conditions, update.condition_num, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create filter statement. rc=%d:%s", rc, strrc(rc));
    return rc;
  }

  // everything alright
  stmt = new UpdateStmt(table, field_name, update_values, filter_stmt);
  return RC::SUCCESS;
}
