#include "Date.h"
#include <iostream>
using namespace std;

const int Date::DaysInMonth[] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

// Constrcutors
Date::Date(int d, int m, int y) {
	cout << "\nInside Constructor of Date\n";
	SetDate(d, m, y);
}

Date::~Date() {
	cout << "\nInside Destructor of Date\n";
}

// Private member funtions
bool Date::LeapYear(int y) {
	if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)
		return true;
	return false;
}

int Date::DaysOfMonth(Date d) {
	if (LeapYear(d.year) && d.month == 2)
		return 29;
	return DaysInMonth[d.month];
}

// Public member funtions
void Date::SetDate(int d, int m, int y) {
	this->year = y;

	if (m >= 1 && m <= 12)
		month = m;
	else
		month = 1;

	if (m == 2 && LeapYear(y)) {
		if (d >= 1 && d <= 29)
			day = d;
		else
			day = 1;
	}
	else {
		if (d >= 1 && d <= DaysInMonth[m])
			day = d;
		else
			day = 1;
	}

}

void Date::Display() {
	cout << "\nDate:" << day << "-" << month << "-" << year;
}

Date Date::operator + (int numOfDays) {
	for (int i = 1; i <= numOfDays; i++) {
		++(*this);
	}
	return *this;
}

Date Date::operator ++ () {
	if (day == DaysOfMonth(*this) && month == 12) {
		day = 1;
		month = 1;
		year++;
	}
	else if (day == DaysOfMonth(*this)) {
		day = 1;
		month++;
	}
	else {
		day++;
	}
	return *this;
}

Date Date::operator += (int numOfDays) {
	return *this + numOfDays;
}

bool Date::operator < (Date d) {
	if (this->year < d.year)
		return true;
	else if (this->year > d.year)
		return false;
	else {
		if (this->month < d.month)
			return true;
		else if (this->month > d.month)
			return false;
		else {
			if (this->day < d.day)
				return true;
			else if (this->day >= d.day)
				return false;
		}
	}
}

bool Date::operator > (Date d) {
	return !(*this < d);
}
