#include <iostream>

using namespace std;

class Point{
	int x, y;
public:
	Point (int _x = 0, int _y = 0) {
		this->x = _x;
		this->y = _y;
	}
	friend Point operator + (const Point& p1, const Point&p2);	/* for private members... */
};

Point operator + (const Point& p1, const Point& p2) { /* Declare operator overloading outside of class!  */
	return Point(p1.x+p2.x, p1.y+p2.y);
}

int main() {
	Point pt1, pt2;
	Point pt3(pt1 + pt2);

	return 0;
}
