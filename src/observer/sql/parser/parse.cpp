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
// Created by Meiyi
//

#include <mutex>
#include "sql/parser/parse.h"
#include "sql/parser/parse_defs.h"
#include "common/log/log.h"
#include "sql/expr/expression.h"

RC parse(char *st, ParsedSqlNode *sqln);

CalcSqlNode::~CalcSqlNode()
{
  // for (Expression *expr : expressions) {
  //   delete expr;
  // }
  expressions.clear();
}

ParsedSqlNode::ParsedSqlNode() : flag(SCF_ERROR)
{}

ParsedSqlNode::ParsedSqlNode(SqlCommandFlag _flag) : flag(_flag)
{}

void ParsedSqlResult::add_sql_node(std::unique_ptr<ParsedSqlNode> sql_node)
{
  sql_nodes_.emplace_back(std::move(sql_node));
}

////////////////////////////////////////////////////////////////////////////////

int sql_parse(const char *st, ParsedSqlResult *sql_result);

RC parse(const char *st, ParsedSqlResult *sql_result)
{
  sql_parse(st, sql_result);
  return RC::SUCCESS;
}
////////////////////////////////////////release/////////////////

void ExprSqlNode::release() {
  if (left != nullptr) {
    left->release();
    delete left;
    left = nullptr;
  }

  if (right != nullptr) {
    right->release();
    delete right;
    right = nullptr;
  }

  if (value != nullptr) {
    delete value;
    value = nullptr;
  }

  if (attr != nullptr) {
    delete attr;
    attr = nullptr;
  }

  if (field != nullptr) {
    delete field;
    field = nullptr;
  }
}

void ConditionSqlNode::release() {
  if (left_expr != nullptr) {
    left_expr->release();
    delete left_expr;
    left_expr = nullptr;
  }

  if (left_subquery != nullptr) {
    left_subquery->release();
    delete left_subquery;
    left_subquery = nullptr;
  }


  if (right_expr != nullptr) {
    right_expr->release();
    delete right_expr;
    right_expr = nullptr;
  }

  if (right_subquery != nullptr) {
    right_subquery->release();
    delete right_subquery;
    right_subquery = nullptr;
  }
}

void JoinSqlNode::release() {
  for (int i = 0; i < on_coditions.size(); i++) {
    on_coditions[i].release();
  }
}

void GroupBySqlNode::release() {
  for (int i = 0; i < having_conditions.size(); i++) {
    having_conditions[i].release();
  }
  having_conditions.clear();
}

void OrderBySqlNode::release() {
  if (by_attr != nullptr) {
    delete by_attr;
    by_attr = nullptr;
  }
}

void SelectSqlNode::release() {
  LOG_INFO("release!");
  for (int i = 0; i < select_exprs.size(); i++) {
    select_exprs[i].release();
  }
  select_exprs.clear();
  for (int i = 0; i < joins.size(); i++) {
    joins[i].release();
  }
  joins.clear();
  for (int i = 0; i < conditions.size(); i++) {
    conditions[i].release();
  }
  conditions.clear();
  group_by.release();
  for (int i = 0; i < order_bys.size(); i++) {
    order_bys[i].release();
  }
  order_bys.clear();
}

void CalcSqlNode::release() {
  for (int i = 0; i < expressions.size(); i++) {
    expressions[i].release();
  }
  expressions.clear();
}

void DeleteSqlNode::release() {
  for (int i = 0; i < conditions.size(); i++) {
    conditions[i].release();
  }
  conditions.clear();
}

void UpdatePairSqlNode::release() {
  select_value.release();
}

void UpdateSqlNode::release() {
  for (int i = 0; i < attr_values.size(); i++) {
    attr_values[i].release();
  }
  attr_values.clear();
  for (int i = 0; i < conditions.size(); i++) {
    conditions[i].release();
  }
  conditions.clear();
}

ParsedSqlNode::~ParsedSqlNode() {
  calc.release();
  selection.release();
  deletion.release();
  update.release();
}

void ParsedSqlNode::release() {
  calc.release();
  selection.release();
  deletion.release();
  update.release();
}