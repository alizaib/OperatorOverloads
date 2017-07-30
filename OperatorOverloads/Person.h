#pragma once
#include "Date.h"
class Person {
private:
	char* Name;
	Date dob;
public:
	Person(const char* name, int day, int month, int year);
	~Person();
	void DisplayInfo();
};