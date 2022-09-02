#include "Person.h"

int Person::count = 0;

Person::Person(const char* name, int day, int month, int year) 
			: Name(name), dob(day, month, year), Id(day+month+year) {

	Log("Inside Person Constructor");	
	Person::count++;
}
Person::~Person() {
	Log("Inside destructor of Person");
	Person::count--;
}

ostream& operator << (ostream& os, const Person& p) {
	os << p.Name;
	os << "\nDate of birth: ";
	os << p.dob;

	return os;
}