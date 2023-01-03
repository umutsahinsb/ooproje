#include "Point.h"

class PointCloud :public Point {
public:
	list <PointCloud> points;
	int pointNumber = 0;
	PointCloud(int pointNumber) {			//	umut
		this->pointNumber = pointNumber;
	}
	// inheritance kullandigimiz icin default constructor hatasi
	// aliyoruz. bundan kurtulmak icin boyle yaziyorum.					// umut
	PointCloud() {}

	list<PointCloud> setPointCloud(double x, double y, double z) {
		points.clear();
		points.push_back(x);
		points.push_back(y);
		points.push_back(z);
		this->x = x;
		this->y = y;
		this->z = z;
		return points;
	}
	list<PointCloud> setPointCloud(double x, double y, double z, double x1, double y1, double z1) {
		points.clear();
		Point p1, p2;
		points.push_back(x);
		points.push_back(y);
		points.push_back(z);
		points.push_back(x1);
		points.push_back(y1);
		points.push_back(z1);
		p1.setPoints(x, y, z);
		p2.setPoints(x1, y1, z1);
		return points;

	}
	void getPointCloud() {
		if (this->pointNumber == 3) {
			cout << "x: " << points.front();
			points.pop_front();
			cout << "y: " << points.front();
			points.pop_front();
			cout << "z: " << points.front();
			points.pop_front();
		}
		else {
			cout << "x: " << points.front();
			points.pop_front();
			cout << "y: " << points.front();
			points.pop_front();
			cout << "z: " << points.front();
			points.pop_front();
			cout << "   " << points.front();
			points.pop_front();
			cout << "   " << points.front();
			points.pop_front();
			cout << "   " << points.front();
			points.pop_front();
		}
	}
	void getPointCloud1() {


	}
	PointCloud operator+(PointCloud& a) {
		PointCloud npc(6);
		npc.setPointCloud(this->x, this->y, this->z, a.x, a.y, a.z);
		cout << "\nIki nokta bulutunun toplami:\n";


		return npc;
	}
	Point operator=(Point& a) {
		Point kopya;
		kopya.x = a.x;
		kopya.y = a.y;
		kopya.z = a.z;
		return kopya;
	}
};
