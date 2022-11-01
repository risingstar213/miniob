#include "util/agg.h"
#include "util/comparator.h"
#include "util/cast.h"
#include "util/util.h"
#include "defs.h"
#include <cstdlib>

void AggFunc::init_data(Aggregation agg, AggData *data, AttrType type) {
  switch (agg) {
    case AGG_MAX: {
      data->min.data = nullptr;
    } break;
    case AGG_MIN: {
      data->max.data = nullptr;
    } break; // no alloc
    case AGG_COUNT: {
      data->count.data = (char *)calloc(1, sizeof(int));
    } break;
    case AGG_SUM: {
      if (type == INTS) {
        data->sum.data = (char *)calloc(1, sizeof(int));
      } else if (type == FLOATS) {
        data->sum.data = (char *)calloc(1, sizeof(float));
      }
      data->sum.count = 0;
    } break;
    case AGG_AVG: {
      data->avg.data = (char *)calloc(1, sizeof(float));
      data->avg.count = 0;
    } break;
    default:
      break;
  }
}

void AggFunc::add_data(Aggregation agg, AggData *data, AttrType type, char *data_in, int length = 0)
{
  if (is_null(data_in)) {
    return;
  }
  switch (agg) {
    case AGG_MAX: {
      // if (*((int *)data_in) == 1 << 31) {
      //   return;
      // }
      if (data->max.data != nullptr) {
        switch (type) {
          case INTS: {
            if (compare_int(data->max.data, data_in) < 0) {
              data->max.data = data_in;
            }
          } break;
          case FLOATS: {
            if (compare_float(data->max.data, data_in) < 0) {
              data->max.data = data_in;
            }
          } break;
          case TEXTS:
          case CHARS: {
            if (compare_string(data->max.data, length, data_in, length) < 0) {
              data->max.data = data_in;
            }
          } break;
          case DATES: {
            if (compare_date(data->max.data, data_in) < 0) {
              data->max.data = data_in;
            }
          } break;
          default:
            break;
        }
      } else {
        data->max.data = data_in;
      }
    } break;
    case AGG_MIN: {
      // if (*((int *)data_in) == 1 << 31) {
      //   return;
      // }
      if (data->min.data != nullptr) {
        switch (type) {
          case INTS: {
            if (compare_int(data->max.data, data_in) > 0) {
              data->min.data = data_in;
            }
          } break;
          case FLOATS: {
            if (compare_float(data->max.data, data_in) > 0) {
              data->min.data = data_in;
            }
          } break;
          case TEXTS:
          case CHARS: {
            if (compare_string(data->max.data, length, data_in, length) > 0) {
              data->min.data = data_in;
            }
          } break;
          case DATES: {
            if (compare_date(data->max.data, data_in) > 0) {
              data->max.data = data_in;
            }
          } break;
          default:
            break;
        }
      } else {
        data->min.data = data_in;
      }
    } break;
    case AGG_COUNT: {
      // (TODO): resolve null
      // if (*((int *)data_in) == 1 << 31) {
      //   return;
      // }
      *((int *)data->count.data) += 1;
    } break;
    case AGG_SUM: {
      // if (*((int *)data_in) == 1 << 31) {
      //   return;
      // }
      data->sum.count += 1;
      switch (type) {
        case INTS:{
          *((int *)data->sum.data) += *((int *)data_in);
        } break;
        case FLOATS: {
          *((float *)data->sum.data) += *((float *)data_in);
        } break;
        case TEXTS:
        case CHARS: {
          *((float *)data->sum.data) += CastUnit::cast_string_to_float(data_in, length);
        } break;
        default:
          break;
      }
    } break;
    case AGG_AVG: {
      // if (*((int *)data_in) == 1 << 31) {
      //   return;
      // }
      data->avg.count += 1;
      switch (type) {
        case INTS:{
          *((float *)data->avg.data) += *((int *)data_in);
        } break;
        case FLOATS: {
          *((float *)data->avg.data) += *((float *)data_in);
        } break;
        case TEXTS:
        case CHARS: {
          *((float *)data->avg.data) += CastUnit::cast_string_to_float(data_in, length);
        } break;
        default:
          break;
      }
    } break;
    default:
      break;
  }
}

void AggFunc::destroy_data(Aggregation agg, AggData *data, AttrType type)
{
  switch (agg) {
    case AGG_MAX:
    case AGG_MIN: break;
    case AGG_COUNT: {
      free(data->count.data);
    } break;
    case AGG_SUM: {
      free(data->sum.data);
    } break;
    case AGG_AVG: {
      free(data->avg.data);
    } break;
    default:
      break;
  }
}

AttrType AggFunc::get_attrtype(Aggregation agg, AttrType type)
{
  switch (agg) {
    case AGG_MAX:
    case AGG_MIN: {
      return type;
    } break;
    case AGG_COUNT: {
      return INTS;
    } break;
    case AGG_SUM: {
      if (type == INTS) {
        return INTS;
      } else {
        return FLOATS;
      }
    } break;
    case AGG_AVG: {
      return FLOATS;
    } break;
    default:
      return UNDEFINED;
      break;
  }
}

char* AggFunc::get_data(Aggregation agg, AggData *data, AttrType type)
{
  switch (agg)
  {
  case AGG_MAX: {
    return data->max.data;
  } break;
  case AGG_MIN: {
    return data->min.data;
  } break;
  case AGG_COUNT: {
    return data->count.data;
  } break;
  case AGG_SUM: {
    if (data->sum.count == 0) {
      *(int *)data->sum.data = NULL_CONST;
      return data->sum.data;
    }
    return data->sum.data;
  } break;
  case AGG_AVG: {
    if (data->avg.count == 0) {
      *(int *)data->avg.data = NULL_CONST;
      return data->avg.data;
    }
    *((float *)data->sum.data) /= data->avg.count;
    return data->avg.data;
  } break;
  default:
    return nullptr;
    break;
  }
}