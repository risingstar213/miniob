#include "util/date.h"
#include "common/log/log.h"

#include <iomanip>

bool Date::operator > (Date& d) const {
	if (this->year > d.year)
		return true;
	else if (this->year == d.year) {
        if (this->month > d.month) 
            return true;
        else if (this->month == d.month) 
            return this->day > d.day;
        return false;
    }
	return false;
}

bool Date::operator < (Date &d) const {
    if (this->year < d.year)
		return true;
	else if (this->year == d.year) {
        if (this->month < d.month) 
            return true;
        else if (this->month == d.month) 
            return this->day < d.day;
        return false;
    }
	return false;
}

bool Date::operator == (Date &d) const {
    return this->year == d.year && this->month == d.month && this->day == d.day;
}

bool Date::operator >= (Date &d) const {
    if (this->year > d.year)
		return true;
	else if (this->year == d.year) {
        if (this->month > d.month) 
            return true;
        else if (this->month == d.month) 
            return this->day >= d.day;
        return false;
    }
	return false;
}

bool Date::operator <= (Date &d) const {
    if (this->year < d.year)
		return true;
	else if (this->year == d.year) {
        if (this->month < d.month) 
            return true;
        else if (this->month == d.month) 
            return this->day <= d.day;
        return false;
    }
	return false;
}

void Date::set_date(string s) {
    std::stringstream sstream(s);
    char c;
    sstream >> this->year >> c;
    sstream >> this->month >> c;
    sstream >> this->day;
    int len = s.size();
    int found1, found2;
    found1 = s.find_first_of('-');
    found2 = s.find_last_of('-');
    month_space = found2 - found1 - 1;
    day_space = len - found2 - 1;
}

bool Date::is_valid() {
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

string Date::toString() {
    std::stringstream sstream;
    std::string str;
    sstream << year << '-';
    str += sstream.str(); sstream.str("");
    sstream << std::setw(month_space) << std::setfill('0') << month;
    str += sstream.str() + '-'; sstream.str("");
    sstream << std::setw(day_space) << std::setfill('0') << day;
    str += sstream.str(); sstream.clear();
    return str;
}