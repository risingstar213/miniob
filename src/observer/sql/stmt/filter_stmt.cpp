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

#include <deque>

#include "common/rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/filter_stmt.h"
#include "storage/db/db.h"
#include "storage/table/table.h"

#include "sql/utils/expression_helpers.h"

FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    std::deque<ConditionSqlNode> &condition_sqls, FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_sqls.size(); i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, condition_sqls[i], filter_unit);
    if (rc != RC::SUCCESS) {
      delete tmp_stmt;
      LOG_WARN("failed to create filter unit. condition index=%d", i);
      return rc;
    }
    tmp_stmt->filter_units_.push_back(filter_unit);
  }

  stmt = tmp_stmt;
  return rc;
}

RC get_table_and_field(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    const RelAttrSqlNode &attr, Table *&table, const FieldMeta *&field)
{
  if (common::is_blank(attr.relation_name.c_str())) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(attr.relation_name);
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(attr.relation_name.c_str());
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", attr.relation_name.c_str());
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name.c_str());
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), attr.attribute_name.c_str());
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
    ConditionSqlNode &condition, FilterUnit *&filter_unit)
{
  RC rc = RC::SUCCESS;

  if (condition.left_is_subquery || condition.right_is_subquery) {
    LOG_WARN("UNIMPLENMENT");
    rc = RC::UNIMPLENMENT;
    return rc;
  }

  CompOp comp = condition.op;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  filter_unit = new FilterUnit;

  std::vector<Table *> table;
  table.push_back(default_table);

  AttrType left_type = UNDEFINED;
  AttrType right_type = UNDEFINED;

  Expression* left = nullptr,* right = nullptr;
  
  if (condition.left_is_subquery ) {

  } else if (condition.left_expr != nullptr) {
    rc = check_select_expression_valid(*condition.left_expr, 0, table, *tables);
    left = std::move(generate_expression(*condition.left_expr));
    left_type = condition.left_expr->attrType;
  } else {
    left_type = UNDEFINED;
  }

  if (condition.right_is_subquery ) {

  } else if (condition.right_expr != nullptr) {
    rc = check_select_expression_valid(*condition.right_expr, 0, table, *tables);
    right = generate_expression(*condition.right_expr);
    right_type = condition.right_expr->attrType;
  } else {
    right_type = UNDEFINED;
  }

  bool can_compare = true;
  bool left_cast = left_type == CHARS || left_type == INTS || left_type == FLOATS;
  bool right_cast = right_type == CHARS || right_type == INTS || right_type == FLOATS;
  if (left_cast && right_cast) {
    can_compare = true;
  } else if (left_type == right_type) {
    can_compare = true;
  } else if (left_type == UNDEFINED) { // EXISTS
    can_compare = true;
  // } else if (left->is_null() || right->is_null()) {
  //   can_compare = true;
  } else {
    can_compare = false;
  }
  // 检查两个类型是否能够比较
  if (!can_compare) {
    LOG_WARN("cannot compare left %d right %d", left_type, right_type);
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  // if (condition.left_is_attr) {
  //   Table *table = nullptr;
  //   const FieldMeta *field = nullptr;
  //   rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);
  //   if (rc != RC::SUCCESS) {
  //     LOG_WARN("cannot find attr");
  //     return rc;
  //   }
  //   FilterObj filter_obj;
  //   filter_obj.init_attr(Field(table, field));
  //   filter_unit->set_left(filter_obj);
  // } else {
  //   FilterObj filter_obj;
  //   filter_obj.init_value(condition.left_value);
  //   filter_unit->set_left(filter_obj);
  // }

  // if (condition.right_is_attr) {
  //   Table *table = nullptr;
  //   const FieldMeta *field = nullptr;
  //   rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field);
  //   if (rc != RC::SUCCESS) {
  //     LOG_WARN("cannot find attr");
  //     return rc;
  //   }
  //   FilterObj filter_obj;
  //   filter_obj.init_attr(Field(table, field));
  //   filter_unit->set_right(filter_obj);
  // } else {
  //   FilterObj filter_obj;
  //   filter_obj.init_value(condition.right_value);
  //   filter_unit->set_right(filter_obj);
  // }

  filter_unit->set_left(std::move(left));
  filter_unit->set_right(std::move(right));
  filter_unit->set_comp(comp);

  // 检查两个类型是否能够比较
  return rc;
}
