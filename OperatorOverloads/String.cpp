#include "String.h"

void String::setValue(const char* s) {
	delete[] buff;

	buff = new char[30];
	strcpy(buff, s);
}

String::String() {
	buff = new char[30];
	strcpy(buff, "");
}

String::String(const char* s) {
	buff = new char[30];
	strcpy(buff, s);
}

String::String(int num) {	
	buff = new char[30];	
	itoa(num, buff, 10);
}

int String::length() const {
	return strlen(buff);
}

String& String::operator = (const String& other)
{
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
	delete[] buff;
}