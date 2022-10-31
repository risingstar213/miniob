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
// Created by Meiyi 
//

#include <mutex>
#include <deque>
#include "sql/parser/parse.h"
#include "rc.h"
#include "common/log/log.h"
#include "util/date.h"
#include "defs.h"

RC parse(char *st, Query *sqln);

// #ifdef __cplusplus
// extern "C" {
// #endif  // __cplusplus
void select_attr_init(SelectExpr *expr, RelAttr *attr)
{
  LOG_INFO("select_attr_init: %s", attr->attribute_name);
  expr->attr = attr;
  expr->is_attr = true;

  expr->is_value = false;
  expr->arithOp = ARITH_NONE;
  expr->value = nullptr;
  expr->left = nullptr;
  expr->right = nullptr;
  expr->type = UNDEFINED;
  expr->is_brace = false;
  expr->field = nullptr;
  expr->attr_num = 0;
  expr->aggregation_num = 0;
}

void select_value_init(SelectExpr *expr, Value *value)
{
  LOG_INFO("select_value_init: %s", value->raw_data);
  expr->value = value;
  expr->is_value = true;

  expr->is_attr = false;
  expr->arithOp = ARITH_NONE;
  expr->attr = nullptr;
  expr->left = nullptr;
  expr->right = nullptr;
  expr->type = UNDEFINED;
  expr->is_brace = false;
  expr->field = nullptr;
  expr->attr_num = 0;
  expr->aggregation_num = 0;
}

void select_subexpr_init(SelectExpr *expr, SelectExpr *left, SelectExpr *right,
          ArithOp op) {
  expr->left = left;
  expr->right = right;
  expr->arithOp = op;

  expr->is_attr = false;
  expr->is_value = false;
  expr->attr = nullptr;
  expr->value = nullptr;
  expr->type = UNDEFINED;
  expr->is_brace = false;
  expr->field = nullptr;
  expr->attr_num = 0;
  expr->aggregation_num = 0;
}

void select_expr_destroy(SelectExpr *expr)
{
  if (expr->is_value) {
    value_destroy(expr->value);
    delete expr->value;
    expr->is_value = false;
    expr->value = nullptr;
  }
  if (expr->is_attr) {
    relation_attr_destroy(expr->attr);
    delete expr->attr;
    expr->is_attr = false;
    expr->attr = nullptr;
  }
  if (expr->left != nullptr) {
    select_expr_destroy(expr->left);
    delete expr->left;
    expr->left = nullptr;
  }
  if (expr->right != nullptr) {
    select_expr_destroy(expr->right);
    delete expr->right;
    expr->right = nullptr;
  }
  expr->aggregation_num = 0;
  expr->attr_num = 0;
  if (expr->field != nullptr) {
    delete expr->field;
    expr->field = nullptr;
  }
  expr->is_brace = false;
}

void relation_attr_init(RelAttr *relation_attr, const char *relation_name, const char *attribute_name)
{
  if (relation_name != nullptr) {
    relation_attr->relation_name = strdup(relation_name);
  } else {
    relation_attr->relation_name = nullptr;
  }
  if (attribute_name != nullptr) {
    relation_attr->attribute_name = strdup(attribute_name);
  } else {
    relation_attr->attribute_name = nullptr;
  }
  relation_attr->is_valid = true;
}
void relation_attr_init_with_aggregation(RelAttr *relation_attr, const char *relation_name, const char *attribute_name, Aggregation agg, bool is_valid)
{
  LOG_INFO("relation_attr_init_with_aggregation");
  if (relation_name != nullptr) {
    relation_attr->relation_name = strdup(relation_name);
  } else {
    relation_attr->relation_name = nullptr;
  }
  if (attribute_name != nullptr) {
    relation_attr->attribute_name = strdup(attribute_name);
  } else {
    relation_attr->attribute_name = nullptr;
  }
  relation_attr->agg = agg;
  relation_attr->is_valid = is_valid;
}

void relation_attr_init_copy(RelAttr *relation_attr, RelAttr source, Aggregation agg)
{
  LOG_INFO("relation_attr_init_copy");
  relation_attr->relation_name = source.relation_name;
  relation_attr->attribute_name = source.attribute_name;
  relation_attr->is_valid = source.is_valid;
  relation_attr->agg = agg;
}

void relation_attr_destroy(RelAttr *relation_attr)
{
  free(relation_attr->relation_name);
  free(relation_attr->attribute_name);
  relation_attr->relation_name = nullptr;
  relation_attr->attribute_name = nullptr;
}

