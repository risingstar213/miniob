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
// Created by Wangyunlai on 2022/6/5.
//

#pragma once

#include <vector>
#include <memory>

#include "common/rc.h"
#include "sql/stmt/stmt.h"
#include "sql/expr/expression.h"

#include "sql/utils/expression_helpers.h"

class Db;
class Table;

/**
 * @brief 描述算术运算语句
 * @ingroup Statement
 */
class CalcStmt : public Stmt 
{
public:
  CalcStmt() = default;
  virtual ~CalcStmt() override = default;

  StmtType type() const override
  {
    return StmtType::CALC;
  }

public:
  static RC create(CalcSqlNode &calc_sql, Stmt *&stmt)
  {
    CalcStmt *calc_stmt = new CalcStmt();
    for (auto & expr : calc_sql.expressions) {
      std::vector<Table *> empty_tables;
      std::unordered_map<std::string, Table *> empty_tables_map;

      RC rc = check_select_expression_valid(expr, 0, empty_tables, "",empty_tables_map);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      calc_stmt->expressions_.emplace_back(generate_expression(expr));
      std::unordered_map<std::string, std::string> empty_alias_map;
      calc_stmt->alias_.emplace_back(generate_alias(false, expr, empty_alias_map));
    }
    calc_stmt->is_select_ = calc_sql.is_select;
    calc_sql.expressions.clear();
    stmt = calc_stmt;
    return RC::SUCCESS;
  }

public:
  std::vector<std::unique_ptr<Expression>> &expressions()
  {
    return expressions_;
  }

  std::vector<std::string> &alias()
  {
    return alias_;
  }

  bool is_select()
  {
    return is_select_;
  }

private:
  std::vector<std::unique_ptr<Expression>> expressions_;
  std::vector<std::string>                 alias_;
  bool is_select_;
};
