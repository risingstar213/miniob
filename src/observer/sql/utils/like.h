#pragma once

class LikeUnit {
public:
  static bool like_schema(const char *data, int data_len, const char *schema, int schema_len);
  static bool unlike_schema(const char *data, int data_len, const char *schema, int schema_len);
};
