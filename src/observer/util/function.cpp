#include <cstring>
#include <cmath>
#include <sstream>
#include <iomanip>

#include "util/function.h"
#include "util/date.h"

char *execute_length(const char *data)
{
  int *number_ = new int;
  *number_ = strlen(data);
  return (char *)number_;
}

static float execute_round(float x, int y) {
  for (int i = 0; i < y; i++) {
    x *= 10;
  }
  x = round(x);
  for (int i = 0; i < y; i++) {
    x /= 10;
  }
  return x;
}

char *execute_round(const char *data, char *round_len)
{
  float number = *(float *)data;
  int round_ = (round_len != nullptr) ? *(int *)round_len : 0;
  number = execute_round(number, round_);
  float *number_ = new float;
  *number_ = number;
  return (char *)number_;
}

const char *month_name[13] = {
  "illegal month","January","February",
  "March","April","May","June","July","August",
  "September","October","November","December"
};

const char * suffix(int day) {
  switch(day) {
    case 1:
    case 21:
    case 31:
      return "st";
    case 2:
    case 22:
      return "nd";
    case 3:
    case 23:
      return "rd";
    default:
      return "th";
  }
}

char *execute_format(const char *data, char *format)
{
  Date *date = (Date *)data;
  std::stringstream sstream;
  if (format[1] == 'Y') {
    sstream << date->getYear();
  } else {
    sstream << date->getYear() % 100;
  }
  sstream << format[2];
  if (format[4] == 'M') {
    sstream << month_name[date->getMonth()];
  } else {
    sstream << std::setw(2) << std::setfill('0') << date->getMonth();
  }
  sstream << format[5];
  if (format[7] == 'D') {
    sstream << std::setw(2) << std::setfill('0') << date->getDay() << suffix(date->getDay());
  } else {
    sstream << std::setw(2) << std::setfill('0') << date->getDay();
  }

  return strdup(sstream.str().c_str());
}