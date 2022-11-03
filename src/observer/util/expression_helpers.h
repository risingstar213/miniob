#ifndef _EXPRESSION_HELPERS_H_
#define _EXPRESSION_HELPERS_H_
#include <unordered_map>
#include <string>

#include "rc.h"
#include "sql/parser/parse_defs.h"
#include "sql/expr/expression.h"


class Table;

RC check_select_expression_valid(SelectExpr *expr, int depth, std::vector<TableInfo> *tables, 
          std::unordered_map<std::string, Table *> *tables_map, std::vector<Field> *group_fields = nullptr);

RC append_select_expression_with_star(std::vector<TableInfo> tables, SelectExpr *expr, std::vector<SelectExpr> &expressions);

Expression *generate_expression(SelectExpr *expr);

std::string generate_alias(bool multi_tables, SelectExpr *expr);

#endif