#include "sql/stmt/show_index_stmt.h"
#include "storage/db/db.h"

RC ShowIndexStmt::create(Db *db, const ShowIndexSqlNode &desc_table, Stmt *&stmt)
{
  if (db->find_table(desc_table.relation_name.c_str()) == nullptr) {
    return RC::SCHEMA_TABLE_NOT_EXIST;
  }
  stmt = new ShowIndexStmt(desc_table.relation_name);
  return RC::SUCCESS;
}