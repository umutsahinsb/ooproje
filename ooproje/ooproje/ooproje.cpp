#include <iostream>
#include <string>
using namespace std;

class Point {
private:
	double x;
	double y;
	double z;
public:
	Point();
	//set/get functions...
	double distance(const Point&) const;
	Point operator == (Point const&);
};

class PointCloud :public Point {
private:
	Point* points;
	int pointNumber;
public:
	PointCloud();
	//set/get functions...
	PointCloud operator + (PointCloud const&);
	PointCloud operator = (PointCloud const&);
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