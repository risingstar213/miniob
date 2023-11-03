#include <cstring>
#include <cmath>
#include <sstream>
#include <iomanip>
#include <string>

#include "sql/utils/function.h"
#include "sql/parser/value.h"


float execute_round(float x, int y) {
  for (int i = 0; i < y; i++) {
    x *= 10;
  }
  x = round(x);
  for (int i = 0; i < y; i++) {
    x /= 10;
  }
  return x;
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

std::string execute_format(std::string data, std::string format)
{
  Value::DateMeta meta;
  meta.set_date(data.c_str());
  std::stringstream sstream;

  std::string Y = std::to_string(meta.year);
  sstream << std::setw(2) << std::setfill('0') << meta.year % 100;
  std::string y = sstream.str(); sstream.str("");

  std::string M = month_name[meta.month];
  sstream << std::setw(2) << std::setfill('0') << meta.month;
  std::string m = sstream.str(); sstream.str("");
  
  sstream << meta.day << suffix(meta.day);
  std::string D = sstream.str(); sstream.str("");
  
  sstream << std::setw(2) << std::setfill('0') << meta.day;
  std::string d = sstream.str(); sstream.str("");

  int pos = 0;
  while((pos=format.find("%Y",pos))!=std::string::npos)
	{
		format.replace(pos,2,Y);
		pos+=Y.size();
	}
  pos = 0;
  while((pos=format.find("%y",pos))!=std::string::npos)
	{
		format.replace(pos,2,y);
		pos+=y.size();
	}
  pos = 0;
  while((pos=format.find("%M",pos))!=std::string::npos)
	{
		format.replace(pos,2,M);
		pos+=M.size();
	}
  pos = 0;
  while((pos=format.find("%m",pos))!=std::string::npos)
	{
		format.replace(pos,2,m);
		pos+=m.size();
	}
  pos = 0;
  while((pos=format.find("%D",pos))!=std::string::npos)
	{
		format.replace(pos,2,D);
		pos+=D.size();
	}
  pos = 0;
  while((pos=format.find("%d",pos))!=std::string::npos)
	{
		format.replace(pos,2,d);
		pos+=d.size();
	}
  pos = 0;
  while((pos=format.find("%",pos))!=std::string::npos)
	{
		format.replace(pos,1,"");
	}
  return format;
}