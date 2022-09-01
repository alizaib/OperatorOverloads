#include "Person.h"

Person::Person(const char* name, int day, int month, int year) 
			: dob(day, month, year), Id(day+month+year) {

	Log("\nInside Person Constructor\n");
	Name = new char[strlen(name)];
	strcpy(Name, name);	
}
Person::~Person() {
	Log("\nInside destructor of Person");
}

ostream& operator << (ostream& os, const Person& p) {
	os << p.Name;
	os << "\nDate of birth: ";
	os << p.dob;

	return os;
}