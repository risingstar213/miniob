#ifndef _EXPRESSION_HELPERS_H_
#define _EXPRESSION_HELPERS_H_
#include <unordered_map>
#include <string>

#include "common/log/log.h"
#include "sql/parser/parse_defs.h"
#include "sql/expr/expression.h"


RC check_select_expression_valid(ExprSqlNode &expr, int depth, std::vector<Table *> &tables, 
          std::unordered_map<std::string, Table *> &tables_map);

RC append_select_expression_with_star(std::vector<Table *> tables, 
            std::unordered_map<std::string, Table *> &tables_map, ExprSqlNode &expr, std::vector<ExprSqlNode> &expressions);

Expression* generate_expression(ExprSqlNode &expr);

std::string generate_alias(bool multi_tables, ExprSqlNode *expr);

#endif