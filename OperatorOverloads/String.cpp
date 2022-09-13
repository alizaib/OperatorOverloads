#include "String.h"

String::String() : buff(NULL) {
	Log("Inside default constructor of string");
	buff = new char[30];
	strcpy(buff, "");
}

String::String(const char* s) : buff(NULL) {
	Log("Inside overloaded constructor (const char*) of string");
	/*buff = new char[30];
	strcpy(buff, s);*/
	setValue(s);
}

String::String(int num) {	
	buff = new char[30];	
	itoa(num, buff, 10);
}

void String::setValue(const char* s) {	
	if(buff != nullptr)
		delete[] buff;

	buff = new char[30];
	strcpy(buff, s);
}

int String::length() const {
	return strlen(buff);
}

String& String::operator = (const String& other)
{
	Log("Inside assignment operator of string");
	if (this == &other)
		return *this;
	int length = other.length();
	delete buff;
	buff = new char[length + 1];
	strcpy(buff, other.buff);
	return *this;
}

char String::operator[](int index) {
	if (index < length()) {
		return buff[index];
	}
	else {
		return '0'; // for now
	}
}

String::operator char* () {
	return buff;
}
String::operator int() {
	if (length() > 0) {
		return atoi(buff);
	}
	else {
		return -1;
	}
}

String& String::operator=(const char* s) {
	Log("Inside operator =  of string");
	if (buff != nullptr)
		delete[] buff;

	buff = new char[30];
	strcpy(buff, s);

	return *this;
}


//insertion extraction operator
ostream& operator<<(ostream& os, const String& s) {
	os << s.buff;

	return os;
}

istream& operator>>(istream& is, String& s) {
	char c[30];
	is >> c;
	s.setValue(c);

	return is;
}

//destructor
String::~String() {
	Log("Inside destructor of string");
	delete[] buff;
}