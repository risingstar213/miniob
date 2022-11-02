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
// Created by WangYunlai on 2022/07/01.
//

#include "sql/parser/parse_defs.h"
#include "common/log/log.h"
#include "sql/operator/project_operator.h"
#include "storage/record/record.h"
#include "storage/common/table.h"
#include "storage/trx/trx.h"
#include "util/cast.h"
#include "util/expression_helpers.h"
#include <algorithm>

RC ProjectOperator::open()
{
  // if (children_.size() != 1) {
  //   LOG_WARN("project operator must has 1 child");
  //   return RC::INTERNAL;
  // }

  // Operator *child = children_[0];
  // RC rc = child->open();
  // if (rc != RC::SUCCESS) {
  //   LOG_WARN("failed to open child operator: %s", strrc(rc));
  //   return rc;
  // }

  // tuple_.reset_tuples();
  // has_run_ = false;
  // return RC::SUCCESS;
  RC rc = child_->open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  tuple_.reset_tuples();
  has_run_ = false;
  return RC::SUCCESS;
}

RC ProjectOperator::next(std::vector<Tuple *> *context)
{
  // if (!is_aggregation_) {
  //   RC rc =  children_[0]->next(context);
  //   if (rc == RC::SUCCESS) {
  //     tuple_.set_tuples(children_[0]->current_tuples());
  //   }
  //   return rc;
  // } else {
  //   // bool start = true;
  //   if (has_run_) {
  //     return RC::RECORD_EOF;
  //   }
  //   RC rc;
  //   while ((rc = children_[0]->next(context)) == RC::SUCCESS) {
  //     tuple_.set_tuples(children_[0]->current_tuples());
  //     // start = false;
  //   }
  //   if (rc != RC::RECORD_EOF) {
  //     return rc;
  //   }
  //   has_run_ = true;
  //   return RC::SUCCESS;
  // }
  RC rc;
  if (is_group_) {
    tuple_.reset_tuples();
  }
  while ((rc = child_->next(context)) == RC::SUCCESS) {
    if (child_->data_valid()) {
      tuple_.set_tuples(child_->current_tuples());
    }
    if (child_->group_complete()) {
      if (child_->group_valid()) {
        break;
      } else {
        tuple_.reset_tuples();
      }
    }
  }
  return rc;
}

RC ProjectOperator::close()
{
  // children_[0]->close();
  child_->close();
  return RC::SUCCESS;
}
std::vector<Tuple *> ProjectOperator::current_tuples()
{
  std::vector<Tuple *> tuples;
  tuples.push_back(&tuple_);
  return tuples;
}

void ProjectOperator::add_projection(bool multi_tables, SelectExpr *expr, bool is_group)
{
  // 对单表来说，展示的(alias) 字段总是字段名称，
  // 对多表查询来说，展示的alias 需要带表名字
  // LOG_INFO("add projection:%s agg:%d", field_meta->name(), agg);
  TupleCellSpec *spec = new TupleCellSpec(generate_expression(expr));
  spec->set_alias(generate_alias(multi_tables, expr));
  is_group_ = is_group;
  tuple_.add_cell_spec(spec);
}

RC ProjectOperator::tuple_cell_spec_at(int index, const TupleCellSpec *&spec) const
{
  return tuple_.cell_spec_at(index, spec);
}
