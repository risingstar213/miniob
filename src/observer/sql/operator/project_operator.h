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

#pragma once

#include <vector>
#include "sql/operator/operator.h"
#include "sql/operator/group_operator.h"
#include "rc.h"

class ProjectOperator : public Operator
{
public:
  ProjectOperator()
  {}

  ~ProjectOperator() {
    if (child_ != nullptr) {
      delete child_;
    }
  };

  void add_projection(bool multi_tables, SelectExpr *expr, bool is_aggregation);

  RC open() override;
  RC next(std::vector<Tuple *> *context = nullptr) override;
  RC close() override;

  int tuple_cell_num() const
  {
    return tuple_.cell_num();
  }

  RC tuple_cell_spec_at(int index, const TupleCellSpec *&spec) const;

  std::vector<Tuple *> current_tuples() override;

  void add_child(GroupOperator *oper) {
    child_ = oper;
  }
private:
  ProjectTuple tuple_;
  bool is_group_ = false;
  bool has_run_;
  // std::vector<Tuple> tuples_;
  GroupOperator *child_ = nullptr;
  bool ended_;
};
