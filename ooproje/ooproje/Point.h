#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <iterator>
#include <list>
#include <vector>
#define PI 3,14
using namespace std;

///////						ONEMLI				////////
/*iplikci nedim gibi yorum yazin lutfen, turkce harf kullanmayin github bozuyor tsk.*/
///////						ONEMLI				////////

// point ok
class Point {
public:
	double x = 0, y = 0, z = 0;
	Point() {							//	umut
		this->x = x;
		this->y = y;
		this->z = z;
	}
	~Point() {							//	umut
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}
	/*noktalari ekrana basiyor*/
	void getPoints() {					//	umut
		cout << "x:" << x << " y:" << y << " z:" << z << endl;
	}
	/*noktalari ayarliyor/degistiriyor*/
	double setPoints(double x, double y, double z) {
		this->x = x;
		this->y = y;
		this->z = z;
		return x, y, z;
	}
	/*esit esit == yazimi*/
	bool operator==(Point a) {
		if (Point::x == a.x && Point::y == a.y && Point::z == a.z) {
			cout << "both points are equal.";
			return 1;
		}
		else {
			cout << "not equal.";
			return 0;
		}
	}
	double distance(const Point& a) const {
		double dist;
		dist = sqrt(pow((Point::x - a.x), 2) + pow((Point::y - a.y), 2) + pow((Point::z - a.z), 2));
		cout << "the distance is: " << dist;
		return dist;
	}

};

ostream& operator<<(ostream& os, const Point& dt)
{
	os << dt.x << '/' << dt.y << '/' << dt.z;
	return os;
}
