#pragma once
#include "Date.h"
#include <string.h>
#include "Log.h"

class Person {
private:
	const int Id;	
	char* Name;
	Date dob;
public:
	Person(const char* name, int day, int month, int year);
	~Person();

	friend ostream& operator << (ostream&, const Person&);	
};