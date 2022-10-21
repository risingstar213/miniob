#include "util/like.h"
#include "common/log/log.h"

bool LikeUnit::like_schema(const char *data, int data_len, const char *schema, int schema_len)
{
  bool *match = new bool[data_len+1];
  // LOG_INFO("data(%d):%s, schema(%d):%s", data_len, data, schema_len, schema);
  match[0] = true;
  for (int i = 1; i <= data_len; i++) {
    match[i] = false;
  }
  for (int j = 0; j < schema_len; j++) {
    for (int i = data_len; i > 0; i--) {
      switch (schema[j]) {
        case '%': {
          for (int k = i-1; k >= 0; k--) {
            if (match[k]) {
              match[i] = true;
              break;
            }
            match[i] = false;
            if (data[k] == '\'') {
              break;
            }
          }
        } break;
        case '_': {
          if (match[i-1] && data[i-1] != '\'') {
            match[i] = true;
          } else {
            match[i] = false;
          }
        } break;
        default: {
          if (match[i-1] && data[i-1] == schema[j]) {
            match[i] = true;
          } else {
            match[i] = false;
          }
        } break;
      }
    }
    match[0] = false;
  }
  bool comp = match[data_len];
  delete []match;
  return comp;
}

bool LikeUnit::unlike_schema(const char *data, int data_len, const char *schema, int schema_len) {
  return !like_schema(data, data_len, schema, schema_len);
}