#include "sql/operator/group_logical_operator.h"

#include "storage/field/field.h"

GroupLogicalOperator::GroupLogicalOperator(std::vector<Field> &fields)
{
    fields_.swap(fields);
}