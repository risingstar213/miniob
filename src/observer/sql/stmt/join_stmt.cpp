
#include "common/log/log.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/join_stmt.h"
#include "storage/common/db.h"
#include "storage/common/table.h"

JoinStmt::~JoinStmt()
{
  if (nullptr != filter_stmt_) {
    delete filter_stmt_;
    filter_stmt_ = nullptr;
  }
}

RC JoinStmt::create(Db *db, std::vector<TableInfo>* tables, 
                    std::unordered_map<std::string, Table *> *table_map, 
                    Join &join_sql, JoinStmt *&stmt)
{
  if (nullptr == db) {
    LOG_WARN("invalid argument. db is null");
    return RC::INVALID_ARGUMENT;
  }

  const char *table_name = join_sql.relation_name;
  if (nullptr == table_name) {
    LOG_WARN("invalid argument. relation name is null.");
    return RC::INVALID_ARGUMENT;
  }

  Table *table = db->find_table(table_name);
  if (nullptr == table) {
    LOG_WARN("no such table. db=%s, table_name=%s", db->name(), table_name);
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }

  tables->push_back(TableInfo{table, table_name});
  table_map->insert(std::pair<std::string, Table*>(table_name, table));

  FilterStmt *filter_stmt = nullptr;
  RC rc = FilterStmt::create(db, TableInfo{nullptr, nullptr}, table_map,
            join_sql.conditions, join_sql.condition_num, filter_stmt);

  if (rc != RC::SUCCESS) {
    return rc;
  }
  // everything alright
  JoinStmt *join_stmt = new JoinStmt();
  join_stmt->table_ = table;
  join_stmt->filter_stmt_ = filter_stmt;
  stmt = join_stmt;
  return RC::SUCCESS;
}