void value_init_integer(Value *value, int v, const char *raw)
{
  value->type = INTS;
  value->data = malloc(sizeof(v));
  memcpy(value->data, &v, sizeof(v));
  value->raw_data = strdup(raw);
}
void value_init_float(Value *value, float v, const char *raw)
{
  value->type = FLOATS;
  value->data = malloc(sizeof(v));
  memcpy(value->data, &v, sizeof(v));
  value->raw_data = strdup(raw);
}
void value_init_string(Value *value, const char *v)
{
  value->type = CHARS;
  value->data = strdup(v);
  value->raw_data = strdup(v);
}
void value_init_date(Value *value, const char *v) {
  value->type = DATES;
  string s(v);
  value->data = malloc(sizeof(Date));
  ((Date *)value->data)->set_date(s);
  LOG_INFO("%s", ((Date *)value->data)->toString().c_str());
  value->raw_data = strdup(v);
}
void value_init_null(Value *value) {
  value->type = INTS;
  int v = NULL_CONST;
  value->data = malloc(12 * sizeof(char));
  memcpy(value->data, &v, sizeof(v));
  value->raw_data = strdup("null");
}
void value_destroy(Value *value)
{
  value->type = UNDEFINED;
  free(value->data);
  value->data = nullptr;
  free(value->raw_data);
  value->raw_data = nullptr;
}

void updatevalue_init_value(UpdateValue *update_value, Value *value) {
  update_value->is_select = false;
  update_value->value.value = *value;
}

void updatevalue_init_select(UpdateValue *update_value, Selects *select) {
  LOG_INFO("updatevalue_init_select");
  update_value->is_select = true;
  update_value->value.select = *select;
}
void updatevalue_destroy(UpdateValue *update_value) {
  if (update_value->is_select) {
    selects_destroy(&update_value->value.select);
  } else {
    value_destroy(&update_value->value.value);
  }
  update_value->is_select = false;
}

void condition_init(Condition *condition, CompOp comp, SelectExpr *left_expr,
    SelectExpr *right_expr)
{
  condition->comp = comp;
  condition->left_expr = *left_expr;
  condition->right_expr = *right_expr;
}
void condition_destroy(Condition *condition)
{
  select_expr_destroy(&condition->left_expr);
  select_expr_destroy(&condition->right_expr);
}

void attr_info_init(AttrInfo *attr_info, const char *name, AttrType type, size_t length)
{
  attr_info->name = strdup(name);
  attr_info->type = type;
  attr_info->length = length;
  attr_info->nullable = false;
  LOG_INFO("attr_info_init: %s, %d, %d", name, type, length);
}
void attr_info_destroy(AttrInfo *attr_info)
{
  free(attr_info->name);
  attr_info->name = nullptr;
}

void join_set_relation(Join *join, const char *relation_name)
{
  LOG_INFO("%p, JOIN TABLE: %s", join, relation_name);
  join->relation_name = strdup(relation_name);
}

void join_append_conditions(Join *join, std::deque<Condition> conditions)
{
  LOG_INFO("%p, JOIN CONDITION NUM: %d", join, conditions.size());
  for (size_t i = 0; i < conditions.size(); i++) {
    join->conditions[i] = conditions[i];
  }
  join->condition_num = conditions.size();
}

void join_destroy(Join *join)
{
  free(join->relation_name);
  join->relation_name = nullptr;

  for (size_t i = 0; i < join->condition_num; i++) {
    condition_destroy(&join->conditions[i]);
  }
  join->condition_num = 0;
}

void selects_init(Selects *selects, ...);

void selects_append_select_exprs(Selects *selects, std::deque<SelectExpr> select_exprs)
{
  for (size_t i = 0; i < select_exprs.size(); i++) {
    selects->select_expr[i] = select_exprs[i];
  }
  selects->select_expr_num = select_exprs.size();
}
void selects_append_relation(Selects *selects, std::deque<char *> relation_names)
{
  for (size_t i = 0; i < relation_names.size(); i++) {
    selects->relations[selects->relation_num++] = strdup(relation_names[i]);
  }
  selects->relation_num = relation_names.size();
}

void selects_append_conditions(Selects *selects, std::deque<Condition> conditions)
{
  assert(conditions.size() <= sizeof(selects->conditions) / sizeof(selects->conditions[0]));
  for (size_t i = 0; i < conditions.size(); i++) {
    selects->conditions[i] = conditions[i];
  }
  selects->condition_num = conditions.size();
}

void selects_append_joins(Selects *selects, std::deque<Join> joins)
{
  for (size_t i = 0; i < joins.size(); i++) {
    selects->join[i] = joins[i];
  }
  selects->join_num = joins.size();
}

