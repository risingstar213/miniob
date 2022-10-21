#include "util/date.h"

bool Date::operator > (Date& d) const {
	if (this->year > d.year)
		return true;
	else if (this->year == d.year) {
        if (this->month > this->month) 
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
        if (this->month < this->month) 
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
        if (this->month > this->month) 
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
        if (this->month < this->month) 
            return true;
        else if (this->month == d.month) 
            return this->day <= d.day;
        return false;
    }
	return false;
}

void Date::set_date(string s) {
    int len = s.size();

    std::stringstream sstream(s);
    char c;
    sstream >> this->year >> c;
    sstream >> this->month >> c;
    sstream >> this->day;
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
    return std::to_string(this->year) + "-" + std::to_string(this->month) + "-" + std::to_string(this->day);
}