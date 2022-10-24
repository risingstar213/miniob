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
// Created by WangYunlai on 2021/6/10.
//

#pragma once

#include "sql/parser/parse.h"
#include "sql/operator/operator.h"
#include "rc.h"

// TODO fixme
class JoinOperator : public Operator
{
public:
  JoinOperator(Operator *left, Operator *right) : left_(left), right_(right)
  {}

  virtual ~JoinOperator() = default;

  RC open() override;
  RC next() override;
  RC close() override;

  std::vector<Tuple *> current_tuples() override;
private:
  // filter / scan
  Operator *left_;
  // scan
  Operator *right_;
  bool start_ = true;
  bool stop_ = true;
  RC rc_;
};
