#pragma once

#include "common/rc.h"
#include "sql/operator/string_list_physical_operator.h"
#include "event/sql_event.h"
#include "event/session_event.h"
#include "sql/executor/sql_result.h"
#include "session/session.h"
#include "storage/db/db.h"

class SQLStageEvent;

class ShowIndexExecutor
{
public:
  ShowIndexExecutor() = default;
  virtual ~ShowIndexExecutor() = default;

  RC execute(SQLStageEvent *sql_event);
};