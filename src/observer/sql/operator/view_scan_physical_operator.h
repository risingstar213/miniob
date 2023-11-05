#pragma once

#include "sql/operator/physical_operator.h"
#include "common/rc.h"

class ViewScanPhysicalOperator : public PhysicalOperator
{
public:
  ViewScanPhysicalOperator(Table *table, PhysicalOperator *view_operator);

  ~ViewScanPhysicalOperator() override;

  std::string param() const override;

  PhysicalOperatorType type() const override
  {
    return PhysicalOperatorType::VIEW_SCAN;
  }

  RC open(Trx *trx) override;
  RC next() override;
  RC close() override;

  Tuple *current_tuple() override;

  void set_predicates(std::vector<std::unique_ptr<Expression>> &&exprs);

private:
  RC filter(RowTuple &tuple, bool &result);

private:
  Table *                                  table_ = nullptr;
  // SelectStmt *                             view_stmt_ = nullptr;
  PhysicalOperator *                       view_operator_ = nullptr;
  Trx *                                    trx_ = nullptr;
  // Record                                   current_record_;
  RowTuple                                 tuple_;
  std::vector<std::unique_ptr<Expression>> predicates_;
  Record                                   record_;
};