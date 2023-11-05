#pragma once

#include "common/rc.h"

class SQLStageEvent;

/**
 * @brief 创建表的执行器
 * @ingroup Executor
 */
class CreateViewExecutor
{
public:
  CreateViewExecutor() = default;
  virtual ~CreateViewExecutor() = default;

  RC execute(SQLStageEvent *sql_event);
};