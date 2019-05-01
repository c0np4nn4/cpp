#include <iostream>

using namespace std;

class Point{
	int x, y;	// default is private
public:
	Point operator + (const Point& p) const {
		return Point(x+p.x, y+p.y);
	}
};

int main() {
	Point pt1, pt2;			/* Declare 2 Point class object with 'default constructor' */
	Point pt3( pt1 + pt2 );		/* Declare another Point class object with 'default copy constructor' */
}					/* with Operator Overloading...
					   using operator + when the type of operand is 'Point' is not declared in default settings
					   So, you should make overloading code in source file */ 
