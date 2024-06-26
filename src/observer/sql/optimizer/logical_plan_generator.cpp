/* Copyright (c) 2023 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2023/08/16.
//

#include "sql/optimizer/logical_plan_generator.h"

#include "sql/operator/logical_operator.h"
#include "sql/operator/calc_logical_operator.h"
#include "sql/operator/project_logical_operator.h"
#include "sql/operator/predicate_logical_operator.h"
#include "sql/operator/table_get_logical_operator.h"
#include "sql/operator/insert_logical_operator.h"
#include "sql/operator/delete_logical_operator.h"
#include "sql/operator/update_logical_operator.h"
#include "sql/operator/join_logical_operator.h"
#include "sql/operator/group_logical_operator.h"
#include "sql/operator/order_logical_operator.h"
#include "sql/operator/project_logical_operator.h"
#include "sql/operator/explain_logical_operator.h"

#include "sql/stmt/stmt.h"
#include "sql/stmt/calc_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/update_stmt.h"
#include "sql/stmt/explain_stmt.h"

using namespace std;

RC LogicalPlanGenerator::create(Stmt *stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  RC rc = RC::SUCCESS;
  switch (stmt->type()) {
    case StmtType::CALC: {
      CalcStmt *calc_stmt = static_cast<CalcStmt *>(stmt);
      rc = create_plan(calc_stmt, logical_operator);
    } break;

    case StmtType::SELECT: {
      SelectStmt *select_stmt = static_cast<SelectStmt *>(stmt);
      rc = create_plan(select_stmt, logical_operator);
    } break;

    case StmtType::INSERT: {
      InsertStmt *insert_stmt = static_cast<InsertStmt *>(stmt);
      rc = create_plan(insert_stmt, logical_operator);
    } break;

    case StmtType::DELETE: {
      DeleteStmt *delete_stmt = static_cast<DeleteStmt *>(stmt);
      rc = create_plan(delete_stmt, logical_operator);
    } break;

    case StmtType::UPDATE: {
      UpdateStmt *update_stmt = static_cast<UpdateStmt *>(stmt);
      rc = create_plan(update_stmt, logical_operator);
    } break;

    case StmtType::EXPLAIN: {
      ExplainStmt *explain_stmt = static_cast<ExplainStmt *>(stmt);
      rc = create_plan(explain_stmt, logical_operator);
    } break;
    default: {
      rc = RC::UNIMPLENMENT;
    }
  }
  return rc;
}

RC LogicalPlanGenerator::create_plan(CalcStmt *calc_stmt, std::unique_ptr<LogicalOperator> &logical_operator)
{
  logical_operator.reset(new CalcLogicalOperator(std::move(calc_stmt->expressions())));
  return RC::SUCCESS;
}

static Expression * generate_conj_expression(FilterStmt *filter_stmt)
{
  if (filter_stmt == nullptr) {
    return nullptr;
  }
  std::vector<unique_ptr<Expression>> cmp_exprs;
  auto &filter_units = filter_stmt->filter_units();
  for (auto & filter_unit: filter_units) {
    Expression* left_ptr = filter_unit->left();
    Expression* right_ptr = filter_unit->right();

    std::unique_ptr<Expression> left(left_ptr);
    std::unique_ptr<Expression> right(right_ptr);
    // const FilterObj &filter_obj_left = filter_unit->left();
    // const FilterObj &filter_obj_right = filter_unit->right();

    // unique_ptr<Expression> left(filter_obj_left.is_attr
    //                                      ? static_cast<Expression *>(new FieldExpr(filter_obj_left.field))
    //                                      : static_cast<Expression *>(new ValueExpr(filter_obj_left.value)));

    // unique_ptr<Expression> right(filter_obj_right.is_attr
    //                                       ? static_cast<Expression *>(new FieldExpr(filter_obj_right.field))
    //                                       : static_cast<Expression *>(new ValueExpr(filter_obj_right.value)));

    ComparisonExpr *cmp_expr = new ComparisonExpr(filter_unit->comp(), std::move(left), std::move(right));
    cmp_exprs.emplace_back(cmp_expr);
  }

  if (!cmp_exprs.empty()) {
    ConjunctionExpr::Type conj_type = (filter_stmt->is_or()) ? ConjunctionExpr::Type::OR : ConjunctionExpr::Type::AND;
    return new ConjunctionExpr(conj_type, cmp_exprs);
  } else {
    return nullptr;
  }
}

RC LogicalPlanGenerator::create_plan(
    SelectStmt *select_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  unique_ptr<LogicalOperator> table_oper(nullptr);

  const std::vector<Table *> &tables = select_stmt->tables();
  auto &table_alias = select_stmt->table_alias();
  // TODO: SIMPLYFY 
  std::vector<Field> all_fields;
  const std::vector<FilterStmt *> &join_filters = select_stmt->join_filters();
  int iter_times = 0;
  for (Table *table : tables) {
    std::vector<Field> fields;
    fields.clear();
    // for (const Field &field : all_fields) {
    //   if (0 == strcmp(field.table_name(), table->name())) {
    //     fields.push_back(field);
    //   }
    // }

    for (int i = 0; i < table->table_meta().field_num(); i++) {
      const FieldMeta *field_meta = table->table_meta().field(i);
      Field now_field(table, field_meta);
      now_field.set_table_alias(table_alias[iter_times]);
      fields.push_back(now_field);
      all_fields.push_back(now_field);
    }

    unique_ptr<LogicalOperator> table_get_oper(new TableGetLogicalOperator(table, table_alias[iter_times], fields, true/*readonly*/));
    if (table_oper == nullptr) {
      table_oper = std::move(table_get_oper);
    } else {
      JoinLogicalOperator *join_oper = new JoinLogicalOperator;
      join_oper->add_child(std::move(table_oper));
      join_oper->add_child(std::move(table_get_oper));
      if (iter_times-1 < join_filters.size()) {
        unique_ptr<LogicalOperator> join_pred_oper(nullptr);
        RC rc = create_plan(join_filters[iter_times-1], join_pred_oper);
        if (rc != RC::SUCCESS) {
          LOG_WARN("failed to create predicate logical plan. rc=%s", strrc(rc));
          return rc;
        }
        if (join_pred_oper == nullptr) {
          LOG_INFO("join_pred_oper is nullptr !!!");
        }
        join_pred_oper->add_child(std::unique_ptr<LogicalOperator>(join_oper));
        table_oper.swap(join_pred_oper);
      } else {
        table_oper = unique_ptr<LogicalOperator>(join_oper);
      }
    }

    iter_times += 1;
  }

  unique_ptr<LogicalOperator> predicate_oper;
  RC rc = create_plan(select_stmt->filter_stmt(), predicate_oper);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create predicate logical plan. rc=%s", strrc(rc));
    return rc;
  }

  unique_ptr<LogicalOperator> top_oper;
  if (predicate_oper) {
    if (table_oper) {
      predicate_oper->add_child(std::move(table_oper));
    }
    top_oper = std::move(predicate_oper);
  } else {
    if (table_oper) {
      top_oper = std::move(table_oper);
    }
  }

  if (select_stmt->group_fields().size() > 0) {
    auto &group_fields = select_stmt->group_fields();
    std::vector<uint8_t> empty_ascs;
    for (int i = 0; i < group_fields.size(); i++) {
      empty_ascs.push_back(false);
    }
    unique_ptr<LogicalOperator> order_oper(new OrderLogicalOperator(all_fields, group_fields, empty_ascs));
    order_oper->add_child(std::move(top_oper));

    Expression *conj_expr = generate_conj_expression(select_stmt->having_filter_stmt());
    unique_ptr<LogicalOperator> group_oper(new GroupLogicalOperator(all_fields, group_fields, conj_expr));
    group_oper->add_child(std::move(order_oper));

    top_oper = std::move(group_oper);
  } else if (select_stmt->has_aggregation()) {
    std::vector<Field> empty;
    unique_ptr<LogicalOperator> group_oper(new GroupLogicalOperator(all_fields, empty, nullptr));
    group_oper->add_child(std::move(top_oper));
    top_oper = std::move(group_oper);
  }
  
  if (select_stmt->order_fields().size() > 0) {
    auto &order_fields = select_stmt->order_fields();
    auto &order_ascs   = select_stmt->order_ascs();
    unique_ptr<LogicalOperator> order_oper(new OrderLogicalOperator(all_fields, order_fields, order_ascs));
    order_oper->add_child(std::move(top_oper));
    top_oper = std::move(order_oper);
  }

  unique_ptr<LogicalOperator> project_oper(new ProjectLogicalOperator(select_stmt->query_exprs()));
  // if (predicate_oper) {
  //   if (table_oper) {
  //     predicate_oper->add_child(std::move(table_oper));
  //   }
  //   project_oper->add_child(std::move(predicate_oper));
  // } else {
  //   if (table_oper) {
  //     project_oper->add_child(std::move(table_oper));
  //   }
  // }

  project_oper->add_child(std::move(top_oper));

  logical_operator.swap(project_oper);
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(
    FilterStmt *filter_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  std::vector<unique_ptr<Expression>> cmp_exprs;
  auto &filter_units = filter_stmt->filter_units();
  for (auto & filter_unit: filter_units) {
    Expression* left_ptr = filter_unit->left();
    Expression* right_ptr = filter_unit->right();

    std::unique_ptr<Expression> left(left_ptr);
    std::unique_ptr<Expression> right(right_ptr);
    // const FilterObj &filter_obj_left = filter_unit->left();
    // const FilterObj &filter_obj_right = filter_unit->right();

    // unique_ptr<Expression> left(filter_obj_left.is_attr
    //                                      ? static_cast<Expression *>(new FieldExpr(filter_obj_left.field))
    //                                      : static_cast<Expression *>(new ValueExpr(filter_obj_left.value)));

    // unique_ptr<Expression> right(filter_obj_right.is_attr
    //                                       ? static_cast<Expression *>(new FieldExpr(filter_obj_right.field))
    //                                       : static_cast<Expression *>(new ValueExpr(filter_obj_right.value)));

    ComparisonExpr *cmp_expr = new ComparisonExpr(filter_unit->comp(), std::move(left), std::move(right));
    cmp_exprs.emplace_back(cmp_expr);
  }

  unique_ptr<PredicateLogicalOperator> predicate_oper;
  if (!cmp_exprs.empty()) {
    ConjunctionExpr::Type conj_type = (filter_stmt->is_or()) ? ConjunctionExpr::Type::OR : ConjunctionExpr::Type::AND;
    unique_ptr<ConjunctionExpr> conjunction_expr(new ConjunctionExpr(conj_type, cmp_exprs));
    predicate_oper = unique_ptr<PredicateLogicalOperator>(new PredicateLogicalOperator(std::move(conjunction_expr)));
  }

  logical_operator = std::move(predicate_oper);
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(
    InsertStmt *insert_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  Table *table = insert_stmt->table();
  // vector<Value> values(insert_stmt->values(), insert_stmt->values() + insert_stmt->value_amount());
  std::vector<std::vector<Value>> &rows = insert_stmt->rows();

  InsertLogicalOperator *insert_operator = new InsertLogicalOperator(table, rows);
  logical_operator.reset(insert_operator);
  return RC::SUCCESS;
}

RC LogicalPlanGenerator::create_plan(
    DeleteStmt *delete_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  Table *table = delete_stmt->table();
  FilterStmt *filter_stmt = delete_stmt->filter_stmt();
  std::vector<Field> fields;
  for (int i = table->table_meta().sys_field_num(); i < table->table_meta().field_num(); i++) {
    const FieldMeta *field_meta = table->table_meta().field(i);
    fields.push_back(Field(table, field_meta));
  }
  unique_ptr<LogicalOperator> table_get_oper(new TableGetLogicalOperator(table, table->name(), fields, false/*readonly*/));

  unique_ptr<LogicalOperator> predicate_oper;
  RC rc = create_plan(filter_stmt, predicate_oper);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  unique_ptr<LogicalOperator> delete_oper(new DeleteLogicalOperator(table));

  if (predicate_oper) {
    predicate_oper->add_child(std::move(table_get_oper));
    delete_oper->add_child(std::move(predicate_oper));
  } else {
    delete_oper->add_child(std::move(table_get_oper));
  }

  logical_operator = std::move(delete_oper);
  return rc;
}

RC LogicalPlanGenerator::create_plan(
    UpdateStmt *update_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  Table *table = update_stmt->table();
  FilterStmt *filter_stmt = update_stmt->filter_stmt();
  std::vector<Field> fields;
  for (int i = table->table_meta().sys_field_num(); i < table->table_meta().field_num(); i++) {
    const FieldMeta *field_meta = table->table_meta().field(i);
    fields.push_back(Field(table, field_meta));
  }
  unique_ptr<LogicalOperator> table_get_oper(new TableGetLogicalOperator(table, table->name(), fields, false/*readonly*/));

  unique_ptr<LogicalOperator> predicate_oper;
  RC rc = create_plan(filter_stmt, predicate_oper);
  if (rc != RC::SUCCESS) {
    return rc;
  }

  unique_ptr<LogicalOperator> delete_oper(
    new UpdateLogicalOperator(
      table,
      update_stmt->update_fields(),
      update_stmt->update_exprs()));

  if (predicate_oper) {
    predicate_oper->add_child(std::move(table_get_oper));
    delete_oper->add_child(std::move(predicate_oper));
  } else {
    delete_oper->add_child(std::move(table_get_oper));
  }

  logical_operator = std::move(delete_oper);
  return rc;
}



RC LogicalPlanGenerator::create_plan(
    ExplainStmt *explain_stmt, unique_ptr<LogicalOperator> &logical_operator)
{
  Stmt *child_stmt = explain_stmt->child();
  unique_ptr<LogicalOperator> child_oper;
  RC rc = create(child_stmt, child_oper);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to create explain's child operator. rc=%s", strrc(rc));
    return rc;
  }

  logical_operator = unique_ptr<LogicalOperator>(new ExplainLogicalOperator);
  logical_operator->add_child(std::move(child_oper));
  return rc;
}
