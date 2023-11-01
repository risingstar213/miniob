
#include "sql/executor/show_index_executor.h"

#include "session/session.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "common/log/log.h"
#include "storage/table/table.h"
#include "sql/stmt/show_index_stmt.h"
#include "storage/db/db.h"
#include "storage/index/index.h"
#include "storage/index/index_meta.h"
#include "sql/operator/string_list_physical_operator.h"


RC ShowIndexExecutor::execute(SQLStageEvent *sql_event)
{
    RC rc = RC::SUCCESS;
    Stmt *stmt = sql_event->stmt();
    SessionEvent *session_event = sql_event->session_event();
    Session *session = session_event->session();
    ASSERT(stmt->type() == StmtType::DESC_TABLE, 
            "desc table executor can not run this command: %d", static_cast<int>(stmt->type()));

    ShowIndexStmt *show_index_stmt = static_cast<ShowIndexStmt *>(stmt);

    SqlResult *sql_result = session_event->sql_result();

    const char *table_name = show_index_stmt->table_name().c_str();

    Db *db = session->get_current_db();
    Table *table = db->find_table(table_name);
    if (table != nullptr) {
        TupleSchema tuple_schema;
        tuple_schema.append_cell(TupleCellSpec("", "Table", "Table"));
        tuple_schema.append_cell(TupleCellSpec("", "Non_unique", "Non_unique"));
        tuple_schema.append_cell(TupleCellSpec("", "Key_name", "Key_name"));
        tuple_schema.append_cell(TupleCellSpec("", "Seq_in_index", "Seq_in_index"));
        tuple_schema.append_cell(TupleCellSpec("", "Column_name", "Column_name"));

        sql_result->set_tuple_schema(tuple_schema);

        auto oper = new StringListPhysicalOperator;
        auto &indexes = table->indexes();
        for (int i = 0; i < indexes.size(); i++) {
            const IndexMeta &index_meta = indexes[i]->index_meta();
            std::vector<std::string> fields = index_meta.fields();
            for (int j = 0; j < fields.size(); j++) {
                oper->append({
                    table_name, 
                    index_meta.is_unique() ? "0" : "1", 
                    index_meta.name(),
                    std::to_string(j+1),
                    fields[j]
                });
            }
        }

        sql_result->set_operator(std::unique_ptr<PhysicalOperator>(oper));
    } else {

        sql_result->set_return_code(RC::SCHEMA_TABLE_NOT_EXIST);
        sql_result->set_state_string("Table not exists");
    }
    return rc;
}