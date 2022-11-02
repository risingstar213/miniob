#include "util/operator_helper.h"
#include "common/log/log.h"

#include "sql/operator/table_scan_operator.h"
#include "sql/operator/tables_scan_operator.h"
#include "sql/operator/index_scan_operator.h"
#include "sql/operator/predicate_operator.h"
#include "sql/operator/delete_operator.h"
#include "sql/operator/update_operator.h"
#include "sql/operator/project_operator.h"
#include "sql/operator/join_operator.h"
#include "sql/stmt/stmt.h"
#include "sql/stmt/select_stmt.h"
#include "sql/stmt/update_stmt.h"
#include "sql/stmt/delete_stmt.h"
#include "sql/stmt/insert_stmt.h"
#include "sql/stmt/filter_stmt.h"
#include "sql/stmt/join_stmt.h"

Operator*  get_select_operator(SelectStmt *select_stmt)
{
   Operator *top_oper;
  bool multi_tables = select_stmt->tables().size() > 1;
  std::vector<JoinStmt *> join_tables = select_stmt->join_stmts();
  if (join_tables.size() > 0) {
    LOG_INFO("join num: %d", join_tables.size());
    Operator *left_operator = new TableScanOperator(select_stmt->tables()[0]);
    TableScanOperator *right_operator;
    JoinOperator *join_operator;
    for (size_t i = 0; i < join_tables.size(); i++) {
      right_operator = new TableScanOperator(join_tables[i]->table());
      join_operator = new JoinOperator(left_operator, right_operator);
      LOG_INFO("join_stmt: %d", join_tables[i]->filter_stmt()->filter_units().size());
      left_operator = new PredicateOperator(join_tables[i]->filter_stmt());
      left_operator->add_child(join_operator);
    }
    top_oper = left_operator;
  }
  else if (multi_tables) {
    top_oper = new TablesScanOperator();
    Operator *child_oper;
    for (uint i = 0; i < select_stmt->tables().size(); i++) {
      child_oper = new TableScanOperator(select_stmt->tables()[i]);
      top_oper->add_child(child_oper);
    }
  } else {
    top_oper = new TableScanOperator(select_stmt->tables()[0]);
  }

  PredicateOperator *pred_oper = new PredicateOperator(select_stmt->filter_stmt());
  pred_oper->add_child(top_oper);

  GroupOperator *group_oper = new GroupOperator(select_stmt->group_expresions(), 
          select_stmt->having_filter(), select_stmt->is_aggregations());
  group_oper->add_child(pred_oper);

  ProjectOperator *project_oper = new ProjectOperator;
  project_oper->add_child(group_oper);
  
  int n = select_stmt->select_exprs().size();
  for (int i = 0; i < n; i++) {
    project_oper->add_projection(multi_tables, &select_stmt->select_exprs()[i], select_stmt->is_aggregations());
  }
  return project_oper;
}