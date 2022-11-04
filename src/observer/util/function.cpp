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
  std::string format_ = format;

  std::string Y = std::to_string(date->getYear());
  std::string y = std::to_string(date->getYear() % 100);

  std::string M = month_name[date->getMonth()];
  sstream << std::setw(2) << std::setfill('0') << date->getMonth();
  std::string m = sstream.str(); sstream.str("");
  
  sstream << date->getDay() << suffix(date->getDay());
  std::string D = sstream.str(); sstream.str("");
  
  sstream << std::setw(2) << std::setfill('0') << date->getDay();
  std::string d = sstream.str(); sstream.str("");

  int pos = 0;
  while((pos=format_.find("%Y",pos))!=string::npos)
	{
		format_.replace(pos,2,Y);
		pos+=Y.size();
	}
  pos = 0;
  while((pos=format_.find("%y",pos))!=string::npos)
	{
		format_.replace(pos,2,y);
		pos+=y.size();
	}
  pos = 0;
  while((pos=format_.find("%M",pos))!=string::npos)
	{
		format_.replace(pos,2,M);
		pos+=M.size();
	}
  pos = 0;
  while((pos=format_.find("%m",pos))!=string::npos)
	{
		format_.replace(pos,2,m);
		pos+=m.size();
	}
  pos = 0;
  while((pos=format_.find("%D",pos))!=string::npos)
	{
		format_.replace(pos,2,D);
		pos+=D.size();
	}
  pos = 0;
  while((pos=format_.find("%d",pos))!=string::npos)
	{
		format_.replace(pos,2,d);
		pos+=d.size();
	}
  pos = 0;
  while((pos=format_.find("%",pos))!=string::npos)
	{
		format_.replace(pos,1,"");
	}
  return strdup(format_.c_str());
}