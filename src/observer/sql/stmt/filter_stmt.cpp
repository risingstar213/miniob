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

#include "rc.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "storage/common/db.h"
#include "storage/common/table.h"
#include "util/date.h"
#include "util/expression_helpers.h"

FilterStmt::~FilterStmt()
{
  for (FilterUnit *unit : filter_units_) {
    delete unit;
  }
  filter_units_.clear();
}

RC FilterStmt::create(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
		      Condition *conditions, int condition_num,
		      FilterStmt *&stmt)
{
  RC rc = RC::SUCCESS;
  stmt = nullptr;

  FilterStmt *tmp_stmt = new FilterStmt();
  for (int i = 0; i < condition_num; i++) {
    FilterUnit *filter_unit = nullptr;
    rc = create_filter_unit(db, default_table, tables, conditions[i], filter_unit);
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
		       const RelAttr &attr, Table *&table, const FieldMeta *&field)
{
  table = nullptr;
  if (common::is_blank(attr.relation_name)) {
    table = default_table;
  } else if (nullptr != tables) {
    auto iter = tables->find(std::string(attr.relation_name));
    if (iter != tables->end()) {
      table = iter->second;
    }
  } else {
    table = db->find_table(attr.relation_name);
  }
  if (nullptr == table) {
    LOG_WARN("No such table: attr.relation_name: %s", attr.relation_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  field = table->table_meta().field(attr.attribute_name);
  if (nullptr == field) {
    LOG_WARN("no such field in table: table %s, field %s", table->name(), attr.attribute_name);
    table = nullptr;
    return RC::SCHEMA_FIELD_NOT_EXIST;
  }

  return RC::SUCCESS;
}

RC FilterStmt::create_filter_unit(Db *db, Table *default_table, std::unordered_map<std::string, Table *> *tables,
				  Condition &condition, FilterUnit *&filter_unit)
{
  RC rc = RC::SUCCESS;
  
  CompOp comp = condition.comp;
  if (comp < EQUAL_TO || comp >= NO_OP) {
    LOG_WARN("invalid compare operator : %d", comp);
    return RC::INVALID_ARGUMENT;
  }

  Expression *left = nullptr;
  Expression *right = nullptr;

  AttrType left_type = UNDEFINED;
  AttrType right_type = UNDEFINED;

  std::vector<Table *> table;
  table.push_back(default_table);

  // check left && build left expression
  if (condition.left_expr.is_sq) {
    Stmt *stmt;
    rc = SelectStmt::create(db, *condition.left_expr.select, stmt);
    if (rc != RC::SUCCESS) {
      LOG_INFO("Cannot build sub query.");
      return rc;
    }
    
    SelectStmt *select_stmt = (SelectStmt *)stmt;
    if (select_stmt->select_exprs().size() != 1) {
      LOG_INFO("return more than one value from sub query!");
      return rc;
    }
    left = new SqueryExpr(select_stmt);
    left_type = left->get_valuetype();
  } else if (condition.left_expr.expr != nullptr) {
    rc = check_select_expression_valid(condition.left_expr.expr, 0, &table, tables);
    if (rc != RC::SUCCESS) {
      LOG_INFO("left condition not valid: %s", strrc(rc));
      return rc;
    }
    left = generate_expression(condition.left_expr.expr);
    left_type = left->get_valuetype();
  } else {
    left = nullptr;
    left_type = UNDEFINED;
  }

  if (condition.right_expr.is_sq) {
    Stmt *stmt;
    rc = SelectStmt::create(db, *condition.right_expr.select, stmt);
    if (rc != RC::SUCCESS) {
      LOG_INFO("Cannot build sub query.");
      return rc;
    }
    SelectStmt *select_stmt = (SelectStmt *)stmt;
    // if (select_stmt->select_exprs().size() != 1) {
    //   LOG_INFO("return more than one value from sub query!");
    //   return rc;
    // }
    right = new SqueryExpr(select_stmt);
    right_type = right->get_valuetype();
  } else if (condition.right_expr.expr != nullptr) {
    rc = check_select_expression_valid(condition.right_expr.expr, 0, &table, tables);
    if (rc != RC::SUCCESS) {
      LOG_INFO("right condition not valid: %s", strrc(rc));
      return rc;
    }
    right = generate_expression(condition.right_expr.expr);
    right_type = right->get_valuetype();
  } else {
    right = nullptr;
    right_type = UNDEFINED;
  }
  // if (condition.left_is_attr) {
  //   Table *table = nullptr;
  //   const FieldMeta *field = nullptr;
  //   rc = get_table_and_field(db, default_table, tables, condition.left_attr, table, field);  
  //   if (rc != RC::SUCCESS) {
  //     LOG_WARN("cannot find attr");
  //     return rc;
  //   }
  //   left = new FieldExpr(table, field);
  //   left_type = field->type();
  // } else {
  //   left_type = condition.left_value.type;
  //   // check
  //   LOG_INFO("CHECK DATES: %s", condition.left_value.raw_data);
  //   if (left_type == DATES) {
  //     Date *d = (Date *)condition.left_value.data;
  //     if (!d->is_valid()) {
  //       LOG_WARN("The date %s is not valid", d->toString().c_str());
  //       return RC::SQL_SYNTAX;
  //     }
  //   }
  //   left = new ValueExpr(condition.left_value);
  // }

  // if (condition.right_is_attr) {
  //   Table *table = nullptr;
  //   const FieldMeta *field = nullptr;
  //   rc = get_table_and_field(db, default_table, tables, condition.right_attr, table, field);  
  //   if (rc != RC::SUCCESS) {
  //     LOG_WARN("cannot find attr");
  //     delete left;
  //     return rc;
  //   }
  //   right = new FieldExpr(table, field);
  //   right_type = field->type();
  // } else {
  //   right_type = condition.right_value.type;
  //   // check
  //   LOG_INFO("CHECK DATES %s", condition.right_value.raw_data);
  //   if (right_type == DATES) {
  //     Date *d = (Date *)condition.right_value.data;
  //     if (!d->is_valid()) {
  //       delete left;
  //       LOG_WARN("The date %s is not valid", d->toString().c_str());
  //       return RC::SQL_SYNTAX;
  //     }
  //   }
  //   right = new ValueExpr(condition.right_value);
  // }

  bool can_compare = true;
  bool left_cast = left_type == CHARS || left_type == INTS || left_type == FLOATS;
  bool right_cast = right_type == CHARS || right_type == INTS || right_type == FLOATS;
  if (left_cast && right_cast) {
    can_compare = true;
  } else if (left_type == right_type) {
    can_compare = true;
  } else if (left_type == UNDEFINED) { // EXISTS
    can_compare = true;
  } else if (left->is_null() || right->is_null()) {
    can_compare = true;
  } else {
    can_compare = false;
  }
  // 检查两个类型是否能够比较
  if (!can_compare) {
    delete left;
    delete right;
    LOG_WARN("cannot compare");
    return RC::SCHEMA_FIELD_TYPE_MISMATCH;
  }

  // Check whether like comparator is valid
  if (comp == LIKE_SCH || comp == UNLIKE_SCH) {
    if (condition.left_expr.is_sq || condition.left_expr.expr == nullptr || 
        !condition.left_expr.expr->is_attr || right_type != CHARS) {
      delete left;
      delete right;
      LOG_WARN("not supported");
      return RC::SCHEMA_FIELD_TYPE_MISMATCH;
    }
  }

  filter_unit = new FilterUnit;
  filter_unit->set_comp(comp);
  filter_unit->set_left(left);
  filter_unit->set_right(right);

  return rc;
}
