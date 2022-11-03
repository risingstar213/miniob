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
// Created by Wangyunlai on 2022/6/6.
//

#include "sql/stmt/select_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/join_stmt.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/common/db.h"
#include "storage/common/table.h"
#include "storage/trx/trx.h"
#include "util/expression_helpers.h"

SelectStmt::~SelectStmt()
{
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }

  for (size_t i = 0; i < join_stmts_.size(); i++) {
    delete join_stmts_[i];
  }
  join_stmts_.clear();
}

static void wildcard_fields(Table *table, std::vector<Field> &field_metas, std::vector<Aggregation> &aggs)
{
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    field_metas.push_back(Field(table, table_meta.field(i)));
    aggs.push_back(AGG_NONE);
  }
}

RC SelectStmt::create(Db *db, Selects &select_sql, Stmt *&stmt, std::unordered_map<std::string, Table *> *context)
{
  LOG_INFO("SelectStmt::create");
  // if (select_sql.is_valid == false) {
  //   LOG_WARN("invalid argument. selection is invalid");
  //   return RC::INVALID_ARGUMENT;
  // }

  // check aggretion
  // bool isAgg = false;
  // for (int i = select_sql.attr_num - 1; i >= 0; i--) {
  //   LOG_INFO("agg_type: %d", select_sql.attributes[i].agg);
  //   if (select_sql.attributes[i].agg != AGG_NONE) {
  //     isAgg = true;
  //   }
  // }
  // if (isAgg) {
  //   for (int i = select_sql.attr_num - 1; i >= 0; i--) {
  //     if (select_sql.attributes[i].agg == AGG_NONE) {
  //       LOG_INFO("not supported: aggregation and normal attribute exsit simultaneously!");
  //       return RC::INVALID_ARGUMENT;
  //     }
  //   }
  // }

  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  // collect tables in `from` statement
  std::vector<Table *> tables;
  std::unordered_map<std::string, Table *> table_map;
  // *** reverse order
  for (int i = (int)select_sql.relation_num-1; i >= 0; i--) {
    const char *table_name = select_sql.relations[i];
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
    table_map.insert(std::pair<std::string, Table*>(table_name, table));
  }

  std::vector<JoinStmt *> join_stmts;
  for (int i = 0; i < select_sql.join_num; i++) {
    JoinStmt *join;
    RC rc = JoinStmt::create(db, &tables, &table_map, select_sql.join[i], join);
    if (rc != RC::SUCCESS) {
      LOG_WARN("cannot construct join stmt");
      return rc;
    }
    join_stmts.push_back(join);
  }
  
  // check if the columns ordered by are valid
  int order_num = select_sql.order_col_num;
  std::vector<OrderCol *> order_cols;
  std::vector<Field> order_fields;
  for (int i = 0; i < order_num; i++) {
    OrderCol* orderCol = &select_sql.order_col[i];
    RelAttr* relAttr = orderCol->attr;
    const char *table_name = relAttr->relation_name;
    const char *field_name = relAttr->attribute_name;
    Table *table;
    if (table_name == nullptr) {
      table = tables[0];
    } else {
      auto iter = table_map.find(table_name);
      if (iter == table_map.end()) {
        LOG_WARN("===order check: no such table in from list: %s", table_name);
        return RC::SCHEMA_FIELD_MISSING;
      }
      table = iter->second;
    }
    const FieldMeta *field_meta = table->table_meta().field(field_name);
    if (nullptr == field_meta) {
      LOG_WARN("===order check: no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    Field field(table, field_meta);
    order_fields.push_back(field);
    order_cols.push_back(orderCol);
  }
  
  // collect query fields in `select` statement
  // std::vector<Field> query_fields;
  // std::vector<Aggregation> aggregations;
  // for (size_t i = 0; i < select_sql.attr_num; i++) {
  //   const RelAttr &relation_attr = select_sql.attributes[i];
  //   aggregations.push_back(select_sql.attributes[i].agg);
  //   // STAR
  //   if (common::is_blank(relation_attr.relation_name) && 0 == strcmp(relation_attr.attribute_name, "*")) {
  //     if (select_sql.attributes[i].agg == AGG_NONE) {
  //       for (Table *table : tables) {
  //         wildcard_fields(table, query_fields, aggregations);
  //       }
  //     } else if (select_sql.attributes[i].agg == AGG_COUNT) {
  //       LOG_INFO("count(*)");
  //       Table *table = tables[0];
  //       const TableMeta &table_meta = table->table_meta();
  //       query_fields.push_back(Field(table, table->table_meta().field(Trx::trx_field_name())));
  //     } else {
  //       LOG_WARN("invalid argument. aggrevation * type error");
  //       return RC::INVALID_ARGUMENT;
  //     }

  //   } else if (!common::is_blank(relation_attr.relation_name)) { // TODO
      // const char *table_name = relation_attr.relation_name;
      // const char *field_name = relation_attr.attribute_name;

  //     if (0 == strcmp(table_name, "*")) {
  //       if (0 != strcmp(field_name, "*")) {
  //         LOG_WARN("invalid field name while table is *. attr=%s", field_name);
  //         return RC::SCHEMA_FIELD_MISSING;
  //       }
  //       for (Table *table : tables) {
  //         wildcard_fields(table, query_fields, aggregations);
  //       }
  //     } else {
        // auto iter = table_map.find(table_name);
        // if (iter == table_map.end()) {
        //   LOG_WARN("no such table in from list: %s", table_name);
        //   return RC::SCHEMA_FIELD_MISSING;
        // }

        // Table *table = iter->second;
        // if (0 == strcmp(field_name, "*")) {
        //   wildcard_fields(table, query_fields, aggregations);
        // } else {
        //   const FieldMeta *field_meta = table->table_meta().field(field_name);
        //   if (nullptr == field_meta) {
        //     LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), field_name);
        //     return RC::SCHEMA_FIELD_MISSING;
        //    }

  //       query_fields.push_back(Field(table, field_meta));
  //       }
  //     }
  //   } else {
  //     if (tables.size() != 1) {
  //       LOG_WARN("invalid. I do not know the attr's table. attr=%s", relation_attr.attribute_name);
  //       return RC::SCHEMA_FIELD_MISSING;
  //     }

  //     Table *table = tables[0];
  //     const FieldMeta *field_meta = table->table_meta().field(relation_attr.attribute_name);
  //     if (nullptr == field_meta) {
  //       LOG_WARN("no such field. field=%s.%s.%s", db->name(), table->name(), relation_attr.attribute_name);
  //       return RC::SCHEMA_FIELD_MISSING;
  //     }

  //     query_fields.push_back(Field(table, field_meta));
  //   }
  // }

  // LOG_INFO("got %d tables in from stmt and %d fields in query stmt", tables.size(), query_fields.size());
  int attr_num = 0;
  int aggregation_num = 0;
  for (int i = 0; i < select_sql.select_expr_num; i++) {
    RC rc = check_select_expression_valid(&select_sql.select_expr[i], 0, &tables, &table_map);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    attr_num += select_sql.select_expr[i].attr_num;
    aggregation_num += select_sql.select_expr[i].aggregation_num;
  }
  if (aggregation_num != attr_num && aggregation_num != 0) {
    LOG_WARN("NOT MATCH aggregation_num %d, attr_num %d", aggregation_num, attr_num);
    return RC::INVALID_ARGUMENT;
  }

  std::vector<SelectExpr> expressions;
  for (int i = 0; i < select_sql.select_expr_num; i++) {
    append_select_expression_with_star(tables, &select_sql.select_expr[i], expressions);
  }

  Table *default_table = nullptr;
  if (tables.size() == 1) {
    default_table = tables[0];
  }

  // create filter statement in `where` statement
  FilterStmt *filter_stmt = nullptr;
  if (context != nullptr) {
    table_map.insert(context->begin(), context->end());
  }
  RC rc = FilterStmt::create(db, default_table, &table_map,
           select_sql.conditions, select_sql.condition_num, filter_stmt);
  if (rc != RC::SUCCESS) {
    LOG_WARN("cannot construct filter stmt");
    return rc;
  }

  // everything alright
  SelectStmt *select_stmt = new SelectStmt();
  select_stmt->tables_.swap(tables);
  // select_stmt->query_fields_.swap(query_fields);
  select_stmt->select_exprs_.swap(expressions);
  select_stmt->join_stmts_.swap(join_stmts);
  select_stmt->order_cols_.swap(order_cols);
  select_stmt->order_fields_.swap(order_fields);
  select_stmt->filter_stmt_ = filter_stmt;
  select_stmt->is_aggregations_ = aggregation_num == attr_num;
  // select_stmt->aggregations_.swap(aggregations);
  stmt = select_stmt;
  return RC::SUCCESS;
}
