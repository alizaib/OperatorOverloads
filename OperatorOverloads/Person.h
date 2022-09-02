#pragma once
#include "Date.h"
#include "String.h"
#include "Log.h"

class Person {
private:
	const int Id;	
	String Name;
	Date dob;
public:
	static int count;

	Person(const char* name, int day, int month, int year);
	~Person();

	friend ostream& operator << (ostream&, const Person&);	
};
