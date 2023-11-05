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
// Created by Wangyunlai on 2022/6/6.
//

#include "sql/stmt/select_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

#include "sql/utils/expression_helpers.h"

SelectStmt::~SelectStmt()
{
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }
}

static void wildcard_fields(Table *table, std::vector<Field> &field_metas)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    field_metas.push_back(Field(table, table_meta.field(i)));
  }
}

RC SelectStmt::create(Db *db, SelectSqlNode &select_sql, std::unordered_map<std::string, Table *> &ctx_tables_map, Stmt *&stmt, bool create_table)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  // collect tables in `from` statement
  std::vector<Table *> tables;
  std::vector<std::string> table_alias;
  std::unordered_map<std::string, Table *> table_map;
  std::unordered_map<std::string, std::string> alias_map;
  for (size_t i = 0; i < select_sql.relations.size(); i++) {
    const char *table_name = select_sql.relations[i].relation.c_str();
    if (nullptr == table_name) {
      LOG_WARN("invalid argument. relation name is null. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name);
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    std::string alias;
    if (select_sql.relations[i].alias.empty()) {
      alias = select_sql.relations[i].relation;
    } else {
      alias = select_sql.relations[i].alias;
    }
    if (table_map.count(alias) > 0) {
      LOG_WARN("duplicate alias !!!!");
      return RC::INVALID_ARGUMENT;
    }

    tables.push_back(table);
    table_alias.push_back(alias);
    table_map.insert(std::pair<std::string, Table *>(alias, table));
    alias_map.insert(std::pair<std::string, std::string>(table->name(), alias));
  }

  // join
  std::vector<FilterStmt *> join_filters;

  for (size_t i = 0; i < select_sql.joins.size(); i++) {
    LOG_INFO("join %d in select stmt", i);
    const char *table_name = select_sql.joins[i].relation.c_str();
    if (nullptr == table_name) {
      LOG_WARN("invalid argument. relation name is null. index=%d", i);
      return RC::INVALID_ARGUMENT;
    }

    Table *table = db->find_table(table_name);
    if (nullptr == table) {
      LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
      return RC::SCHEMA_TABLE_NOT_EXIST;
    }

    tables.push_back(table);
    table_alias.push_back(table_name);
    table_map.insert(std::pair<std::string, Table *>(table_name, table));
    alias_map.insert(std::pair<std::string, std::string>(table_name, table_name));

    FilterStmt *join_filter_stmt = nullptr;
    RC rc = FilterStmt::create(db,
        tables[0],
        table_alias[0],
        &table_map,
        select_sql.joins[i].on_coditions,
        false,
        join_filter_stmt);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot construct filter stmt");
      return rc;
    }
    join_filters.push_back(join_filter_stmt);
  }

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }

  // group fields
  std::vector<Field> group_fields;
  FilterStmt *having_filter_stmt = nullptr;
  for (int i = 0; i < select_sql.group_by.by_attrs.size(); i++) {
    std::string table_name = select_sql.group_by.by_attrs[i].relation_name;
    std::string field_name = select_sql.group_by.by_attrs[i].attribute_name;
    Table *table;
    if (table_name.empty()) {
      table = default_table;
      table_name = table_alias[0];
    } else {
      auto iter = table_map.find(table_name);
      if (iter == table_map.end()) {
        LOG_WARN("===order check: no such table in from list: %s", table_name);
        return RC::SCHEMA_FIELD_MISSING;
      }
      table = iter->second;
    }

    const FieldMeta *field_meta = table->table_meta().field(field_name.c_str());
    if (nullptr == field_meta) {
      LOG_WARN("===order check: no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    Field field(table, field_meta);
    field.set_table_alias(table_name);
    group_fields.push_back(field);
  }
  if (select_sql.group_by.having_conditions.size() > 0) {
    RC rc = FilterStmt::create(db,
      default_table,
      table_alias[0],
      &table_map,
      select_sql.group_by.having_conditions,
      false,
      having_filter_stmt);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot construct filter stmt");
      return rc;
    }
  }

  int attr_num = 0;
  int aggregation_num = 0;
  for (size_t i = 0; i < select_sql.select_exprs.size(); i++) {
    RC rc = check_select_expression_valid(select_sql.select_exprs[i], 0, tables, table_alias[0], table_map, &group_fields);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    attr_num += select_sql.select_exprs[i].attr_num;
    aggregation_num += select_sql.select_exprs[i].aggregation_num;
  }
  if (aggregation_num != attr_num && aggregation_num != 0) {
    LOG_WARN("NOT MATCH aggregation_num %d, attr_num %d", aggregation_num, attr_num);
    return RC::INVALID_ARGUMENT;
  }

  std::vector<ExprSqlNode> expressions;
  for (size_t i = 0; i < select_sql.select_exprs.size(); i++) {
    append_select_expression_with_star(tables, table_alias, table_map, select_sql.select_exprs[i], expressions);
  }

  std::vector<Expression *> query_exprs;
  std::vector<std::string>  query_alias;
  std::vector<Field *>      query_fields;
  bool multi_tables = (tables.size() > 1) && !create_table;
  for (size_t i = 0; i < expressions.size(); i++) {
    query_exprs.push_back(generate_expression(expressions[i]));
    query_alias.push_back(generate_alias(multi_tables, expressions[i], alias_map));
  }

  LOG_INFO("got %d tables in from stmt and %d fields in query stmt", tables.size(), expressions.size());

  // order fields
  std::vector<Field> order_fields;
  std::vector<uint8_t> order_ascs;
  for (int i = 0; i < select_sql.order_bys.size(); i++) {
    std::string table_name = select_sql.order_bys[i].by_attr->relation_name;
    std::string field_name = select_sql.order_bys[i].by_attr->attribute_name;
    Table *table;
    if (table_name.empty()) {
      table = default_table;
      table_name = table_alias[0];
    } else {
      auto iter = table_map.find(table_name);
      if (iter == table_map.end()) {
        LOG_WARN("===order check: no such table in from list: %s", table_name);
        return RC::SCHEMA_FIELD_MISSING;
      }
      table = iter->second;
    }

    const FieldMeta *field_meta = table->table_meta().field(field_name.c_str());
    if (nullptr == field_meta) {
      LOG_WARN("===order check: no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    Field field(table, field_meta);
    field.set_table_alias(table_name);
    order_fields.push_back(field);
    order_ascs.push_back(select_sql.order_bys[i].is_asc);
  }

  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;

  // process ctx
  table_map.insert(ctx_tables_map.begin(), ctx_tables_map.end());

  RC rc = FilterStmt::create(db,
      default_table,
      table_alias[0],
      &table_map,
      select_sql.conditions,
      select_sql.condtion_is_or,
      filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();
  // TODO add expression copy
  select_stmt->tables_.swap(tables);
  select_stmt->table_alias_.swap(table_alias);
  select_stmt->join_filters_.swap(join_filters);
  select_stmt->query_exprs_.swap(query_exprs);
  select_stmt->query_alias_.swap(query_alias);
  select_stmt->filter_stmt_ = filter_stmt;
  select_stmt->has_aggregation_ = (aggregation_num > 0);
  select_stmt->group_fields_.swap(group_fields);
  select_stmt->having_filter_stmt_ = having_filter_stmt;
  select_stmt->order_fields_.swap(order_fields);
  select_stmt->order_ascs_.swap(order_ascs);
  stmt = select_stmt;
  return RC::SUCCESS;
}
