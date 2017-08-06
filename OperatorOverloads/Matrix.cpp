#include "Matrix.h"

Matrix::Matrix(int rows, int cols) {
	this->rows = rows;
	this->cols = cols;

	elements = new double*[rows];
	for (int i = 0; i < rows; i++) {
		elements[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			elements[i][j] = 0.0;
	}
}

Matrix::Matrix(const Matrix& m) {
	rows = m.rows;
	cols = m.cols;

	elements = new double*[rows];
	for (int i = 0; i < rows; i++) {
		elements[i] = new double[cols];
		for (int j = 0; j < cols; j++)
			elements[i][j] = m.elements[i][j];
	}
}
Matrix::~Matrix() {
	delete[] elements;
}

int Matrix::getRows() const { return rows; }
int Matrix::getCols() const { return cols; }

void Matrix::output(ostream &os) const {
	os.setf(ios::showpoint);
	os.setf(ios::fixed, ios::floatfield);

	//print first row
	os << endl << (char)218;
	for (int j = 0; j < cols; j++)
		os << setw(10) << "";
	os << (char)191 << endl;

	//print matrix value with bars at start and end
	for (int i = 0; i < rows; i++) {
		os << (char)179;
		for (int j = 0; j < cols; j++)
			os << setw(10) << setprecision(2) << elements[i][j];
		os << (char)179 << endl;
	}

	//print last row
	os << (char)192;
	for (int j = 0; j < cols; j++)
		os << setw(10) << "";
	os << (char)217 << endl;
}
const Matrix& Matrix::input(istream &is) {
	cout << "Input Matrix size:" << rows << " rows by " << cols << " columns \n";
	for (int i = 0; i < rows; i++) {
		cout << "Please enter " << cols << " values separated by spaces for row " << i + 1 << ":  ";
		for (int j = 0; j < cols; j++)
			is >> elements[i][j];
	}
	return *this;
}

const Matrix& Matrix::operator=(const Matrix& m) {
	if (&m != this) { //check if both m and this are not refering to the same location
		if (m.cols != this->cols || m.rows != this->rows) {
			delete[] elements;
			elements = new double*[m.rows];
			for (int i = 0; i < m.rows; i++) {
				elements[i] = new double[m.cols];
			}
		}
		rows = m.rows;
		cols = m.cols;
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				elements[i][j] = m.elements[i][j];
			}
		}
	}
	return *this;
}
Matrix Matrix::operator*(const Matrix& m) {
	Matrix temp(rows, m.cols);
	//compatiblity check
	if (cols == m.rows) {
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < m.cols; j++) {
				temp.elements[i][j] = 0.0;
				for (int k = 0; k < m.rows; k++) {
					temp.elements[i][j] += elements[i][k] * m.elements[k][j];
				}
			}
		}
	}
	return temp;
}

Matrix Matrix::operator*(const double d) {
	Matrix temp(*this);
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
			temp.elements[i][j] = temp.elements[i][j] * d;
	return temp;
}

Matrix operator*(const double d, const Matrix& m) {
	Matrix temp(m);
	temp = temp * d;
	return temp;
}

const Matrix& Matrix::Transpose() {
	//if this is square matrix
	if (rows == cols) {
		for (int i = 0; i < rows; i++) {
			for (int j = i+1; j < cols; j++) {
				double elem = elements[i][j];
				elements[i][j] = elements[j][i];
				elements[j][i] = elem;
			}
		}
	}
	else {
		Matrix temp(cols, rows);
		for (int i = 0; i < rows; i++) {
			for (int j = 0; j < cols; j++) {
				temp.elements[j][i] = elements[i][j];
			}
		}
		*this = temp;
	}
	return *this;
}