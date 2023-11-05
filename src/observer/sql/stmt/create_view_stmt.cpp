#include <unordered_map>

#include "sql/stmt/create_view_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "event/sql_debug.h"
#include "sql/expr/expression.h"

RC CreateViewStmt::create(Db *db, const CreateViewSqlNode &create_view, Stmt *&stmt)
{
  SelectStmt* as_select_stmt = nullptr;
  std::deque<AttrInfoSqlNode> attr_infos = create_view.attr_infos;
  bool has_attr_defs = attr_infos.size() > 0;
  if (create_view.as_select != nullptr) {
    Stmt* as_stmt = nullptr;
    std::unordered_map<std::string, Table *> empty_table_map;
    RC rc = SelectStmt::create(db, *create_view.as_select, empty_table_map, as_stmt, true);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    as_select_stmt = static_cast<SelectStmt *>(as_stmt);

    auto &exprs = as_select_stmt->query_exprs();
    auto &alias = as_select_stmt->query_alias();

    if (has_attr_defs && exprs.size() != attr_infos.size()) {
      return RC::INVALID_ARGUMENT;
    }

    for (int i = 0; i < exprs.size(); i++) {
      AttrType type = exprs[i]->value_type();
      if (has_attr_defs && type == attr_infos[i].type) {
        continue;
      } else if (has_attr_defs) {
        return RC::INVALID_ARGUMENT;
      }

      size_t length = 4;
      if (type == DATES) {
        length = 12;
      } else if (type == TEXTS) {
        length = 50;
      }
      attr_infos.emplace_back(AttrInfoSqlNode{
        type,
        alias[i],
        length,
        false,
        -1,
      });
    }
  }
  
  stmt = new CreateViewStmt(create_view.relation_name, attr_infos, as_select_stmt);
  sql_debug("create view statement: table name %s", create_view.relation_name.c_str());
  return RC::SUCCESS;
}
