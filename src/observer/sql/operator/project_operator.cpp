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

#include "common/log/log.h"
#include "sql/operator/project_operator.h"
#include "storage/record/record.h"
#include "storage/common/table.h"
#include "storage/trx/trx.h"
#include "util/cast.h"
#include "algorithm"

RC ProjectOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("project operator must has 1 child");
    return RC::INTERNAL;
  }

  Operator *child = children_[0];
  RC rc = child->open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  return RC::SUCCESS;
}

RC ProjectOperator::next()
{
  if (agg_[0] == AGG_NONE) {
    return children_[0]->next();
  } else {
    int n = tuples_.size();
    std::vector<float> temp1(n,0);
    std::vector<float> temp2(n,0);
    std::vector<char*> temp3(n);
    for (int i = 0; i < n; i++) {
      if (agg_[i] == AGG_MIN) {
        temp1[i] = __FLT_MAX__;
      } else if (agg_[i] == AGG_MAX) {
        temp1[i] = __FLT_MIN__;
      }
    }
    while (children_[0]->next() == RC::SUCCESS) {
      Tuple* tuple = children_[0]->current_tuples()[0];
      for (int i = 0; i < n; i++) {
        TupleCell cell;
        Tuple* tuple = children_[0]->current_tuples()[0];
        tuple->cell_at(i, cell);
        AttrType type = cell.attr_type();

        switch(agg_[i]) {
          case AGG_COUNT:
            temp1[i]++;
            break;
          case AGG_MIN:
            if (type == CHARS) {
              if (temp3[i] == "") {
                temp3[i] = (char *)cell.data();
              } else {
                temp3[i] = strcmp(temp3[i], (char *)cell.data()) > 0 ? (char *)cell.data() : temp3[i];
              }
            } else {
              temp1[i] = std::min(*(float *)cell.data(), temp1[i]);
            }
            break;
          case AGG_MAX:
            if (type == CHARS) {
              if (temp3[i] == "") {
                temp3[i] = (char *)cell.data();
              } else {
                temp3[i] = strcmp(temp3[i], (char *)cell.data()) < 0 ? (char *)cell.data() : temp3[i];
              }
            } else {
              temp1[i] = std::max(*(float *)cell.data(), temp1[i]);
            }
            break;
          case AGG_SUM:
            if (type == CHARS) {
              LOG_INFO("sum of strings");
              return RC::INVALID_ARGUMENT;
            } else {
              temp1[i] += *(float *)cell.data();
            }
            break;
          case AGG_AVG: 
            temp1[i]++;
            if (type == CHARS) {
              temp2[i] += CastUnit::cast_string_to_float(const_cast<char *>(cell.data()), 0);
            } else {
              temp2[i] += *(float *)cell.data();
            }
            break;
          default:
            LOG_INFO("wrong aggregation");
            return RC::INVALID_ARGUMENT;
        }
      }
    }
    
  }
}

RC ProjectOperator::close()
{
  children_[0]->close();
  return RC::SUCCESS;
}
std::vector<Tuple *> ProjectOperator::current_tuples()
{
  LOG_INFO("Project: current_tuples");
  tuple_.set_tuples(children_[0]->current_tuples());
  std::vector<Tuple *> tuples;
  tuples.push_back(&tuple_);
  return tuples;
}

void ProjectOperator::add_projection(bool multi_tables, const Table *table, const FieldMeta *field_meta, const Aggregation agg)
{
  // 对单表来说，展示的(alias) 字段总是字段名称，
  // 对多表查询来说，展示的alias 需要带表名字
  TupleCellSpec *spec = new TupleCellSpec(new FieldExpr(table, field_meta));
  if (multi_tables) {
    std::string str;
    str = table->name();
    str += '.';
    str += field_meta->name();
    spec->set_alias(str);
  } else if (agg == AGG_NONE) {
    spec->set_alias(field_meta->name());
  } else {
    std::string str;
    switch(agg) {
      case AGG_AVG:
        str += "AVG(";
        break;
      case AGG_COUNT:
        str += "COUNT(";
        break;
      case AGG_MAX:
        str += "MAX(";
        break;
      case AGG_MIN:
        str += "MIN(";
        break;
      case AGG_SUM:
        str += "SUM(";
        break;
      default:
        break;
    }
    if (field_meta->name() == Trx::trx_field_name()) {
      str += "*";
    } else {
      str += field_meta->name();
    }
    str += ")";
    spec->set_alias(str);
  }
  tuple_.add_cell_spec(spec);
  agg_.push_back(agg);
}

RC ProjectOperator::tuple_cell_spec_at(int index, const TupleCellSpec *&spec) const
{
  return tuple_.cell_spec_at(index, spec);
}
