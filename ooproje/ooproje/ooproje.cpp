#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
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

// pointcloud ok
class PointCloud :public Point {
	friend ostream& operator<<(ostream& o, const PointCloud& vect);
	friend istream& operator>>(istream& in, PointCloud& vect);
public:
	Point* points;
	int pointNumber = 0;
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

// recorder ok
class PointCloudRecorder :public PointCloud {
private:
	string fileName;
public:
	PointCloudRecorder() {
		fileName = "record.txt";
	}
	//set/get functions...
	bool save(const PointCloud& pc) {
		ofstream file;
		file.open(fileName);
		file << pc.points->x << " " << pc.points->y << " " << pc.points->z;
		return 1;
	}
};	

// depth ok
class DepthCamera : public PointCloud {
private:
	string fileName;
public:
	DepthCamera() {
		fileName = "cam1.txt";
	}
	//set/get functions...
	PointCloud capture() {
		PointCloud* readPoints;
		PointCloud d;
		Point s;
		string arr[6];
		int numLines = 0, p = 0, i = 0;
		ifstream file;
		file.open(fileName);
		string linectr;
		while (getline(file, linectr)) {
			++numLines;
		}
		readPoints = new PointCloud[numLines];
		readPoints->pointNumber = 3;
		readPoints->points = nullptr;
		file.close();
		file.open(fileName);
		int sayac = 1;
		while (getline(file, linectr)) {
			stringstream iss(linectr);
			stringstream abb(linectr);
			string k = linectr;
			while (iss >> linectr) {
				p++;
			}
			if (p % 6 == 0) {
				while (abb >> k) {
					arr[i] += k;
					i++;
				}
				readPoints->x = stod(arr[0]);
				readPoints->y = stod(arr[1]);
				readPoints->z = stod(arr[2]);

				i = 0;
				for (int k = 0; k < 6; k++) {
					arr[k] = " ";
				}

			}

			cout << sayac << "\t" << "x degeri: " << readPoints->x << "\ty degeri: " << readPoints->y << "\tz degeri: " << readPoints->z << endl;
			sayac++;
		}
		return *readPoints;
	}
};


class ThreeDGridMap : public PointCloud {  // 3DGridMap þeklinde yazýnca hata veriyordu ThreeD yazdým
private:
	 // burayý yapamadým
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

int main() {
	/*mainde test yaptim set-get-esit esit calisti*/
	Point u;
	Point y;
	PointCloud a(3);
	PointCloud b(3);
	PointCloud c(3);
	PointCloud d(3);
	DepthCamera s;
	PointCloudRecorder ff;
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
	ff.save(c);
}