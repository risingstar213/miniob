/* Copyright (c) 2021 OceanBase and/or its affiliates. All rights reserved.
miniob is licensed under Mulan PSL v2.
You can use this software according to the terms and conditions of the Mulan PSL v2.
You may obtain a copy of Mulan PSL v2 at:
         http://license.coscl.org.cn/MulanPSL2
THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
See the Mulan PSL v2 for more details. */

//
// Created by WangYunlai on 2023/06/28.
//

#include <sstream>
#include <iomanip>
#include "sql/parser/value.h"
#include "storage/field/field.h"
#include "common/log/log.h"
#include "common/lang/comparator.h"
#include "common/lang/string.h"


const char *ATTR_TYPE_NAME[] = {"undefined", "chars", "ints", "floats", "dates", "texts","booleans"};

const char *attr_type_to_string(AttrType type)
{
  if (type >= UNDEFINED && type <= TEXTS) {
    return ATTR_TYPE_NAME[type];
  }
  return "unknown";
}
AttrType attr_type_from_string(const char *s)
{
  for (unsigned int i = 0; i < sizeof(ATTR_TYPE_NAME) / sizeof(ATTR_TYPE_NAME[0]); i++) {
    if (0 == strcmp(ATTR_TYPE_NAME[i], s)) {
      return (AttrType)i;
    }
  }
  return UNDEFINED;
}

Value::Value(int val)
{
  set_int(val);
  is_null_ = false;
}

Value::Value(float val)
{
  set_float(val);
  is_null_ = false;
}

Value::Value(bool val)
{
  set_boolean(val);
  is_null_ = false;
}

Value::Value(const char *s, int len /*= 0*/)
{
  set_string(s, len);
  is_null_ = false;
}

Value::Value(const char *s, bool is_date, bool check_bit)
{
  assert(is_date == true && check_bit == true);
  set_date(s);
  is_null_ = false;
}

void Value::set_data(char *data, int length)
{
  is_null_ = false;
  switch (attr_type_) {
    case CHARS: {
      set_string(data, length);
    } break;
    case INTS: {
      num_value_.int_value_ = *(int *)data;
      length_ = length;
    } break;
    case FLOATS: {
      num_value_.float_value_ = *(float *)data;
      length_ = length;
    } break;
    case BOOLEANS: {
      num_value_.bool_value_ = *(int *)data != 0;
      length_ = length;
    } break;
    case DATES: {
      set_date(data);
    } break;
    case TEXTS: {
      set_text(data, length);
    } break;
    default: {
      LOG_WARN("unknown data type: %d", attr_type_);
    } break;
  }
}
void Value::set_int(int val)
{
  is_null_ = false;
  attr_type_ = INTS;
  num_value_.int_value_ = val;
  length_ = sizeof(val);
}

void Value::set_float(float val)
{
  is_null_ = false;
  attr_type_ = FLOATS;
  num_value_.float_value_ = val;
  length_ = sizeof(val);
}
void Value::set_boolean(bool val)
{
  is_null_ = false;
  attr_type_ = BOOLEANS;
  num_value_.bool_value_ = val;
  length_ = sizeof(val);
}
void Value::set_string(const char *s, int len /*= 0*/)
{
  is_null_ = false;
  attr_type_ = CHARS;
  if (len > 0) {
    len = strnlen(s, len);
    str_value_.assign(s, len);
  } else {
    str_value_.assign(s);
  }
  length_ = str_value_.length();
}

void Value::set_text(const char *s, int len)
{
  is_null_ = false;
  attr_type_ = TEXTS;
  if (len > 0) {
    len = strnlen(s, len);
    str_value_.assign(s, len);
  } else {
    str_value_.assign(s);
  }
  length_ = str_value_.length();
}

void Value::set_date(const char *s)
{
  is_null_ = false;
  attr_type_ = DATES;
  num_value_.date_meta_.set_date(s);
  str_value_ = num_value_.date_meta_.to_string();
  length_ = 10;
}

void Value::set_value(const Value &value)
{
  is_null_ = false;
  switch (value.attr_type_) {
    case INTS: {
      set_int(value.get_int());
    } break;
    case FLOATS: {
      set_float(value.get_float());
    } break;
    case CHARS: {
      set_string(value.get_string().c_str());
    } break;
    case BOOLEANS: {
      set_boolean(value.get_boolean());
    } break;
    case DATES: {
      set_date(value.get_date().c_str());
    }
    case UNDEFINED: {
      ASSERT(false, "got an invalid value type");
    } break;
  }
}

void Value::set_null(bool is_null)
{
  is_null_ = is_null;
}

const char *Value::data() const
{
  switch (attr_type_) {
    case CHARS: {
      return str_value_.c_str();
    } break;
    case DATES: {
      return str_value_.c_str();
    } break;
    default: {
      return (const char *)&num_value_;
    } break;
  }
}

