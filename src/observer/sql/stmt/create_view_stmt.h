#pragma once

#include <string>
#include <vector>

#include "sql/stmt/stmt.h"

class Db;
class SelectStmt;

/**
 * @brief 表示创建表的语句
 * @ingroup Statement
 * @details 虽然解析成了stmt，但是与原始的SQL解析后的数据也差不多
 */
class CreateViewStmt : public Stmt
{
public:
  CreateViewStmt(const std::string &table_name, const std::deque<AttrInfoSqlNode> &attr_infos, SelectStmt *stmt)
        : table_name_(table_name), select_stmt_(std::unique_ptr<SelectStmt>(stmt))
  {
    for (size_t i = 0; i < attr_infos.size(); i++) {
      attr_infos_.push_back(attr_infos[i]);
      if (attr_infos[i].null_unsolved == 0) {
        attr_infos_[i].nullable = false;
      } else if (attr_infos[i].null_unsolved == 1) {
        attr_infos_[i].nullable = true;
      } else if (i == 0) {
        attr_infos_[i].nullable = false;
      } else {
        attr_infos_[i].nullable = true;
      }
    }
  }
  virtual ~CreateViewStmt() = default;

  StmtType type() const override { return StmtType::CREATE_VIEW; }

  const std::string &table_name() const { return table_name_; }
  const std::vector<AttrInfoSqlNode> &attr_infos() const { return attr_infos_; }

  std::unique_ptr<SelectStmt> &select_stmt() { return select_stmt_; }

  static RC create(Db *db, const CreateViewSqlNode &create_table, Stmt *&stmt);

private:
  std::string table_name_;
  std::vector<AttrInfoSqlNode> attr_infos_;
  std::unique_ptr<SelectStmt> select_stmt_ = nullptr;
};