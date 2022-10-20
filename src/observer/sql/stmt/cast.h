#pragma once
#ifndef _CAST_H_
#define _CAST_H_
#include "rc.h"
#include "sql/parser/parse_defs.h"

class CastUnit
{
public:
  static void cast_to(Value &value, AttrType type);
  // static RC cast_compare(Value &left, Value &right);
};

#endif