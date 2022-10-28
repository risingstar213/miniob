#include "sql/operator/update_operator.h"
#include "sql/stmt/update_stmt.h"
#include "storage/common/table.h"
#include "common/log/log.h"
#include "rc.h"
#include "util/operator_helper.h"
#include "util/cast.h"

RC UpdateOperator::open()
{
  if (children_.size() != 1) {
    LOG_WARN("update operator must has 1 child");
    return RC::INTERNAL;
  }

  Operator *child = children_[0];
  RC rc = child->open();
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  auto update_values = update_stmt_->values();
  std::vector<Operator *> operator_queue;
  std::vector<Value> true_values;
  for (size_t i = 0; i < update_values.size(); i++) {
    AttrType type = update_stmt_->table()->table_meta().field(update_stmt_->field_name()[i])->type();
    if (update_values[i].is_select) {
      Operator *oper = get_select_operator(update_values[i].value.select);
      operator_queue.push_back(oper);
      TupleCell cell;
      int count = 0;
      if ((rc = oper->open()) != RC::SUCCESS) {
        for (auto &oper : operator_queue) delete oper;
        return rc;
      }
      while (oper->next() == RC::SUCCESS) {
        count += 1;
        oper->current_tuples()[0]->cell_at(0, cell);
      }
      if (count != 1) {
        for (auto &oper : operator_queue) delete oper;
        return RC::INVALID_ARGUMENT;
      }
      Value value;
      value.data = const_cast<char *>(cell.data());
      value.type = cell.attr_type();
      CastUnit::cast_to_with_new_alloc(value, type);
      true_values.push_back(value);
    } else {
      Value value = update_values[i].value.value;
      CastUnit::cast_to_with_new_alloc(value, type);
      true_values.push_back(value);
    }
  }

  Table *table = update_stmt_->table();
  while (RC::SUCCESS == (rc = child->next())) {
    Tuple *tuple = child->current_tuples()[0];
    if (nullptr == tuple) {
      LOG_WARN("failed to get current record: %s", strrc(rc));
      return rc;
    }

    RowTuple *row_tuple = static_cast<RowTuple *>(tuple);
    TupleCell cell;
    Value *values = new Value[row_tuple->cell_num()];
    for (int i = 0; i < row_tuple->cell_num(); i++) {
      row_tuple->cell_at(i, cell);
      values[i].type = cell.attr_type();
      values[i].data = (void *)cell.data();
    }

    for (size_t i = 0; i < update_stmt_->field_name().size(); i++) {
      int offset = update_stmt_->table()->table_meta().field_index(update_stmt_->field_name()[i]);
      values[offset] = true_values[i];
    }
    // LOG_INFO("offset: %d", update_stmt_->field().meta()->offset());
    Record &old_record = row_tuple->record();
    rc = table->update_record(trx_, &old_record, row_tuple->cell_num(), values);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to delete record: %s", strrc(rc));
      return rc;
    }
    delete (values);
  }
  for (auto &oper : operator_queue) delete oper;
  return RC::SUCCESS;
}

RC UpdateOperator::next()
{
  return RC::RECORD_EOF;
}

RC UpdateOperator::close()
{
  return RC::SUCCESS;
}