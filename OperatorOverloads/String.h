#pragma once
#include <iostream>
using namespace std;

class String
{
private:
	char* buff;
public:
	String() 
	{ 
		buff = new char[30];
		strcpy(buff, "");
	}
	String(const char* s)
	{
		buff = new char[30];
		strcpy(buff, s);
	}
	void Display()
	{
		cout << buff << endl;
	}
	int length() const
	{
		return strlen(buff);
	}

	String& operator = (const String& other) 
	{
		if (this == &other)
			return *this;
		int length = other.length();
		delete buff;
		buff = new char[length + 1];
		strcpy(buff, other.buff);
		return *this;
	}
	~String()
	{
		delete[] buff;
	}
};
