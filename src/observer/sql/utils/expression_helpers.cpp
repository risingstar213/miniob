#include <memory>

#include "sql/utils/expression_helpers.h"

#include "storage/trx/trx.h"
#include "common/log/log.h"
#include "common/lang/string.h"


static bool check_field(Field &rel_field, Field &target_field)
{
  if (strcmp(rel_field.get_table_alias().c_str(), target_field.get_table_alias().c_str()) == 0) {
    if (strcmp(rel_field.field_name(), target_field.field_name()) == 0) {
      return true;
    }
  }
  return false;
}


RC check_select_expression_valid(ExprSqlNode &expr, int depth, std::vector<Table *> &tables, std::string default_name,
          std::unordered_map<std::string, Table *> &tables_map, std::vector<Field> *group_fields)
{
  if (expr.type == E_VAL) {
    expr.attrType = expr.value->attr_type();
    if (!expr.value->check_valid()) {
      LOG_WARN("The date %s is not valid", expr.value->to_string().c_str());
      return RC::SQL_SYNTAX;
    }
    return RC::SUCCESS;
  }
  if (expr.type == E_DYN) {
    expr.attr_num += 1;
    if (expr.attr->aggType != A_UNDEFINED) {
      expr.aggregation_num += 1;
    }
    // if (!expr->attr->is_valid) {
    //   LOG_INFO("attr is not valid");
    //   return RC::INVALID_ARGUMENT;
    // }
    // select * / count(*)
    if (expr.attr->node.attribute_name == "*" && expr.attr->node.relation_name.empty()) {
      if ((depth == 0 && expr.attr->aggType == A_UNDEFINED)) {
        if (!expr.alias.empty()) {
          LOG_WARN("select * cannot have alias !!!");
          return RC::INVALID_ARGUMENT;
        }
        expr.attrType = INTS;
        return RC::SUCCESS;
      } else if (expr.attr->aggType == A_COUNT) {
        expr.attrType = INTS;
        Table *table = tables[0];
        expr.table_ = table;
        expr.field_ = table->table_meta().trx_field();
        expr.attr->node.relation_name = default_name;
        // if (expr->attr->alias != nullptr) {
        //   expr->field->set_alias(expr->attr->alias);
        // }
        return RC::SUCCESS;
      } else {
        LOG_WARN("agg(*) expcept count is not supported.");
        return RC::INVALID_ARGUMENT;
      }
    }
    Table * table;
    const char *table_alias;
    if (!expr.attr->node.relation_name.empty()) {
      auto iter = tables_map.find(expr.attr->node.relation_name);
      if (iter == tables_map.end()) {
        LOG_WARN("no such table in from list: %s", expr.attr->node.relation_name);
        return RC::SCHEMA_FIELD_MISSING;
      }
      table = iter->second;
      // table_alias = expr->attr->relation_name;
    } else {
      if (tables.size() != 1) {
        LOG_WARN("invalid. I do not know the attr's table. table=%s", expr.attr->node.relation_name.c_str());
        return RC::SCHEMA_FIELD_MISSING;
      }

      table = tables[0];
      expr.attr->node.relation_name = default_name;
      // if (table->name() != expr.attr->node.relation_name) {
      //   LOG_WARN("invalid. I do not know the attr's table. table=%s", expr.attr->node.relation_name.c_str());
      //   return RC::SCHEMA_FIELD_MISSING;
      // }
      // table_alias = (*tables)[0].alias;
    }
    if (expr.attr->node.attribute_name == "*") {
      if (depth == 0 && expr.attr->aggType == A_UNDEFINED) {
        if (!expr.alias.empty()) {
          LOG_WARN("select t.* cannot have alias !!!");
          return RC::INVALID_ARGUMENT;
        }
        expr.attrType = INTS;
        return RC::SUCCESS;
      } else {
        LOG_WARN("agg(*.) is not valid.");
        return RC::INVALID_ARGUMENT;
      }
    }
    const FieldMeta *field_meta = table->table_meta().field(expr.attr->node.attribute_name.c_str());
    if (nullptr == field_meta) {
      LOG_WARN("no such field. field=%s.%s", table->name(), expr.attr->node.attribute_name.c_str());
      return RC::SCHEMA_FIELD_MISSING;
    }
    expr.table_ = table;
    expr.field_ = field_meta;
    // if (expr->attr->alias != nullptr) {
    //   expr->field->set_alias(expr->attr->alias);
    // }
    // expr->field->set_table_alias(table_alias);

    // check group by field
    if (group_fields != nullptr) {
      for (auto &field : *group_fields) {
        Field expr_field = Field(expr.table_, expr.field_);
        expr_field.set_table_alias(expr.attr->node.relation_name);
        if (check_field(expr_field, field)) {
          expr.aggregation_num += 1;
        }
      }
    }

    expr.attrType = expr.field_->type();
    LOG_INFO("set attrType: %d", expr.attrType);
    return RC::SUCCESS;
  }
  RC rc;
  if (expr.left != nullptr) {
    rc = check_select_expression_valid(*expr.left, depth+1, tables, default_name, tables_map);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    if (expr.func == nullptr && (expr.left->attrType == DATES || expr.left->attrType == CHARS || expr.left->attrType == TEXTS)) {
      LOG_WARN("the type %d in complex expression is not supported.", expr.left->attrType);
      return RC::INVALID_ARGUMENT;
    }
    expr.attr_num += expr.left->attr_num;
    expr.aggregation_num += expr.left->aggregation_num;
  }
  if (expr.right != nullptr) {
    rc = check_select_expression_valid(*expr.right, depth+1, tables, default_name, tables_map);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    if (expr.right->attrType == DATES || expr.right->attrType == CHARS || expr.right->attrType == TEXTS) {
      LOG_WARN("the type %d in complex expression is not supported.", expr.right->attrType);
      return RC::INVALID_ARGUMENT;
    }

    expr.attr_num += expr.right->attr_num;
    expr.aggregation_num += expr.right->aggregation_num;
  }
  if (expr.func != nullptr) {
    switch (expr.func->funcType) {
      case F_LENGTH: {
        if (expr.left->attrType != CHARS) {
          LOG_INFO("The type %d doesn't match FUNC_LENGTH", expr.left->type);
          return RC::INVALID_ARGUMENT;
        }
        expr.attrType = INTS;
      } break;
      case F_ROUND: {
        if (expr.left->attrType != FLOATS) {
          LOG_INFO("The type %d doesn't match FUNC_ROUND", expr.left->type);
          return RC::INVALID_ARGUMENT;
        }
        expr.attrType = FLOATS;
      } break;
      case F_FORMAT: {
        if (expr.left->attrType != DATES) {
          LOG_INFO("The type %d doesn't match FUNC_FORMAT", expr.left->type);
          return RC::INVALID_ARGUMENT;
        }
        expr.attrType = CHARS;
      } break;
      default: {
        if (expr.left->attrType != CHARS) {
          return RC::INVALID_ARGUMENT;
        }
      } break;
    }
  } else {
    expr.attrType = FLOATS;
  }
  // expr.attrType = FLOATS;
  return RC::SUCCESS;
}

