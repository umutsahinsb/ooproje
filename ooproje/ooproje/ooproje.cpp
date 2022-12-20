#include <iostream>
#include <string>
#include <math.h>
using namespace std;

///////						ONEMLI				////////
/*iplikci nedim gibi yorum yaz�n lutfen, turkce harf kullanmayin github bozuyor tsk.*/
///////						ONEMLI				////////

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
	/*noktalari ekrana basiyor*/
	void getPoints() {					//	umut
		cout << "x: " << x << endl << "y: " << y << endl << "z: " << z << endl;
	}
	/*noktalari ayarliyor/degistiriyor*/
	double setPoints() {
		cout << "Enter x, y and z points: ";
		cin >> x >> y >> z;
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

	Point* setPointCloud() {
		points->setPoints();
		return points;
	}
	Point* getPointCloud() {
		points->getPoints();
		return points;
	}
	void operator+(Point a) {
		
	}
	void operator=(Point a) {

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
	Point x;
	Point y;
	PointCloud a(3);
	PointCloud b(3);
	x.setPoints();
	y.setPoints();
	x.getPoints();

	x == y;
	cout << endl;
	/* distance ve PointCloud'in fonksiyonlarinin testleri*/
	y.distance(x);
	a.setPointCloud();
	a.getPointCloud();
}