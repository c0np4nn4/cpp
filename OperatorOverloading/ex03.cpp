#include <iostream>

using namespace std;

class Complex { 			//Complex number
	double re, im;			// re == real_number , im == imaginary number
public:
	Complex(double re = 0, double im = 0) { this->re = re; this->im = im; } // constructor with default values
	Complex operator + (const Complex& c) const { return Complex(re + c.re, im + c.im); } // Operator Overloading
	Complex operator - (const Complex& c) const { return Complex(re - c.re, im - c.im); } // Operator Overloading
	friend ostream & operator << (ostream& os, const Complex& c);		// friend
};

ostream& operator << (ostream& os, const Complex& c) {		// friend .. for private variables..
	os << c.re << " + " << c.im << "i";
	return os;						// return os-which is cout.
}

int main() {
	Complex c1(1, 0), c2(2, 1);
	Complex c3(c1 + c2);
	Complex c4(c1 - c2);
	cout << c3 << c4 << endl;
}
