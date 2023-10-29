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
// Created by WangYunlai on 2023/4/25.
//

#pragma once

#include <vector>

#include "sql/operator/logical_operator.h"
#include "sql/parser/parse_defs.h"

/**
 * @brief 插入逻辑算子
 * @ingroup LogicalOperator
 */
class UpdateLogicalOperator : public LogicalOperator
{
public:
  UpdateLogicalOperator(
    Table *table, 
    std::vector<const FieldMeta *> &fields,
    std::vector<Expression *> &exprs);
  virtual ~UpdateLogicalOperator() = default;

  LogicalOperatorType type() const override
  {
    return LogicalOperatorType::UPDATE;
  }

  Table *table() const { return table_; }
  const std::vector<const FieldMeta *> &fields() const { return fields_; }
  std::vector<const FieldMeta *> &fields() { return fields_; }
  const std::vector<std::unique_ptr<Expression>> &exprs() const { return exprs_; }
  std::vector<std::unique_ptr<Expression>> &exprs() { return exprs_; }

private:
  Table *table_ = nullptr;
  std::vector<const FieldMeta*> fields_;
  std::vector<std::unique_ptr<Expression>> exprs_;
};