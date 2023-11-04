/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by Wangyunlai on 2023/6/13.
//

#include <memory>

#include "sql/executor/create_table_executor.h"

#include "session/session.h"
#include "common/log/log.h"
#include "storage/table/table.h"
#include "sql/stmt/create_table_stmt.h"
#include "sql/stmt/select_stmt.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "storage/db/db.h"

#include "sql/optimizer/logical_plan_generator.h"
#include "sql/optimizer/physical_plan_generator.h"
#include "storage/trx/trx.h"

RC CreateTableExecutor::execute(SQLStageEvent *sql_event)
{
  Stmt *stmt = sql_event->stmt();
  Session *session = sql_event->session_event()->session();
  ASSERT(stmt->type() == StmtType::CREATE_TABLE, 
         "create table executor can not run this command: %d", static_cast<int>(stmt->type()));

  CreateTableStmt *create_table_stmt = static_cast<CreateTableStmt *>(stmt);

  const int attribute_count = static_cast<int>(create_table_stmt->attr_infos().size());

  const char *table_name = create_table_stmt->table_name().c_str();
  RC rc = session->get_current_db()->create_table(table_name, attribute_count, create_table_stmt->attr_infos().data());

  // insert
  auto &select_stmt = create_table_stmt->select_stmt();
  if (select_stmt == nullptr) {
    return rc;
  }

  Table *table = session->get_current_db()->find_table(table_name);
  if (table == nullptr) {
    LOG_WARN("cannot find table in create table select!");
    return RC::INTERNAL;
  }

  std::unique_ptr<LogicalOperator> logical_oper;
  LogicalPlanGenerator logical_generator;
  logical_generator.create(select_stmt.get(), logical_oper);
  PhysicalPlanGenerator physical_generator;
  std::unique_ptr<PhysicalOperator> physical_oper;
  physical_generator.create(*logical_oper, physical_oper);

  Trx *trx = sql_event->session_event()->session()->current_trx();

  rc = physical_oper->open(trx);
  if (rc != RC::SUCCESS) {
    return RC::INTERNAL;
  }

  while (RC::SUCCESS == (rc = physical_oper->next())) {
    Tuple *tuple = physical_oper->current_tuple();
    std::vector<Value> values;
    Value temp;

    for (int i = 0; i < tuple->cell_num(); i++) {
      RC rc = tuple->cell_at(i, temp);
      if (rc != RC::SUCCESS) {
        return rc;
      }
      values.emplace_back(temp);
    }
    Record record;
    rc = table->make_record(static_cast<int>(values.size()), values.data(), record);
    if (rc != RC::SUCCESS) {
      return rc;
    }
    rc = trx->insert_record(table, record);

    if (rc != RC::SUCCESS) {
      LOG_WARN("failed to insert record: %s", strrc(rc));
      return rc;
    }
  }

  if (rc == RC::RECORD_EOF) {
    return RC::SUCCESS;
  }
  return rc;
}