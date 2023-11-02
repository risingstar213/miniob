#include "sql/operator/order_logical_operator.h"


OrderLogicalOperator::OrderLogicalOperator(std::vector<Field> &all_fields, std::vector<Field> &order_fields, std::vector<uint8_t> &ascs)
  : all_fields_(all_fields), order_fields_(order_fields), ascs_(ascs)
{
}