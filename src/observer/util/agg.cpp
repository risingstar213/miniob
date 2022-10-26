#include "util/agg.h"
#include "util/comparator.h"
#include "util/cast.h"
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
  switch (agg) {
    case AGG_MAX: {
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
      *((int *)data->count.data) += 1;
    } break;
    case AGG_SUM: {
      switch (type) {
        case INTS:{
          *((int *)data->sum.data) += *((int *)data_in);
        } break;
        case FLOATS: {
          *((float *)data->sum.data) += *((float *)data_in);
        } break;
        case CHARS: {
          *((float *)data->sum.data) += CastUnit::cast_string_to_float(data_in, length);
        } break;
        default:
          break;
      }
    } break;
    case AGG_AVG: {
      // (TODO): resolve null
      data->avg.count += 1;
      switch (type) {
        case INTS:{
          *((float *)data->avg.data) += *((int *)data_in);
        } break;
        case FLOATS: {
          *((float *)data->avg.data) += *((float *)data_in);
        } break;
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
    return data->sum.data;
  } break;
  case AGG_AVG: {
    *((float *)data->sum.data) /= data->avg.count;
    return data->avg.data;
  } break;
  default:
    return nullptr;
    break;
  }
}