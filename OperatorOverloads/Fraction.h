#pragma once
#include <iostream>
#include <math.h>
using namespace std;

class Fraction {
private:
	int numerator, denominator;
public:
	Fraction();
	Fraction(int num); // This constructor will be used as conversion function for statment like Fraction f1 = 3;
	Fraction(int num, int denom);

	//static functions
	static int LCM(int first, int second);
	static int GCD(int first, int second);

	// member functions
	void Display();
	void GetInput();

	// operator overloads
	Fraction operator+(const Fraction& other);
	Fraction operator-(const Fraction&  other);
	Fraction operator*(const Fraction& other);
	Fraction operator/(const Fraction& other);
};
