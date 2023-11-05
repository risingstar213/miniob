#include "sql/operator/view_scan_physical_operator.h"
#include "storage/table/table.h"

// #include "sql/optimizer/logical_plan_generator.h"
// #include "sql/optimizer/physical_plan_generator.h"

#include "event/sql_debug.h"

ViewScanPhysicalOperator::ViewScanPhysicalOperator(Table *table, PhysicalOperator *view_operator)
  : table_(table), view_operator_(view_operator)
{
  if (view_operator_ == nullptr) {
    // std::unique_ptr<LogicalOperator> logical_oper;
    // LogicalPlanGenerator logical_generator;
    // logical_generator.create(view_stmt_, logical_oper);
    // PhysicalPlanGenerator physical_generator;
    // std::unique_ptr<PhysicalOperator> physical_oper;
    // physical_generator.create(*logical_oper, physical_oper);
    // view_operator_ = physical_oper.release();
    // table->set_view_operator(view_operator_);
  }
}

ViewScanPhysicalOperator::~ViewScanPhysicalOperator()
{
  // if (view_operator_ != nullptr) {
  //   delete view_operator_;
  //   view_operator_ = nullptr;
  // }
}

RC ViewScanPhysicalOperator::open(Trx *trx)
{
  // RC rc = table_->get_record_scanner(record_scanner_, trx, readonly_);
  RC rc = view_operator_->open(trx);
  if (rc == RC::SUCCESS) {
    tuple_.set_schema(table_, table_->table_meta().field_metas());
  }
  // LOG_INFO("TableScanPhysicalOperator : %d", tuple_.cell_num());
  trx_ = trx;
  table_->set_view_trx(trx);
  return rc;
}

RC ViewScanPhysicalOperator::next()
{
  // if (!record_scanner_.has_next()) {
  //   return RC::RECORD_EOF;
  // }

  // RC rc = RC::SUCCESS;
  // bool filter_result = false;
  // while (record_scanner_.has_next()) {
  //   rc = record_scanner_.next(current_record_);
  //   if (rc != RC::SUCCESS && rc != RC::LOCKED_CONCURRENCY_CONFLICT) {
  //     LOG_INFO("TableScanPhysicalOperator get error %s", strrc(rc));
  //     return rc;
  //   }

  //   tuple_.set_record(&current_record_);
  //   rc = filter(tuple_, filter_result);
  //   if (rc != RC::SUCCESS) {
  //     return rc;
  //   }

  //   if (filter_result) {
  //     // sql_debug("get a tuple: %s", tuple_.to_string().c_str());
  //     break;
  //   } else {
  //     // sql_debug("a tuple is filtered: %s", tuple_.to_string().c_str());
  //     rc = RC::RECORD_EOF;
  //   }
  // }

  RC rc = RC::SUCCESS;
  bool filter_result = false;
  while (RC::SUCCESS == (rc = view_operator_->next())) {
    Tuple *tuple = view_operator_->current_tuple();
    std::vector<Value> values;
    Value temp;
    for (int i = 0; i < tuple->cell_num(); i++) {
      rc = tuple->cell_at(i, temp);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      values.emplace_back(temp);
    }

    rc = table_->make_record(values.size(), values.data(), record_);
    if (rc != RC::SUCCESS) {
      LOG_INFO("view scan make record get error");
      return rc;
    }
    
    tuple_.set_record(&record_);
    rc = filter(tuple_, filter_result);
    if (rc != RC::SUCCESS) {
      return rc;
    }

    if (filter_result) {
      // sql_debug("get a tuple: %s", tuple_.to_string().c_str());
      break;
    } else {
      // sql_debug("a tuple is filtered: %s", tuple_.to_string().c_str());
      rc = RC::RECORD_EOF;
    }
  }
  return rc;
}

RC ViewScanPhysicalOperator::close()
{
  // return record_scanner_.close_scan();
  return view_operator_->close();
}

Tuple *ViewScanPhysicalOperator::current_tuple()
{
  // tuple_.set_record(&current_record_);
  return &tuple_;
}

std::string ViewScanPhysicalOperator::param() const
{
  return table_->name();
}

void ViewScanPhysicalOperator::set_predicates(std::vector<std::unique_ptr<Expression>> &&exprs)
{
  predicates_ = std::move(exprs);
}

RC ViewScanPhysicalOperator::filter(RowTuple &tuple, bool &result)
{
  RC rc = RC::SUCCESS;
  Value value;
  for (std::unique_ptr<Expression> &expr : predicates_) {
    if (ctx_tuple_ != nullptr) {
      JoinedTuple combined;
      combined.set_left(&tuple);
      combined.set_right(ctx_tuple_);
      rc = expr->get_value(combined, value, trx_);
    } else {
      rc = expr->get_value(tuple, value, trx_);
    }

    if (rc != RC::SUCCESS) {
      return rc;
    }

    bool tmp_result = value.get_boolean();
    if (!tmp_result) {
      result = false;
      return rc;
    }
  }

  result = true;
  return rc;
}
