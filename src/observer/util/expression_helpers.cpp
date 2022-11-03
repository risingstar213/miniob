

#include "util/expression_helpers.h"
#include "util/date.h"

#include "storage/trx/trx.h"
#include "common/log/log.h"
#include "common/lang/string.h"
#include "storage/common/field.h"

static bool check_field(Field &rel_field, Field &target_field)
{
  if (strcmp(rel_field.table_name(), target_field.table_name()) == 0) {
    if (strcmp(rel_field.field_name(), target_field.field_name()) == 0) {
      return true;
    }
  }
  return false;
}


RC check_select_expression_valid(SelectExpr *expr, int depth, std::vector<TableInfo> *tables, 
          std::unordered_map<std::string, Table *> *tables_map, std::vector<Field> *group_fields)
{
  if (expr->is_value) {
    expr->type = expr->value->type;
    if (expr->value->type == DATES) {
      Date *d = (Date *)expr->value->data;
      if (!d->is_valid()) {
        LOG_WARN("The date %s is not valid", d->toString().c_str());
        return RC::SQL_SYNTAX;
      }
    }
    return RC::SUCCESS;
  }
  if (expr->is_attr) {
    expr->attr_num += 1;
    if (expr->attr->agg != AGG_NONE) {
      expr->aggregation_num += 1;
    }
    if (!expr->attr->is_valid) {
      LOG_INFO("attr is not valid");
      return RC::INVALID_ARGUMENT;
    }
    // select * / count(*)
    if (strcmp(expr->attr->attribute_name, "*") == 0) {
      if ((depth == 0 && expr->attr->agg == AGG_NONE)) {
        expr->type = INTS;
        return RC::SUCCESS;
      } else if (expr->attr->agg == AGG_COUNT) {
        expr->type = INTS;
        Table *table = (*tables)[0].table;
        expr->field = new Field(table, table->table_meta().field(Trx::trx_field_name()));
        if (expr->attr->alias != nullptr) {
          expr->field->set_alias(expr->attr->alias);
        }
        return RC::SUCCESS;
      } else {
        LOG_WARN("agg(*) expcept count is not supported.");
        return RC::INVALID_ARGUMENT;
      }
    }
    Table * table;
    const char *table_alias;
    if (!common::is_blank(expr->attr->relation_name)) {
      auto iter = tables_map->find(expr->attr->relation_name);
      if (iter == tables_map->end()) {
        LOG_WARN("no such table in from list: %s", expr->attr->relation_name);
        return RC::SCHEMA_FIELD_MISSING;
      }
      table = iter->second;
      table_alias = expr->attr->relation_name;
    } else {
      if (tables->size() != 1) {
        LOG_WARN("invalid. I do not know the attr's table. attr=%s", expr->attr->attribute_name);
        return RC::SCHEMA_FIELD_MISSING;
      }

      table = (*tables)[0].table;
      table_alias = (*tables)[0].alias;
    }

    const FieldMeta *field_meta = table->table_meta().field(expr->attr->attribute_name);
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s", table->name(), expr->attr->attribute_name);
      return RC::SCHEMA_FIELD_MISSING;
    }
    expr->field = new Field(table, field_meta);
    if (expr->attr->alias != nullptr) {
      expr->field->set_alias(expr->attr->alias);
    }
    expr->field->set_table_alias(table_alias);

    // check group by field
    if (group_fields != nullptr) {
      for (auto &field : *group_fields) {
        if (check_field(*expr->field, field)) {
          expr->aggregation_num += 1;
        }
      }
    }

    expr->type = expr->field->attr_type();
    return RC::SUCCESS;
  }
  RC rc;
  if (expr->left != nullptr) {
    rc = check_select_expression_valid(expr->left, depth+1, tables, tables_map);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    if (expr->left->type == DATES || expr->left->type == CHARS || expr->left->type == TEXTS) {
      LOG_WARN("the type %d in complex expression is not supported.", expr->left->type);
      return RC::INVALID_ARGUMENT;
    }
    expr->attr_num += expr->left->attr_num;
    expr->aggregation_num += expr->left->aggregation_num;
  }
  rc = check_select_expression_valid(expr->right, depth+1, tables, tables_map);
  if (rc != RC::SUCCESS) {
    return rc;
  }
  if (expr->right->type == DATES || expr->right->type == CHARS || expr->right->type == TEXTS) {
      LOG_WARN("the type %d in complex expression is not supported.", expr->right->type);
      return RC::INVALID_ARGUMENT;
  }
  expr->attr_num += expr->right->attr_num;
  expr->aggregation_num += expr->right->aggregation_num;
  expr->type = FLOATS;
  return RC::SUCCESS;
}

