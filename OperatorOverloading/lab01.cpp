/* 미완성된 코드입니다!!! 
   해결해야 할 점 : Assignment operator를 만들어서 Shallow Copy가 일어나지 않게 해야함!
*/

#include <iostream>

using namespace std;

class Matrix {
	int** values;
	int row, column;
public:
	Matrix(const int _row = 2, const int _column = 2) {
		this->row = _row;
		this->column = _column;
		values = new int*[row];
		for( int i = 0; i < column; i++ ) {
			*(values + i) = new int[2];
		}
	}
	
	
	~Matrix() { 
		for( int i = 0; i < column; i++ ){
			delete [] *(values + i);
		}
		delete [] values;
	}
		

	Matrix(const Matrix& m) {
		this->row = m.row;
		this->column = m.column;
		this->values = m.values;		// ?
	}

	void set(const int row, const int column, const int value) {
		this->values[row][column] = value;
	}

	int getRow() {
		return this->row;
	}

	int getColumn() {
		return this->column;
	}

	int getValues(int row, int column) {
		return values[row][column];
	}

	friend istream& operator >> (istream& is, const Matrix& m);
	friend ostream& operator << (ostream& os, const Matrix& m);

	Matrix operator + (Matrix& m) {
		Matrix tmpMatrix;
		for (int i = 0; i < m.getRow(); i++) {
			for (int j = 0; j < m.getColumn(); j++) {
				int tmpValue = this->getValues(i, j) + m.getValues(i, j);

				tmpMatrix.set(i, j, tmpValue);
			}
		}
		return tmpMatrix;
	}

	Matrix operator * (int number) const {
		Matrix tmpMatrix;
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				int tmpValue = values[i][j] * number;
				tmpMatrix.set(i, j, tmpValue);
			}
		}
		return tmpMatrix;
	}
};

istream& operator >> (istream& is, Matrix& m) {
	for (int i = 0; i < m.getRow(); i++) {
		for (int j = 0; j < m.getColumn(); j++) {
			int tmp;
			is >> tmp;
			m.set(i, j, tmp);
		}
	}
	return is;
}

ostream& operator << (ostream& os, Matrix& m) {
	for (int i = 0; i < m.getRow(); i++) {
		for (int j = 0; j < m.getColumn(); j++) {
			os << m.getValues(i, j) << '\t';
		}
		os << endl;
	}
	return os;
}


int main() {
	Matrix m1(2, 2), m2(2, 2);
	cin >> m1;
	cin >> m2;

	Matrix m3(m1 + m2);
	Matrix m4(2, 2);

	m4 = m3 * 10;

	cout << m3 << endl << m4 << endl;
	return 0;
}
