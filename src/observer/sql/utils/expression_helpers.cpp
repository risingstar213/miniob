#include <memory>

#include "sql/utils/expression_helpers.h"

#include "storage/trx/trx.h"
#include "common/log/log.h"
#include "common/lang/string.h"


static bool check_field(Field &rel_field, Field &target_field)
{
  if (strcmp(rel_field.table_name(), target_field.table_name()) == 0) {
    if (strcmp(rel_field.field_name(), target_field.field_name()) == 0) {
      return true;
    }
  }
  return false;
}


RC check_select_expression_valid(ExprSqlNode &expr, int depth, std::vector<Table *> &tables, 
          std::unordered_map<std::string, Table *> &tables_map)
{
  if (expr.type == E_VAL) {
    expr.attrType = expr.value->attr_type();
    // if (expr->value->type == DATES) {
    //   Date *d = (Date *)expr->value->data;
    //   if (!d->is_valid()) {
    //     LOG_WARN("The date %s is not valid", d->toString().c_str());
    //     return RC::SQL_SYNTAX;
    //   }
    // }
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
    if (expr.attr->node.attribute_name == "*") {
      if ((depth == 0 && expr.attr->aggType == A_UNDEFINED)) {
        // if (expr->attr->alias != nullptr) {
        //   LOG_WARN("select * cannot have alias !!!");
        //   return RC::INVALID_ARGUMENT;
        // }
        expr.attrType = INTS;
        return RC::SUCCESS;
      } else if (expr.attr->aggType == A_COUNT) {
        expr.attrType = INTS;
        Table *table = tables[0];
        expr.table_ = table;
        expr.field_ = table->table_meta().trx_field();
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
    if (expr.attr->node.relation_name.length() > 0) {
      auto iter = tables_map.find(expr.attr->node.relation_name);
      if (iter == tables_map.end()) {
        LOG_WARN("no such table in from list: %s", expr.attr->node.relation_name);
        return RC::SCHEMA_FIELD_MISSING;
      }
      table = iter->second;
      // table_alias = expr->attr->relation_name;
    } else {
      if (tables.size() != 1) {
        LOG_WARN("invalid. I do not know the attr's table. attr=%s", expr.attr->node.relation_name.c_str());
        return RC::SCHEMA_FIELD_MISSING;
      }

      table = tables[0];
      // table_alias = (*tables)[0].alias;
    }
    if (expr.attr->node.attribute_name == "*") {
      if (depth == 0 && expr.attr->aggType == A_UNDEFINED) {
        // if (expr->attr->alias != nullptr) {
        //   LOG_WARN("select t.* cannot have alias !!!");
        //   return RC::INVALID_ARGUMENT;
        // }
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
    // if (group_fields != nullptr) {
    //   for (auto &field : *group_fields) {
    //     if (check_field(*expr->field, field)) {
    //       expr->aggregation_num += 1;
    //     }
    //   }
    // }

    expr.attrType = expr.field_->type();
    LOG_INFO("set attrType: %d", expr.attrType);
    return RC::SUCCESS;
  }
  RC rc;
  if (expr.left != nullptr) {
    rc = check_select_expression_valid(*expr.left, depth+1, tables, tables_map);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    if (expr.left->attrType == DATES || expr.left->type == CHARS || expr.left->type == TEXTS) {
      LOG_WARN("the type %d in complex expression is not supported.", expr.left->type);
      return RC::INVALID_ARGUMENT;
    }
    expr.attr_num += expr.left->attr_num;
    expr.aggregation_num += expr.left->aggregation_num;
  }
  rc = check_select_expression_valid(*expr.right, depth+1, tables, tables_map);
  if (rc != RC::SUCCESS) {
    return rc;
  }
//   if (expr->function == nullptr && (expr->right->type == DATES || expr->right->type == CHARS || expr->right->type == TEXTS)) {
//       LOG_WARN("the type %d in complex expression is not supported.", expr->right->type);
//       return RC::INVALID_ARGUMENT;
//   }
  expr.attr_num += expr.right->attr_num;
  expr.aggregation_num += expr.right->aggregation_num;
//   if (expr->function != nullptr) {
//     switch (expr->function->op) {
//       case FUNC_LENGTH: {
//         if (expr->right->type != CHARS) {
//           LOG_INFO("The type %d doesn't match FUNC_LENGTH", expr->right->type);
//           return RC::INVALID_ARGUMENT;
//         }
//         expr->type = INTS;
//       } break;
//       case FUNC_ROUND: {
//         if (expr->right->type != FLOATS) {
//           LOG_INFO("The type %d doesn't match FUNC_ROUND", expr->right->type);
//           return RC::INVALID_ARGUMENT;
//         }
//         expr->type = FLOATS;
//       } break;
//       case FUNC_FORMAT: {
//         if (expr->right->type != DATES) {
//           LOG_INFO("The type %d doesn't match FUNC_FORMAT", expr->right->type);
//           return RC::INVALID_ARGUMENT;
//         }
//         expr->type = CHARS;
//       } break;
//       default: {
//         if (expr->right->type != CHARS) {
//           return RC::INVALID_ARGUMENT;
//         }
//       } break;
//     }
//   } else {
//     expr->type = FLOATS;
//   }
  expr.attrType = FLOATS;
  return RC::SUCCESS;
}

static void wildcard_fields(Table *table,  std::vector<ExprSqlNode> &expressions)
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
    // if (table.alias != nullptr) {
    //   expr.field->set_table_alias(table.alias);
    // }
    expr.type = E_DYN;
    expressions.push_back(std::move(expr));
  }
}

RC append_select_expression_with_star(std::vector<Table *> tables, 
      std::unordered_map<std::string, Table *> &tables_map, ExprSqlNode &expr, std::vector<ExprSqlNode> &expressions)
{
  // TODO: The only star currently
  if (expr.type == E_DYN && expr.attr->node.attribute_name == "*" && expr.attr->aggType == A_UNDEFINED) {
    if (expr.attr->node.relation_name.length() == 0) {
      for (auto &table_info : tables) {
        wildcard_fields(table_info, expressions);
      }
    } else {
      Table *table = tables_map.find(expr.attr->node.relation_name)->second;
      // TableInfo info{table, expr->attr->relation_name};
      wildcard_fields(table, expressions);
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
      if (expr.attr->aggType != UNDEFINED) {
        return new AggregationExpr(expr.attr->aggType, Field(expr.table_, expr.field_));
      } else {
        return new FieldExpr(Field(expr.table_, expr.field_));
      } 
    }

    std::unique_ptr<Expression> left, right;
    if (expr.left != nullptr) {
        left.reset(generate_expression(*expr.left));
    }

    if (expr.right != nullptr) {
        right.reset(generate_expression(*expr.right));
    }

    return new ArithmeticExpr(ArithmeticExpr::Type(expr.type), std::move(left), std::move(right));
}

std::string generate_alias(bool multi_tables, ExprSqlNode &expr)
{
  std::string str;
  if (expr.has_brace) {
    str += '(';
  }
  if (expr.type == E_VAL) {
    str += expr.value->to_string();
  } else if (expr.type == E_DYN) {
    // if (expr->field->get_alias() != nullptr) {
    //   str += expr->field->get_alias();
   //  } else {
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
      if (expr.field_ == expr.table_->table_meta().trx_field()) {
        str += "*";
      } else if (multi_tables) {
        str += expr.table_->name();
        str += '.';
        str += expr.field_->name();
      } else {
        str += expr.field_->name();
      }
      if (aggType != A_UNDEFINED) {
        str += ")";
      }
    // }
  } else {
//    if (expr->function != nullptr) {
    //   if (expr->alias != nullptr) {
    //     str += expr->alias;
    //   } else {
    //     std::string right_str = generate_alias(multi_tables, expr->right);
    //     switch (expr->function->op) {
    //       case FUNC_LENGTH: {
    //         str += "length(" + right_str + ")";
    //       } break;
    //       case FUNC_ROUND: {
    //         str += "round(" + right_str;
    //         if (expr->function->data != nullptr) {
    //           str += "," + std::to_string(*(int *)expr->function->data);
    //         }
    //         str += ")";
    //       } break;
    //       case FUNC_FORMAT: {
    //         str += "data_format(" + right_str + ",";
    //         str += (expr->function->data);
    //         str += ")";
    //       } break;
    //       default:
    //         break;
    //     }
    //     return str;
    //   }
    // } else {
      std::string left_str;
      std::string right_str;
      if (expr.left != nullptr) {
        left_str = generate_alias(multi_tables, *expr.left);
      }
      if (expr.right != nullptr) {
        right_str = generate_alias(multi_tables, *expr.right);
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
//    }
  }
  if (expr.has_brace) {
    str += ')';
  }
  return str;
}