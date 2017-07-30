#include "Person.h"
#include <string.h>
#include <iostream>
using namespace std;

Person::Person(const char* name, int day, int month, int year) : dob(day, month, year) {
	cout << "\nInside Person Constructor\n";
	Name = new char[strlen(name)];
	strcpy(Name, name);
}
Person::~Person() {
	cout << "\nInside destructor of Person";
}

void Person::DisplayInfo() {
	cout << Name;
	cout << "\nDate of birth: ";
	dob.Display();
}