static void wildcard_fields(Table *table, std::string alias, std::vector<ExprSqlNode> &expressions)
{
  LOG_INFO("wildcard_fields");
  const TableMeta &table_meta = table->table_meta();
  const int field_num = table_meta.field_num();
  for (int i = table_meta.sys_field_num(); i < field_num; i++) {
    // special
    ExprSqlNode expr;
    memset(&expr, 0, sizeof(ExprSqlNode));
    expr.table_ = table;
    expr.field_ = table_meta.field(i);
    expr.attr = std::unique_ptr<DynNodeSqlNode>(new DynNodeSqlNode());
    expr.attr->node.attribute_name = expr.field_->name();
    expr.attr->node.relation_name = alias;
    // if (table.alias != nullptr) {
    //   expr.field->set_table_alias(table.alias);
    // }
    expr.type = E_DYN;
    expressions.push_back(std::move(expr));
  }
}

RC append_select_expression_with_star(std::vector<Table *> tables, std::vector<std::string> table_alias,
      std::unordered_map<std::string, Table *> &tables_map, ExprSqlNode &expr, std::vector<ExprSqlNode> &expressions)
{
  // TODO: The only star currently
  if (expr.type == E_DYN && expr.attr->node.attribute_name == "*" && expr.attr->aggType == A_UNDEFINED) {
    if (expr.attr->node.relation_name.length() == 0) {
      for (int i = 0; i < tables.size(); i++) {
        wildcard_fields(tables[i],table_alias[i], expressions);
      }
    } else {
      Table *table = tables_map.find(expr.attr->node.relation_name)->second;
      // TableInfo info{table, expr->attr->relation_name};
      wildcard_fields(table, expr.attr->node.relation_name, expressions);
    }
  } else {
    expressions.push_back(std::move(expr));
  }
  return RC::SUCCESS;
}

