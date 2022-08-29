#pragma once
#include <iostream>
#include <ostream>
#include <iomanip>
using namespace std;
class Matrix
{
private:
	double **elements;
	int rows, cols;
public:
	Matrix(int rows = 0, int cols = 0);
	Matrix(const Matrix& m);
	~Matrix();

	int getRows() const;
	int getCols() const;
	

	const Matrix& operator=(const Matrix&);
	Matrix operator*(const Matrix&);
	Matrix operator*(const double);
	friend Matrix operator*(const double, const Matrix&);

	friend ostream& operator<<(ostream&, const Matrix&);
	friend istream& operator>>(istream&, const Matrix&);

	const Matrix& Transpose();
};