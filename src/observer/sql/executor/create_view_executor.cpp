#include "storage/table/table.h"
#include "sql/stmt/create_view_stmt.h"
#include "sql/executor/create_view_executor.h"
#include "sql/stmt/select_stmt.h"
#include "event/sql_event.h"
#include "session/session.h"
#include "event/session_event.h"
#include "storage/db/db.h"


RC CreateViewExecutor::execute(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  Session *session = sql_event->session_event()->session();
  ASSERT(stmt->type() == StmtType::CREATE_TABLE, 
         "create table executor can not run this command: %d", static_cast<int>(stmt->type()));

  CreateViewStmt *create_view_stmt = static_cast<CreateViewStmt *>(stmt);

  const int attribute_count = static_cast<int>(create_view_stmt->attr_infos().size());

  auto &select_stmt = create_view_stmt->select_stmt();
  if (select_stmt == nullptr) {
    return RC::INTERNAL;
  }

  const char *table_name = create_view_stmt->table_name().c_str();
  RC rc = session->get_current_db()->create_view(table_name, attribute_count, create_view_stmt->attr_infos().data(), select_stmt.get());
  select_stmt.release();
  return rc;
}