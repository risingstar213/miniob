#pragma once
#ifndef _CAST_H_
#define _CAST_H_
#include "rc.h"
#include "sql/parser/parse_defs.h"

class CastUnit
{
public:
  static void cast_to(Value &value, AttrType type);
  static void cast_to_with_new_alloc(Value &value, AttrType type);
  static float cast_string_to_float(char * data, int length);
  static int cast_string_to_int(char * data, int length);
};

#endif