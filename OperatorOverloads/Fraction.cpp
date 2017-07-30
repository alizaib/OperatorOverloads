#include "Fraction.h"

// constructors
Fraction::Fraction(int num, int denom) {
	this->numerator = num;
	this->denominator = denom;
	
	if (denominator == 0)
		denominator = 1;
	if (denominator < 0)
	{
		numerator = -numerator;
		denominator = abs(denominator);
	}
	int factor = Fraction::GCD(numerator, denominator);
	if(factor > 1)
	{
		numerator /= factor;
		denominator /= factor;
	}
}

Fraction::Fraction(int num) : Fraction(num, 1) {}

Fraction::Fraction(): Fraction(0, 1) {}

// member functions 
void Fraction::Display() {
	cout << this->numerator << "/" << this->denominator;
}

void Fraction::GetInput() {
	cout << "\nEnter Numerator: "; cin >> this->numerator;
	cout << "Enter Denominator: "; cin >> this->denominator;
}

// static functions
int Fraction::GCD(int first, int second) {
	int temp = 1;
	first = abs(first);
	second = abs(second);

	//swap the values for the purpose of division
	if (first < second) {
		int swap = first;
		first = second;
		second = swap;
	}

	while (second != 0) {
		temp = first % second;
		first = second;
		second = temp;
	}
	return first;
}

int Fraction::LCM(int first, int second) {
	return first * second / Fraction::GCD(first, second);
}

// operator overloads
Fraction Fraction::operator+(const Fraction& other) {
	int lcm = Fraction::LCM(this->denominator, other.denominator);
	int part1 = lcm * (this->numerator) / this->denominator;
	int part2 = lcm * (other.numerator) / other.denominator;

	return Fraction(part1 + part2, lcm);

	/*int factor, mult1, mult2;
	factor = Fraction::GCD(denominator, other.denominator);
	mult1 = denominator / factor;
	mult2 = other.denominator / factor;
	return Fraction(numerator * mult2 + other.numerator * mult1,
		denominator * mult2);*/
}

Fraction Fraction::operator-(const Fraction& other) {
	int lcm = Fraction::LCM(this->denominator, other.denominator);
	int part1 = lcm * (this->numerator) / this->denominator;
	int part2 = lcm * (other.numerator) / other.denominator;

	return Fraction(part1 - part2, lcm);

	/*int factor, mult1, mult2;
	factor = Fraction::GCD(denominator, other.denominator);
	mult1 = denominator / factor;
	mult2 = other.denominator / factor;
	return Fraction(numerator * mult2 + other.numerator * mult1,
	denominator * mult2);*/
}

Fraction Fraction::operator*(const Fraction& other)
{
	return Fraction(numerator*other.numerator, denominator*other.denominator);
}

Fraction Fraction::operator/(const Fraction& other)
{
	return Fraction(numerator*other.denominator, denominator*other.numerator);
}