#ifndef _DATE_H_
#define _DATE_H_

#include <iostream>
#include <string>
#include <sstream>
using std::string;

class Date {
    private:
		int month = 0;
		int day = 0;
		int year = 0;

    public:
        Date() = default;
        int getMonth() {return month;}
        int getDay() {return day;}
        int getYear() {return year;}

        bool operator > (Date&) const;
        bool operator >= (Date&) const;
        bool operator == (Date&) const;
        bool operator < (Date&) const;
        bool operator <= (Date&) const;

        void set_date(string s);
        bool is_valid();

        string toString();
};

#endif