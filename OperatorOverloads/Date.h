#pragma once
#include "Log.h"

class Date {
private:
	int day, month, year;
	int DaysOfMonth(Date d);
	static const int DaysInMonth[];
	bool LeapYear(int year);

public:
	Date(int day = 1, int month = 1, int year = 1990);
	~Date();
	void SetDate(int day, int month, int year);	

	friend ostream& operator << (ostream&, const Date&);

	//operator overloads
	Date operator + (int numOfDays);
	Date operator ++ ();
	Date operator += (int numOfDays);
	bool operator < (Date d);
	bool operator > (Date d);
};

