#pragma once

#include "sql/operator/operator.h"
#include "sql/parser/parse.h"
#include "rc.h"
#include "sql/expr/tuple.h"

class Trx;
class UpdateStmt;

class UpdateOperator : public Operator {
public:
  UpdateOperator(UpdateStmt *update_stmt, Trx *trx) : update_stmt_(update_stmt), trx_(trx)
  {}

  virtual ~UpdateOperator() = default;

  RC open() override;
  RC next() override;
  RC close() override;

  std::vector<Tuple *> current_tuples() override
  {
    std::vector<Tuple *> tuples;
    tuples.push_back(nullptr);
    return tuples;
  }

private:
  UpdateStmt *update_stmt_ = nullptr;
  Trx *trx_ = nullptr;
};