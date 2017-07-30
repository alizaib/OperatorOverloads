#pragma once
#include <iostream>
using namespace std;

class Matrix
{
private:
	int* m;
	int rows, cols;
public:
	Matrix(const Matrix& other)
	{
		cout << "\nInside copy constructor\n";
		this->rows = other.rows;
		this->cols = other.cols;

		m = new int[other.rows*other.cols];
	}

	Matrix(int rows, int cols)
	{
		this->rows = rows;
		this->cols = cols;

		m = new int[rows * cols];
	}
	void DisplayPointerAddress()
	{
		cout << &m;
	}

	Matrix& operator = (const Matrix& other)
	{
		cout << "\nInside assignment operator\n";
		// check for self reference
		if (&other == this)
			return *this;

		this->rows = other.rows;
		this->cols = other.cols;

		m = new int[other.rows*other.cols];

		return *this;
	}
	~Matrix() {
		delete[] m;
	}
};