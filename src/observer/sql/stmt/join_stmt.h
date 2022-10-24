#pragma once

#include <vector>
#include <unordered_map>
#include <string>

#include "storage/common/field.h"
#include "sql/stmt/stmt.h"

class Db;
class Table;

class JoinStmt : public Stmt
{
public:
  JoinStmt() = default;
  ~JoinStmt() override;

  StmtType type() const override { return StmtType::JOIN; }

  static RC create(Db *db, std::vector<Table *>* tables, 
                    std::unordered_map<std::string, Table *> *table_map, 
                    Join &join_sql, JoinStmt *&stmt);

  Table* table() { return table_; }
  FilterStmt *filter_stmt() const { return filter_stmt_; }
private:
  Table *table_;
  FilterStmt *filter_stmt_ = nullptr;
};
