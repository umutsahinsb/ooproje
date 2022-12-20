#include <iostream>
#include <string>
using namespace std;

class Point {
private:
	double x = 0, y = 0, z = 0;
public:
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
	double getPoints() {				//	umut
		double x, y, z;
		cout << "Enter x, y and z points: ";
		cin >> x >> y >> z;
		Point::x = x;
		Point::y = y;
		Point::z = z;
		return x, y, z;
	}
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

};

class PointCloud :public Point {
private:
	Point* points;
	int pointNumber;
public:
	PointCloud(int pointNumber) {			//	umut
		this->points = points;
		points = new Point[pointNumber];
	}
};

class Transform :public PointCloud {
private:
	double angles[3];
	double trans[3];
	double transMatrix[4][4];
public:
	Transform();
	//set/get functions...
	void setRotation(double ang[]);
	void setTranslation(double tr[]);
	Point doTransform(Point p);
	PointCloud doTransform(PointCloud pc);
};

class PointCloudRecorder :public PointCloud {
private:
	string fileName;
public:
	PointCloudRecorder();
	//set/get functions...
	bool save(const PointCloud& pc);
};

class DepthCamera : public PointCloud {
private:
	string fileName;
public:
	DepthCamera();
	//set/get functions...
	PointCloud capture();
};

class ThreeDGridMap : public PointCloud {  // 3DGridMap þeklinde yazýnca hata veriyordu ThreeD yazdým
private:
	bool map[][][]; // burayý yapamadým
	float gridSize;
	int depth;
public:
	ThreeDGridMap();
	//set/get functions...
	void insertPointCloud(PointCloud& pc);
	void insertPoint(Point& p);
	bool getGrid(int x, int y, int z) const;
	bool loadMap(string fileName); // fonk. içindeki fileName'in türü belli deðildi böyle yaptým
	bool saveMap(string fileName); // bir üstteki fonk. ile ayný durum mevcut
};