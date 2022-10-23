#include "sql/operator/update_operator.h"
#include "sql/stmt/update_stmt.h"
#include "storage/common/table.h"
#include "common/log/log.h"
#include "rc.h"

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
    int offset = update_stmt_->table()->table_meta().field_index(update_stmt_->field_name());
    values[offset] = update_stmt_->values()[0];
    // LOG_INFO("offset: %d", update_stmt_->field().meta()->offset());
    Record &old_record = row_tuple->record();
    rc = table->update_record(trx_, &old_record, row_tuple->cell_num(), values);
    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to delete record: %s", strrc(rc));
      return rc;
    }
    delete (values);
  }
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