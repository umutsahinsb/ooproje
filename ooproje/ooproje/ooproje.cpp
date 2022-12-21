#include <iostream>
#include <string>
#include <math.h>
using namespace std;

///////						ONEMLI				////////
/*iplikci nedim gibi yorum yazin lutfen, turkce harf kullanmayin github bozuyor tsk.*/
///////						ONEMLI				////////

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
	double setPoints(double x,double y,double z) {
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

class PointCloud :public Point {
	friend ostream& operator<<(ostream& o, const PointCloud& vect);
	friend istream& operator>>(istream& in, PointCloud& vect);
private:
	Point* points;
	int pointNumber = 0;
public:

	PointCloud(int pointNumber) {			//	umut
		this->points = points;
		points = new Point[pointNumber];
	}
	// inheritance kullandigimiz icin default constructor hatasi
	// aliyoruz. bundan kurtulmak icin boyle yaziyorum.					// umut
	PointCloud(){}

	Point* setPointCloud(double x,double y,double z) {
		points->setPoints(x,y,z);
		return points;
	}
	Point* getPointCloud() {
		points->getPoints();
		return points;
	}
	PointCloud operator+(PointCloud &a) {
		PointCloud toplam(3);
		toplam.points->x = a.points->x + this->points->x;
		toplam.points->y = a.points->y + this->points->y;
		toplam.points->z = a.points->z + this->points->z;
		cout << "\nIki nokta bulutunun toplami:\n";
		cout << "yeni x: " << toplam.points->x << "\tyeni y: " << toplam.points->y << "\tyeni z: " << toplam.points->z << endl;
		return toplam;
	}
	Point operator=(Point &a) {
		Point kopya;
		kopya.x = a.x;
		kopya.y = a.y;
		kopya.z = a.z;
		return kopya;
	}
};


class Transform :public PointCloud {
private:
	double angles[3];
	double trans[3];
	double transMatrix[4][4];
public:
	Transform(double trans[3], double angles[3]) {
		
	}
	//set/get functions...
	void setRotation(double ang[]) {
		for (int i = 0; i < 3; i++)
		{
			int a;
			cin >> a;
			ang[i] = a;
		}
	}
	void setTranslation(double tr[]) {
		for (int i = 0; i < 3; i++)
		{
			int a;
			cin >> a;
			tr[i] = a;
		}
	}
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

class ThreeDGridMap : public PointCloud {  // 3DGridMap �eklinde yaz�nca hata veriyordu ThreeD yazd�m
private:
	 // buray� yapamad�m
	float gridSize;
	int depth;
public:
	ThreeDGridMap();
	//set/get functions...
	void insertPointCloud(PointCloud& pc);
	void insertPoint(Point& p);
	bool getGrid(int x, int y, int z) const;
	bool loadMap(string fileName); // fonk. i�indeki fileName'in t�r� belli de�ildi b�yle yapt�m
	bool saveMap(string fileName); // bir �stteki fonk. ile ayn� durum mevcut
};

int main() {
	/*mainde test yaptim set-get-esit esit calisti*/
	Point u;
	Point y;
	PointCloud a(3);
	PointCloud b(3);
	PointCloud c(3);
	PointCloud d(3);
	u.setPoints(3,4,5);
	y.setPoints(6,7,8);
	cout << "x'in setPoint noktalari:\n"; u.getPoints();
	cout << endl;
	cout << "y'nin setPoint ile noktalari:\n"; y.getPoints();
	cout << endl;
	u == y;
	cout << endl;
	/* distance ve PointCloud'in fonksiyonlarinin testleri*/
	y.distance(u);
	cout << endl;
	cout << endl << "pointcloud'in setPoint ile noktalari\n";
	a.setPointCloud(1,2,3);
	a.getPointCloud();
	cout << endl << "aptALOCKLAYVYE";
	b = a;
	b.getPointCloud();
	c.setPointCloud(3, 4, 5);
	b + c;

	double ang[3], tr[3];
	Transform tmp(ang, tr);

	tmp.setRotation(ang);
	tmp.setTranslation(tr);

	for (int i = 0; i < 3; i++)
	{
		cout << ang[i] << " ";
	}

	cout << endl;

	for (int i = 0; i < 3; i++)
	{
		cout << tr[i] << " ";
	}


	return 0;
}