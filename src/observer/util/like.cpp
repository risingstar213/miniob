#include "util/like.h"
#include "common/log/log.h"

static bool equal(char schemai, char datai)
{
  char s, d;
  if (schemai >= 'A' && schemai <= 'Z') {
    s = schemai - 'A' + 'a';
  } else {
    s = schemai;
  }
  if (datai >= 'A' && datai <= 'Z') {
    d = datai - 'A' + 'a';
  } else {
    d = datai;
  }
  return s == d;
}

bool LikeUnit::like_schema(const char *data, int data_len, const char *schema, int schema_len)
{
  bool *match = new bool[data_len+1];
  LOG_INFO("like: data(%d):%s, schema(%d):%s", data_len, data, schema_len, schema);
  match[0] = true;
  for (int i = 1; i <= data_len; i++) {
    match[i] = false;
  }
  for (int j = 0; j < schema_len; j++) {
    for (int i = data_len; i > 0; i--) {
      switch (schema[j]) {
        case '%': {
          for (int k = i; k >= 0; k--) {
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
          if (i == 1) {
            match[0] = false;
          }
        } break;
        default: {
          if (match[i-1] && equal(data[i-1],schema[j])) {
            match[i] = true;
          } else {
            match[i] = false;
          }
          if (i == 1) {
            match[0] = false;
          }
        } break;
      }
    }
  }
  bool comp = match[data_len];
  delete []match;
  return comp;
}

bool LikeUnit::unlike_schema(const char *data, int data_len, const char *schema, int schema_len) {
  LOG_INFO("unlike: data(%d):%s, schema(%d):%s", data_len, data, schema_len, schema);
  return !like_schema(data, data_len, schema, schema_len);
}