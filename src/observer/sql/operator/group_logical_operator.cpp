#include "sql/operator/group_logical_operator.h"

#include "storage/field/field.h"

GroupLogicalOperator::GroupLogicalOperator(std::vector<Field> &all_fields, std::vector<Field> &group_fields, Expression *having_filters)
    : all_fields_(all_fields), group_fields_(group_fields), having_filters_(std::unique_ptr<Expression>(having_filters))
{
}