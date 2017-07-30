#pragma once
#include <iostream>
using namespace std;

class Distance {
private:
	int feet, inches;
public:
	// constructors
	Distance();
	Distance(int);
	Distance(int, int);

	//member functions
	void GetDistance();
	void Display();
	
	//operator overloads
	Distance operator + (Distance);
	Distance operator - (Distance);
	void operator += (Distance);
	void operator -= (Distance);
	Distance operator ++();
	Distance operator ++ (int);  //pre increment like ++d

								 //friends operator functions
	friend Distance operator + (Distance, int);
	friend Distance operator + (int, Distance);

	friend ostream& operator << (ostream&, Distance&);
	friend istream& operator >> (istream&, Distance&);
};