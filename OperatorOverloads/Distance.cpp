#include "Distance.h"

//Constructors
Distance::Distance(int feet, int inches) {
	this->feet = feet;
	this->inches = inches;
	//cout<<"\nconstructor with two parameters has been called";
}
Distance::Distance(int feet) : Distance(feet, 0) {
	//cout<<"\nconstructor with one parameter has been called";
}
Distance::Distance() : Distance(0, 0) {
	//cout<<"\nconstructor with Zero parameters has been called";
}

//Member Functions
istream& operator >> (istream& input, Distance& d) {
	cout << "\nEnter feets: "; input >> d.feet;
	cout << "\nEnter inches: "; input >> d.inches;
	return input;
}
void Distance::Display() {
	cout << "\nfeets: " << feet << "\tinches: " << inches;
}

ostream& operator << (ostream& output, Distance& d)
{	
	output << "\nfeets: " << d.feet << "\tinches: " << d.inches;
	return output;
}

//Operator Overloads
Distance Distance::operator + (Distance d) {
	Distance temp;
	temp.feet = this->feet + d.feet;
	temp.inches = this->inches + d.inches;
	if (temp.inches >= 12) {
		temp.feet++;
		temp.inches %= 12;
	}
	return temp;
}
Distance Distance::operator - (Distance d) {
	Distance temp;
	int carry = 0;

	if (this->inches < d.inches) {
		this->inches += 12;
		carry = 1;
	}
	temp.inches = this->inches - d.inches;
	temp.feet = this->feet - d.feet - carry;

	return temp;
}
void Distance::operator += (Distance d) {
	this->feet += d.feet;
	this->inches += d.inches;
	if (this->inches >= 12) {
		this->inches %= 12;
		this->feet++;
	}
}
void Distance::operator -= (Distance d) {
	int carry = 0;
	if (this->inches < d.inches) {
		this->inches += 12;
		carry = 1;
	}
	this->inches -= d.inches;
	this->feet = this->feet - d.feet - carry;
}
Distance operator + (Distance d, int num) {
	Distance temp;
	temp.feet = d.feet + num;
	temp.inches = d.inches;
	return temp;
}
Distance operator + (int num, Distance d) {
	Distance temp;
	temp.feet = d.feet + num;
	temp.inches = d.inches;
	return temp;
}

Distance Distance::operator ++ () {
	this->feet++;
	return *this;
}

Distance Distance::operator ++ (int) {
	this->feet++;
	return *this;
}


