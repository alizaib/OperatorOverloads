#pragma once
#include <iostream>
#include "Log.h"
using namespace std;

class String
{
private:
	char* buff;
	void setValue(const char* s);
public:
	String();
	String(const char* s);
	explicit String(int);

	int length() const;	

	
	String& operator = (const String& other);	
	char operator[](int index);

	//type cast operators to other types
	// No return type is specifed as 
	// is implicitly taken to be the casting type by compiler
	operator char* ();
	operator int();

	// Drawback of operator int(); is that
	// if there is no operator << and you type cout<<stringObject
	// compiler will try to convert String to a type it can display
	// int in this case and will return junk
	// so avoid using implicit operator overload and use member functions
	// like AsInt()
	

	//insertion extraction operator
	friend ostream& operator<<(ostream&, const String&);
	friend istream& operator>>(istream&, String&);

	~String();
	
};
