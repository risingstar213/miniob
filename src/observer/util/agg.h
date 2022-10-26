#ifndef _AGG_H_
#define _AGG_H_

#include "sql/parser/parse_defs.h"
typedef union AggData {
  struct {
    char *data;
  } max;
  struct {
    char *data;
  } min;
  struct {
    char *data;
  } count;
  struct {
    char *data;
  } sum;
  struct {
    char *data;
    int count;
  } avg;
} AggData;

class AggFunc
{
public:
  static void init_data(Aggregation agg, AggData *data, AttrType type);
  static void add_data(Aggregation agg, AggData *data, AttrType type, char *data_in, int length);
  static void destroy_data(Aggregation agg, AggData *data, AttrType type);
  static AttrType get_attrtype(Aggregation agg, AttrType type);
  static char* get_data(Aggregation agg, AggData *data, AttrType type);
};

#endif