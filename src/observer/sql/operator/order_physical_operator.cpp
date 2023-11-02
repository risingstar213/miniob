#include <algorithm>

#include "sql/operator/order_physical_operator.h"

OrderPhysicalOperator::OrderPhysicalOperator(std::vector<Field> &all_fields, std::vector<Field> &order_fields, std::vector<uint8_t> &ascs) 
  : order_fields_num_(order_fields.size()), all_fields_num_(all_fields.size()), ascs_(ascs), tuple_(all_fields) 
{
  for (int i = 0; i < order_fields.size(); i++) {
    for (int j = 0; j < all_fields.size(); j++) {
      if (0 != strcmp(all_fields[j].table_name(), order_fields[i].table_name())) {
        continue;
      }
      if (0 == strcmp(all_fields[j].field_name(), order_fields[i].field_name())) {
        order_fields_idxes_.emplace_back(j);
      }
    }
  }
}

RC OrderPhysicalOperator::open(Trx *trx)
{
  if (children_.size() != 1) {
    LOG_WARN("order operator must has one child");
    return RC::INTERNAL;
  }

  RC rc = children_[0]->open(trx);
  if (rc != RC::SUCCESS) {
    LOG_WARN("failed to open child operator: %s", strrc(rc));
    return rc;
  }

  std::vector<Value> values;
  Tuple *tuple;
  Value value;
  row_list_.clear();
  while (RC::SUCCESS == (rc = children_[0]->next())) {
    tuple = children_[0]->current_tuple();
    values.clear();
    for (int i = 0; i < all_fields_num_; i++) {
      // rc = tuple->find_cell(tuple_.get_speces_()[i], value);
      LOG_INFO("get %d value", i);
      rc = tuple->cell_at(i, value);
      if (rc != RC::SUCCESS) {
        LOG_INFO("Order Operator cannot get data from children[0]");
        return rc;
      }
      values.emplace_back(value);
    }
    row_list_.emplace_back(values);
  }

  if (rc != RC::RECORD_EOF) {
    LOG_INFO("order by get error: %s", strrc(rc));
    return rc;
  }

  int row_count = row_list_.size();
  order_idxes_.clear();
  for (int i = 0; i < row_count; i++) {
    order_idxes_.emplace_back(i);
  }

  std::sort(
    order_idxes_.begin(), 
    order_idxes_.end(), 
    [&](int &l_, int &r_) -> bool {
      for (int i = 0; i < order_fields_num_; i++) {
        Value &left = row_list_[l_][order_fields_idxes_[i]];
        Value &right = row_list_[r_][order_fields_idxes_[i]];

        if (left.is_null() && right.is_null()) {
          continue;
        }

        if ((!left.is_null() && right.is_null()) || left.compare(right) > 0) {
          if (ascs_[i] == true) {
            return false;
          } else {
            return true;
          }
        } else if ((left.is_null() && !right.is_null()) || left.compare(right) < 0) {
          if (ascs_[i] == true) {
            return true;
          } else {
            return false;
          }
        }
      }

      return true;
    });

  now_count_ = 0;
  return RC::SUCCESS;
}

RC OrderPhysicalOperator::next()
{
  if (now_count_ >= order_idxes_.size()) {
    return RC::RECORD_EOF;
  }
  tuple_.set_values(row_list_[order_idxes_[now_count_]]);
  now_count_ += 1;
  return RC::SUCCESS;
}

RC OrderPhysicalOperator::close()
{
  order_idxes_.clear();
  row_list_.clear();
  now_count_ = 0;
  return children_[0]->close();
}

Tuple *OrderPhysicalOperator::current_tuple()
{
  return &tuple_;
}