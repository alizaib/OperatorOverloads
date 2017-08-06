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

	void output(ostream &os) const;
	const Matrix& input(istream &is);

	const Matrix& operator=(const Matrix&);

	Matrix operator*(const Matrix&);
	Matrix operator*(const double);
	friend Matrix operator*(const double, const Matrix&);

	const Matrix& Transpose();
};