Expression* generate_expression(ExprSqlNode &expr)
{
    if (expr.type == E_VAL) {
      return new ValueExpr(*expr.value);
    }

    // TODO: AGG
    if (expr.type == E_DYN) {
      if (expr.attr != nullptr && expr.attr->aggType != A_UNDEFINED) {
        Field field = Field(expr.table_, expr.field_);
        if (!expr.attr->node.relation_name.empty()) {
          field.set_table_alias(expr.attr->node.relation_name);
        } else {
          field.set_table_alias(expr.table_->name());
        }
        return new AggregationExpr(expr.attr->aggType, field);
      } else {
        Field field = Field(expr.table_, expr.field_);
        if (!expr.attr->node.relation_name.empty()) {
          field.set_table_alias(expr.attr->node.relation_name);
        } else {
          field.set_table_alias(expr.table_->name());
        }
        return new FieldExpr(field);
      } 
    }

    std::unique_ptr<Expression> left, right;
    if (expr.left != nullptr) {
        left.reset(generate_expression(*expr.left));
    }

    if (expr.right != nullptr) {
        right.reset(generate_expression(*expr.right));
    }

    if (expr.type == E_FUNCTION || expr.func != nullptr) {
      return new ArithmeticExpr(expr.func->funcType, std::move(left), expr.func->format, expr.func->round_number);
    }

    return new ArithmeticExpr(ArithmeticExpr::Type(expr.type), std::move(left), std::move(right));
}

std::string generate_alias(bool multi_tables, ExprSqlNode &expr, std::unordered_map<std::string, std::string> &alias_map)
{
  std::string str;
  if (!expr.alias.empty()) {
    str += expr.alias;
    return str;
  }
  if (expr.has_brace) {
    str += '(';
  }
  if (expr.type == E_VAL) {
    str += expr.value->to_string();
  } else if (expr.type == E_DYN) {
    if (!expr.alias.empty()) {
      str += expr.alias;
    } else {
      AggregationType aggType = expr.attr == nullptr ? A_UNDEFINED: expr.attr->aggType;
      switch(aggType) {
        case A_AVG:
          str += "AVG(";
          break;
        case A_COUNT:
          str += "COUNT(";
          break;
        case A_MAX:
          str += "MAX(";
          break;
        case A_MIN:
          str += "MIN(";
          break;
        case A_SUM:
          str += "SUM(";
          break;
        default:
          break;
      }
      if ( expr.field_ == nullptr || expr.table_ == nullptr) {
        return std::string();
      }
      if (expr.attr != nullptr && expr.attr->node.attribute_name == "*") {
        str += "*";
      } else if (multi_tables) {
        // 一定访问的到
        str += expr.attr->node.relation_name;
        str += '.';
        str += expr.field_->name();
      } else {
        str += expr.field_->name();
      }
      if (aggType != A_UNDEFINED) {
        str += ")";
      }
    }
  } else {
   if (expr.func != nullptr) {
      if (!expr.alias.empty()) {
        str += expr.alias;
      } else {
        std::string left_str = generate_alias(multi_tables, *expr.left, alias_map);
        switch (expr.func->funcType) {
          case F_LENGTH: {
            str += "length(" + left_str + ")";
          } break;
          case F_ROUND: {
            str += "round(" + left_str;
            if (expr.func->round_has) {
              str += "," + std::to_string(expr.func->round_number);
            }
            str += ")";
          } break;
          case F_FORMAT: {
            str += "data_format(" + left_str  + ",";
            str += (expr.func->format);
            str += ")";
          } break;
          default:
            break;
        }
        return str;
      }
    } else {
      std::string left_str;
      std::string right_str;
      if (expr.left != nullptr) {
        left_str = generate_alias(multi_tables, *expr.left, alias_map);
      }
      if (expr.right != nullptr) {
        right_str = generate_alias(multi_tables, *expr.right, alias_map);
      }
      switch (expr.type) {
        case E_ADD: {
          str += left_str + "+" + right_str;
        } break;
        case E_SUB: {
          str += left_str + "-" + right_str;
        } break;
        case E_MUL: {
          str += left_str + "*" + right_str;
        } break;
        case E_DIV: {
          str += left_str + "/" + right_str;
        } break;
        case E_NEGATIVE: {
          str += "-" + right_str;
        } break;
        default:
          break;
      }
    }
  }
  if (expr.has_brace) {
    str += ')';
  }
  return str;
}