static void wildcard_fields(TableInfo &table,  std::vector<SelectExpr> &expressions)
{
  const TableMeta &table_meta = table.table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    // special
    SelectExpr expr;
    memset(&expr, 0, sizeof(SelectExpr));
    expr.field = new Field(table.table, table_meta.field(i));
    if (table.alias != nullptr) {
      expr.field->set_table_alias(table.alias);
    }
    expr.is_attr = true;
    expressions.push_back(expr);
  }
}

RC append_select_expression_with_star(std::vector<TableInfo> tables, SelectExpr *expr, std::vector<SelectExpr> &expressions)
{
  // TODO: The only star currently
  if (expr->is_attr && strcmp(expr->attr->attribute_name, "*") == 0 && expr->attr->agg == AGG_NONE) {
    for (auto &table_info : tables) {
      wildcard_fields(table_info, expressions);
    }
  } else {
    expressions.push_back(*expr);
  }
  return RC::SUCCESS;
}

Expression *generate_expression(SelectExpr *expr)
{
  // LOG_INFO("generate_expression");
  if (expr->is_value) {
    return new ValueExpr(*expr->value);
  }
  if (expr->is_attr) {
    bool is_aggregation = (expr->attr != nullptr) && (expr->attr->agg != AGG_NONE);
    Aggregation agg = is_aggregation ?  expr->attr->agg : AGG_NONE;
    return new FieldExpr(expr->field->table(), expr->field->meta(), agg);
  }
  Expression *left = nullptr, *right = nullptr;

  if (expr->left != nullptr) {
    LOG_INFO("generate left");
    left = generate_expression(expr->left);
  }
  if (expr->right != nullptr) {
    LOG_INFO("generate right");
    right = generate_expression(expr->right);
  }
  return new ComplexExpr(expr, left, right);
}

std::string generate_alias(bool multi_tables, SelectExpr *expr)
{
  std::string str;
  if (expr->is_brace) {
    str += '(';
  }
  if (expr->is_value) {
    str += (char *)expr->value->raw_data;
  } else if (expr->is_attr) {
    if (expr->field->get_alias() != nullptr) {
      str += expr->field->get_alias();
    } else {
      Aggregation agg = expr->attr == nullptr ? AGG_NONE: expr->attr->agg;
      switch(agg) {
        case AGG_AVG:
          str += "AVG(";
          break;
        case AGG_COUNT:
          str += "COUNT(";
          break;
        case AGG_MAX:
          str += "MAX(";
          break;
        case AGG_MIN:
          str += "MIN(";
          break;
        case AGG_SUM:
          str += "SUM(";
          break;
        default:
          break;
      }
      if (strcmp(expr->field->meta()->name(), Trx::trx_field_name()) == 0) {
        str += "*";
      } else if (multi_tables) {
        str += expr->field->table_name();
        str += '.';
        str += expr->field->meta()->name();
      } else {
        str += expr->field->meta()->name();
      }
      if (agg != AGG_NONE) {
        str += ")";
      }
    }
  } else {
    std::string left_str;
    std::string right_str;
    if (expr->left != nullptr) {
      left_str = generate_alias(multi_tables, expr->left);
    }
    if (expr->right != nullptr) {
      right_str = generate_alias(multi_tables, expr->right);
    }
    switch (expr->arithOp) {
      case ARITH_ADD: {
        str += left_str + "+" + right_str;
      } break;
      case ARITH_SUB: {
        str += left_str + "-" + right_str;
      } break;
      case ARITH_MUL: {
        str += left_str + "*" + right_str;
      } break;
      case ARITH_DIV: {
        str += left_str + "/" + right_str;
      } break;
      case ARITH_NEG: {
        str += "-" + right_str;
      } break;
      default:
        break;
    }
  }
  if (expr->is_brace) {
    str += ')';
  }
  return str;
}