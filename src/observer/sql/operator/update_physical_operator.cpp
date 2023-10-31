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
// Created by WangYunlai on 2021/6/9.
//

#include "sql/operator/update_physical_operator.h"
#include "sql/stmt/insert_stmt.h"
#include "storage/table/table.h"
#include "storage/trx/trx.h"

using namespace std;

UpdatePhysicalOperator::UpdatePhysicalOperator(Table *table, 
    std::vector<const FieldMeta *> &fields,
    std::vector<std::unique_ptr<Expression>> &exprs)
    : table_(table)
{
  fields_.swap(fields);
  exprs_.swap(exprs);
}

RC UpdatePhysicalOperator::open(Trx *trx)
{
  if (children_.empty()) {
    return RC::SUCCESS;
  }

  std::unique_ptr<PhysicalOperator> &child = children_[0];
  RC rc = child->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  trx_ = trx;

  return RC::SUCCESS;
}

int UpdatePhysicalOperator::find_index_in_tuple(const FieldMeta* field)
{
  int field_num = table_->table_meta().field_num();
  for (int i = 0; i < field_num; i++) {
    if (table_->table_meta().field(i)->name() == field->name()) {
      return i;
    }
  }
  return 0;
}

RC UpdatePhysicalOperator::next()
{
  RC rc = RC::SUCCESS;
  if (children_.empty()) {
    return RC::RECORD_EOF;
  }

  PhysicalOperator *child = children_[0].get();
  while (RC::SUCCESS == (rc = child->next())) {
    Tuple *tuple = child->current_tuple();
    if (nullptr == tuple) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }

    RowTuple *row_tuple = static_cast<RowTuple *>(tuple);

    std::vector<Value> new_values;
    int field_num = table_->table_meta().field_num();
    for (int i = 0; i < field_num; i++) {
      Value temp;
      row_tuple->cell_at(i, temp);
      new_values.emplace_back(temp);
    }

    for (int i = 0; i < fields_.size(); i++) {
      int index = find_index_in_tuple(fields_[i]);
      Value temp;
      exprs_[i]->get_value(*tuple, temp, trx_);
      if (temp.attr_type() != fields_[i]->type()) {
        LOG_WARN("update type is not valid!");
        return RC::INTERNAL;
      }
      new_values[index] = temp;
    }

    Record &record = row_tuple->record();
    rc = trx_->delete_record(table_, record);

    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to delete record in update: %s", strrc(rc));
      return rc;
    }

    for (int i = 0; i < field_num; i++) {
      LOG_INFO("update %d to %s", i, new_values[i].to_string());
    }

    Record new_record;
    table_->make_record(static_cast<int>(new_values.size()), new_values.data(), new_record);

    rc = trx_->insert_record(table_, new_record);

    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to index record in update: %s", strrc(rc));
      return rc;
    }

    // (TODO): generate update row here, using exprs

    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to update record: %s", strrc(rc));
      return rc;
    }
  }

  return RC::RECORD_EOF;
}

RC UpdatePhysicalOperator::close()
{
  if (!children_.empty()) {
    children_[0]->close();
  }
  return RC::SUCCESS;
}
