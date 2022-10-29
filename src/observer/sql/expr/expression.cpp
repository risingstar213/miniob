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
// Created by Wangyunlai on 2022/07/05.
//

#include "sql/expr/tuple.h"


RC FieldExpr::get_value(const std::vector<Tuple *> tuples, TupleCell &cell) const
{
  if (agg_ ==AGG_NONE) {
    for (uint i = 0; i < tuples.size(); i++) {
      if (tuples[i]->find_cell(field_, cell) == RC::SUCCESS) {
        return RC::SUCCESS;
      }
    }
  } else {
    cell.set_data(AggFunc::get_data(agg_, data_, field_.attr_type()));
    cell.set_type(AggFunc::get_attrtype(agg_, field_.attr_type()));
    if (cell.attr_type() == CHARS || cell.attr_type() == TEXTS) {
        cell.set_length(cell_.length());
    } else {
      cell.set_length(4);
    }
    return RC::SUCCESS;
  }
  return RC::NOTFOUND;
}

void FieldExpr::update_value(const std::vector<Tuple *> tuples)
{
  for (uint i = 0; i < tuples.size(); i++) {
    if (tuples[i]->find_cell(field_, cell_) == RC::SUCCESS) {
      break;
    }
  }
  if (agg_ != AGG_NONE) {
    AggFunc::add_data(agg_, data_, cell_.attr_type(), (char *)cell_.data(), cell_.length());
  }
}

RC ValueExpr::get_value(const std::vector<Tuple *> tuples, TupleCell & cell) const
{
  cell = tuple_cell_;
  return RC::SUCCESS;
}