std::string Value::to_string() const
{
  std::stringstream os;
  if (is_null_) {
    os << "null";
    return os.str();
  }
  switch (attr_type_) {
    case INTS: {
      os << num_value_.int_value_;
    } break;
    case FLOATS: {
      os << common::double_to_str(num_value_.float_value_);
    } break;
    case BOOLEANS: {
      os << num_value_.bool_value_;
    } break;
    case CHARS: {
      os << str_value_;
    } break;
    case DATES: {
      os << str_value_;
    } break;
    case TEXTS: {
      os << str_value_;
    } break;
    default: {
      LOG_WARN("unsupported attr type: %d", attr_type_);
    } break;
  }
  return os.str();
}

int Value::compare(const Value &other) const
{
  if (this->is_null_ || other.is_null_) {
    return 0;
  }
  if (this->attr_type_ == other.attr_type_) {
    switch (this->attr_type_) {
      case INTS: {
        return common::compare_int((void *)&this->num_value_.int_value_, (void *)&other.num_value_.int_value_);
      } break;
      case FLOATS: {
        return common::compare_float((void *)&this->num_value_.float_value_, (void *)&other.num_value_.float_value_);
      } break;
      case CHARS: {
        return common::compare_string((void *)this->str_value_.c_str(),
            this->str_value_.length(),
            (void *)other.str_value_.c_str(),
            other.str_value_.length());
      } break;
      case BOOLEANS: {
        return common::compare_int((void *)&this->num_value_.bool_value_, (void *)&other.num_value_.bool_value_);
      }
      case DATES: {
        return num_value_.date_meta_.compare(other.num_value_.date_meta_);
      }
      case TEXTS: {
        return common::compare_string((void *)this->str_value_.c_str(),
            this->str_value_.length(),
            (void *)other.str_value_.c_str(),
            other.str_value_.length());
      };
      default: {
        LOG_WARN("unsupported type: %d", this->attr_type_);
      }
    }
  } else if (this->attr_type_ == INTS && other.attr_type_ == FLOATS) {
    float this_data = this->num_value_.int_value_;
    return common::compare_float((void *)&this_data, (void *)&other.num_value_.float_value_);
  } else if (this->attr_type_ == FLOATS && other.attr_type_ == INTS) {
    float other_data = other.num_value_.int_value_;
    return common::compare_float((void *)&this->num_value_.float_value_, (void *)&other_data);
  } else if (this->attr_type_ == CHARS && other.attr_type_ == INTS) {
    float left_data = this->get_float();
    float right_data = other.get_float();
    return common::compare_float(&left_data, &right_data);
  } else if (this->attr_type_ == INTS && other.attr_type_ == CHARS) {
    float left_data = this->get_float();
    float right_data = other.get_float();
    return common::compare_float(&left_data, &right_data);
  } else if (this->attr_type_ == CHARS && other.attr_type_ == FLOATS) {
    float left_data = this->get_float();
    return common::compare_float(&left_data, (void *)&other.num_value_.float_value_);
  } else if (this->attr_type_ == FLOATS && other.attr_type_ == CHARS) {
    float right_data = other.get_float();
    return common::compare_float((void *)&this->num_value_.float_value_, &right_data);
  }
  LOG_WARN("not supported");
  return -1;  // TODO return rc?
}

static int cast_float_to_int(float f)
{
  if (f > 0) {
    return (f * 10 + 5) / 10;
  } else if (f < 0) {
    return (f * 10 - 5) / 10;
  }
  return 0;
}

int Value::get_int() const
{
  switch (attr_type_) {
    case CHARS: {
      try {
        return (int)(std::stol(str_value_));
      } catch (std::exception const &ex) {
        LOG_TRACE("failed to convert string to number. s=%s, ex=%s", str_value_.c_str(), ex.what());
        return 0;
      }
    }
    case INTS: {
      return num_value_.int_value_;
    }
    case FLOATS: {
      return cast_float_to_int(num_value_.float_value_);
    }
    case BOOLEANS: {
      return (int)(num_value_.bool_value_);
    }
    case DATES:
    case TEXTS: {
      LOG_WARN("the data type. type=%d cannot be casted", attr_type_);
      return false;
    }
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return 0;
    }
  }
  return 0;
}

float Value::get_float() const
{
  switch (attr_type_) {
    case CHARS: {
      // try {
      //   return std::stof(str_value_);
      // } catch (std::exception const &ex) {
      //   LOG_TRACE("failed to convert string to float. s=%s, ex=%s", str_value_.c_str(), ex.what());
      //   return 0.0;
      // }
      if (str_value_[0] <'0' || str_value_[0] > '9') {
        return 0.0;
      } else {
        float f;
        std::sscanf(str_value_.c_str(), "%f", &f);
        return f;
      }
    } break;
    case INTS: {
      return float(num_value_.int_value_);
    } break;
    case FLOATS: {
      return num_value_.float_value_;
    } break;
    case BOOLEANS: {
      return float(num_value_.bool_value_);
    } break;
    case DATES:
    case TEXTS: {
      LOG_WARN("the data type. type=%d cannot be casted", attr_type_);
      return false;
    }
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return 0;
    }
  }
  return 0;
}