void selects_destroy(Selects *selects)
{
  for (size_t i = 0; i < selects->select_expr_num; i++) {
    select_expr_destroy(&selects->select_expr[i]);
  }
  selects->select_expr_num = 0;

  for (size_t i = 0; i < selects->relation_num; i++) {
    free(selects->relations[i]);
    selects->relations[i] = NULL;
  }
  selects->relation_num = 0;

  for (size_t i = 0; i < selects->condition_num; i++) {
    condition_destroy(&selects->conditions[i]);
  }
  selects->condition_num = 0;

  for (size_t i = 0; i < selects->join_num; i++) {
    join_destroy(&selects->join[i]);
  }
  selects->join_num = 0;
}


void inserts_row_init(Rows *rows, std::deque<Value> values)
{
  for (size_t i = 0; i < values.size(); i++) {
    rows->values[i] = values[i];
  }
  rows->value_num = values.size();
}

void inserts_init(Inserts *inserts, const char *relation_name) {
  inserts->relation_name = strdup(relation_name);
}

void inserts_destroy(Inserts *inserts)
{
  free(inserts->relation_name);
  inserts->relation_name = nullptr;

  for (size_t i = 0; i < inserts->row_num; i++) {
    row_destory(&inserts->rows[i]);
  }
  inserts->row_num = 0;
}

void row_destory(Rows *row) {
  for (size_t i = 0; i < row->value_num; i++) {
    value_destroy(&row->values[i]);
  }
}

void deletes_init_relation(Deletes *deletes, const char *relation_name)
{
  deletes->relation_name = strdup(relation_name);
}

void deletes_set_conditions(Deletes *deletes, std::deque<Condition> conditions)
{
  assert(conditions.size() <= sizeof(deletes->conditions) / sizeof(deletes->conditions[0]));
  for (size_t i = 0; i < conditions.size(); i++) {
    deletes->conditions[i] = conditions[i];
  }
  deletes->condition_num = conditions.size();
}
void deletes_destroy(Deletes *deletes)
{
  for (size_t i = 0; i < deletes->condition_num; i++) {
    condition_destroy(&deletes->conditions[i]);
  }
  deletes->condition_num = 0;
  free(deletes->relation_name);
  deletes->relation_name = nullptr;
}

void updates_init(Updates *updates, const char *relation_name, std::deque<Condition> conditions)
{
  LOG_INFO("updates_init");
  updates->relation_name = strdup(relation_name);

  assert(conditions.size() <= sizeof(updates->conditions) / sizeof(updates->conditions[0]));
  for (size_t i = 0; i < conditions.size(); i++) {
    updates->conditions[i] = conditions[i];
  }
  updates->condition_num = conditions.size();
}

void update_append_attribute(Updates *updates, const char *attribute_name, UpdateValue *update_value)
{
  // LOG_INFO("update_append_attribute %s, %s", attribute_name, value->raw_data);
  LOG_INFO("update_append_attribute");
  if (attribute_name == nullptr) {
    LOG_INFO("nullptr");
  } else {
    LOG_INFO("%d,%s, %p", updates->attribute_num, attribute_name, update_value);
  }
  updates->attribute_name[updates->attribute_num] = strdup(attribute_name);
  LOG_INFO("update_append_attribute");
  updates->update_value[updates->attribute_num] = *update_value;
  updates->attribute_num += 1;
}

void updates_destroy(Updates *updates)
{
  free(updates->relation_name);
  updates->relation_name = nullptr;
  for (int i = 0; i < updates->attribute_num ; i++) {
    free(updates->attribute_name[i]);
    updates->attribute_name[i] = nullptr;
    updatevalue_destroy(&updates->update_value[i]);
  }
  updates->attribute_num = 0;

  for (size_t i = 0; i < updates->condition_num; i++) {
    condition_destroy(&updates->conditions[i]);
  }
  updates->condition_num = 0;
}

void create_table_append_attribute(CreateTable *create_table, AttrInfo *attr_info)
{
  create_table->attributes[create_table->attribute_count++] = *attr_info;
}

void create_table_init_name(CreateTable *create_table, const char *relation_name)
{
  create_table->relation_name = strdup(relation_name);
}

void create_table_destroy(CreateTable *create_table)
{
  for (size_t i = 0; i < create_table->attribute_count; i++) {
    attr_info_destroy(&create_table->attributes[i]);
  }
  create_table->attribute_count = 0;
  free(create_table->relation_name);
  create_table->relation_name = nullptr;
}

void drop_table_init(DropTable *drop_table, const char *relation_name)
{
  drop_table->relation_name = strdup(relation_name);
}

void drop_table_destroy(DropTable *drop_table)
{
  free(drop_table->relation_name);
  drop_table->relation_name = nullptr;
}

