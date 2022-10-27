
#include "util/cast.h"
#include "common/log/log.h"

static int cast_float_to_int(float f)
{
  if (f > 0) {
    return (f * 10 + 5) / 10;
  } else if (f < 0) {
    return (f * 10 - 5) / 10;
  }
  return 0;
}

void CastUnit::cast_to(Value &value, AttrType type)
{
  bool convert = false;
  switch (value.type) {
    case AttrType::CHARS: {
      char *old_data = (char *)value.data;
      switch (type) {
        case AttrType::FLOATS: {
          convert = true;
          value.data = malloc(sizeof(float));
          if (old_data[0] <'0' || old_data[0] > '9') {
            *(float *)(value.data) = 0;
          } else {
            sscanf(old_data, "%f", (float *)value.data);
          }
          value.type = AttrType::FLOATS;
        } break;
        case AttrType::INTS: {
          convert = true;
          value.data = malloc(sizeof(int));
          if (old_data[0] <'0' || old_data[0] > '9') {
            *(int *)(value.data) = 0;
          } else {
            sscanf(old_data, "%d", (int *)value.data);
          }
          value.type = AttrType::INTS;
        } break;
        case AttrType::TEXTS: {
          value.type = AttrType::TEXTS;
        } break;
        default:
          break;
      }
      if (convert == true) {
        free(old_data);
      }
    } break;
    case AttrType::FLOATS: {
      float *old_data = (float *)value.data;
      switch (type) {
        case AttrType::CHARS: {
          convert = true;
          std::swap(value.data, value.raw_data);
          value.type = AttrType::CHARS;
        } break;
        case AttrType::INTS: {
          convert = true;
          value.data = malloc(sizeof(int));
          *(int *)(value.data) = cast_float_to_int(*old_data);
          value.type = AttrType::INTS;
          free(old_data);
        } break;
        default:
          break;
      }
    } break;
    case AttrType::INTS: {
      int *old_data = (int *)value.data;
      switch (type) {
        case AttrType::CHARS: {
          convert = true;
          std::swap(value.data, value.raw_data);
          value.type = AttrType::CHARS;
        } break;
        case AttrType::FLOATS: {
          convert = true;
          value.data = malloc(sizeof(float));
          *(float *)(value.data) = *old_data;
          value.type = AttrType::FLOATS;
          free(old_data);
        } break;
        default:
          break;
      }
    } break;
    default:
      break;
  }
  // return RC::SUCCESS;
}


float CastUnit::cast_string_to_float(char * data, int length) {
  float f;
  if (data[0] <'0' || data[0] > '9') {
    f = 0;
  } else {
    sscanf(data, "%f", &f);
  }
  return f;
}
int CastUnit::cast_string_to_int(char * data, int length) {
  float f = cast_string_to_float(data, length);
  return cast_float_to_int(f);
}