std::string Value::get_string() const
{
  return this->to_string();
}

bool Value::get_boolean() const
{
  switch (attr_type_) {
    case CHARS: {
      // try {
      //   float val = std::stof(str_value_);
      //   if (val >= EPSILON || val <= -EPSILON) {
      //     return true;
      //   }

      //   int int_val = std::stol(str_value_);
      //   if (int_val != 0) {
      //     return true;
      //   }

      //   return !str_value_.empty();
      // } catch (std::exception const &ex) {
      //   LOG_TRACE("failed to convert string to float or integer. s=%s, ex=%s", str_value_.c_str(), ex.what());
      //   return !str_value_.empty();
      // }
      if (str_value_[0] <'0' || str_value_[0] > '9') {
        return 0.0;
      } else {
        int d;
        std::sscanf(str_value_.c_str(), "%d", &d);
        return d;
      }
    } break;
    case INTS: {
      return num_value_.int_value_ != 0;
    } break;
    case FLOATS: {
      float val = num_value_.float_value_;
      return val >= EPSILON || val <= -EPSILON;
    } break;
    case BOOLEANS: {
      return num_value_.bool_value_;
    } break;
    case DATES:
    case TEXTS: {
      LOG_WARN("the data type. type=%d cannot be casted", attr_type_);
      return false;
    }
    default: {
      LOG_WARN("unknown data type. type=%d", attr_type_);
      return false;
    }
  }
  return false;
}

std::string Value::get_date() const
{
  std::stringstream os;
  if (attr_type_ == DATES) {
    os << str_value_;
  } else if (attr_type_ == INTS || 
    attr_type_ == FLOATS || 
    attr_type_ == BOOLEANS ||
    attr_type_ == CHARS ||
    attr_type_ == TEXTS) {
    LOG_WARN("the type=%d cannot be casted to DATES", attr_type_);
  } else {
    LOG_WARN("unsupported attr type: %d", attr_type_);
  }
  return os.str();
}

std::string Value::get_text() const
{
  return this->to_string();
}

bool Value::check_valid() const
{
  if (attr_type_ == DATES) {
    return num_value_.date_meta_.check_valid();
  }
  return true;
}

void Value::cast_to_null(AttrType type)
{
  switch (type) 
  {
  case INTS:
    set_int(0);
    break;
  case FLOATS:
    set_float(0.0);
    break;
  case CHARS:
    set_string("");
    break;
  case DATES:
    set_date("2023-01-01");
    break;
  }
  is_null_ = true;
}

bool Value::cast_to_other_type(AttrType type)
{
  if (type == attr_type_) {
    return true;
  }
  if (type == TEXTS && attr_type_ == CHARS) {
    attr_type_ = TEXTS;
    return true;
  }
  if (type > FLOATS || attr_type_ > FLOATS || type == UNDEFINED || attr_type_ == UNDEFINED) {
    return false;
  }

  switch (type)
  {
  case CHARS: {
    set_string(get_string().c_str());
  } break;
  case INTS: {
    set_int(get_int());
  } break;
  case FLOATS: {
    set_float(get_float());
  } break;
  default:
    break;
  }

  return true;
}

void Value::DateMeta::set_date(const char *s)
{
  std::stringstream sstream(s);
  char c;
  sstream >> this->year >> c;
  sstream >> this->month >> c;
  sstream >> this->day;
}

int Value::DateMeta::compare(const DateMeta &meta) const
{
  if (this->year > meta.year)
		return 1;
	else if (this->year == meta.year) {
    if (this->month > meta.month) {
      return 1;
    } else if (this->month == meta.month) {
      if (this->day > meta.day) {
        return 1;
      } else if (this->day == meta.day) {
        return 0;
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
	return -1;
}

bool Value::DateMeta::check_valid() const
{
  if (year <= 0) {
        return false;
    }
    if (day <= 0) {
        return false;
    }
    bool isLeap = false; // if the year is a leap year
    if ((year%4 == 0 && year%100 != 0) || year % 400 == 0 ) {
        isLeap = true;
    }
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        if (day > 31)
            return false;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        if (day > 30)
            return false;
        break;
    case 2:
        if (isLeap) {
            if (day > 29) 
                return false;
        } else {
            if (day > 28)
                return false;
        }
        break;
    default:
        return false;
    }
    return true;
}

std::string Value::DateMeta::to_string() const
{
  std::stringstream sstream;
  std::string str;
  sstream << year << '-';
  str += sstream.str(); sstream.str("");
  sstream << std::setw(2) << std::setfill('0') << month;
  str += sstream.str() + '-'; sstream.str("");
  sstream << std::setw(2) << std::setfill('0') << day;
  str += sstream.str(); sstream.clear();
  return str;
}