void create_index_init(
    CreateIndex *create_index, const char *index_name, const char *relation_name, std::deque<char *> attr_names, bool is_unique)
{
  create_index->index_name = strdup(index_name);
  create_index->relation_name = strdup(relation_name);
  for (size_t i = 0; i < attr_names.size(); i++) {
    create_index->attribute_name[i] = strdup(attr_names[i]);
  }
  create_index->attribute_num = attr_names.size();
  create_index->is_unique = is_unique;
}

void create_index_destroy(CreateIndex *create_index)
{
  free(create_index->index_name);
  free(create_index->relation_name);

  create_index->index_name = nullptr;
  create_index->relation_name = nullptr;
  for (size_t i = 0; i < create_index->attribute_num; i++) {
    free(create_index->attribute_name[i]);
  }
  create_index->attribute_num = 0;
}

void drop_index_init(DropIndex *drop_index, const char *index_name)
{
  drop_index->index_name = strdup(index_name);
}

void drop_index_destroy(DropIndex *drop_index)
{
  free((char *)drop_index->index_name);
  drop_index->index_name = nullptr;
}

void show_index_init(ShowIndex *show_index, const char *relation_name)
{
  show_index->relation_name = strdup(relation_name);
}

void show_index_destroy(ShowIndex *show_index)
{
  free((char *)show_index->relation_name);
  show_index->relation_name = nullptr;
}

void desc_table_init(DescTable *desc_table, const char *relation_name)
{
  desc_table->relation_name = strdup(relation_name);
}

void desc_table_destroy(DescTable *desc_table)
{
  free((char *)desc_table->relation_name);
  desc_table->relation_name = nullptr;
}

void load_data_init(LoadData *load_data, const char *relation_name, const char *file_name)
{
  load_data->relation_name = strdup(relation_name);

  if (file_name[0] == '\'' || file_name[0] == '\"') {
    file_name++;
  }
  char *dup_file_name = strdup(file_name);
  int len = strlen(dup_file_name);
  if (dup_file_name[len - 1] == '\'' || dup_file_name[len - 1] == '\"') {
    dup_file_name[len - 1] = 0;
  }
  load_data->file_name = dup_file_name;
}

void load_data_destroy(LoadData *load_data)
{
  free((char *)load_data->relation_name);
  free((char *)load_data->file_name);
  load_data->relation_name = nullptr;
  load_data->file_name = nullptr;
}

void query_init(Query *query)
{
  query->flag = SCF_ERROR;
  memset(&query->sstr, 0, sizeof(query->sstr));
}

Query *query_create()
{
  Query *query = (Query *)malloc(sizeof(Query));
  if (nullptr == query) {
    LOG_ERROR("Failed to alloc memroy for query. size=%ld", sizeof(Query));
    return nullptr;
  }

  query_init(query);
  return query;
}

void query_reset(Query *query)
{
  switch (query->flag) {
    case SCF_SELECT: {
      selects_destroy(&query->sstr.selection);
    } break;
    case SCF_INSERT: {
      inserts_destroy(&query->sstr.insertion);
    } break;
    case SCF_DELETE: {
      deletes_destroy(&query->sstr.deletion);
    } break;
    case SCF_UPDATE: {
      updates_destroy(&query->sstr.update);
    } break;
    case SCF_CREATE_TABLE: {
      create_table_destroy(&query->sstr.create_table);
    } break;
    case SCF_DROP_TABLE: {
      drop_table_destroy(&query->sstr.drop_table);
    } break;
    case SCF_CREATE_INDEX: {
      create_index_destroy(&query->sstr.create_index);
    } break;
    case SCF_DROP_INDEX: {
      drop_index_destroy(&query->sstr.drop_index);
    } break;
    case SCF_SHOW_INDEX: {
      show_index_destroy(&query->sstr.show_index);
    } break;
    case SCF_SYNC: {

    } break;
    case SCF_SHOW_TABLES:
      break;

    case SCF_DESC_TABLE: {
      desc_table_destroy(&query->sstr.desc_table);
    } break;

    case SCF_LOAD_DATA: {
      load_data_destroy(&query->sstr.load_data);
    } break;
    case SCF_CLOG_SYNC:
    case SCF_BEGIN:
    case SCF_COMMIT:
    case SCF_ROLLBACK:
    case SCF_HELP:
    case SCF_EXIT:
    case SCF_ERROR:
      break;
  }
}

void query_destroy(Query *query)
{
  query_reset(query);
  free(query);
}
// #ifdef __cplusplus
// }  // extern "C"
// #endif  // __cplusplus

////////////////////////////////////////////////////////////////////////////////

int sql_parse(const char *st, Query *sqls);

RC parse(const char *st, Query *sqln)
{
  sql_parse(st, sqln);

  if (sqln->flag == SCF_ERROR)
    return SQL_SYNTAX;
  else
    return SUCCESS;
}