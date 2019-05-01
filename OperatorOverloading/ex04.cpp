#include <iostream>

using namespace std;

class Complex {
	double re, im;			// real number, imaginary number
public:
	Complex(double re = 0, double im = 0) { this->re = re; this->im = im; }

	Complex operator + (const Complex& c) const { return Complex(re+c.re, im+c.im); }
	bool operator == (const Complex& c) const { return re == c.re && im == c.im; }
	bool operator != (const Complex& c) const { return !this->operator == (c); }
};

int main() {
	Complex c1(1, 0), c2(2, 1);
	Complex c3( c1 + c2 );
	if( c3 == Complex(3, 1) )
		cout << "They are same" << endl;
	else if( c3 != Complex(3, 1) )
		cout << "They are different" << endl;
}
