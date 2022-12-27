#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include <iterator>
#include <list>
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
public:	
	list <PointCloud> points;
	int pointNumber = 0;
	PointCloud(int pointNumber) {			//	umut
		this->pointNumber = pointNumber;
	}
	// inheritance kullandigimiz icin default constructor hatasi
	// aliyoruz. bundan kurtulmak icin boyle yaziyorum.					// umut
	PointCloud(){}

	list<PointCloud> setPointCloud(double x,double y,double z) {
		points.clear();
		points.push_back(x);
		points.push_back(y);
		points.push_back(z);
		this->x = x;
		this->y = y;
		this->z = z;
		return points;
	}
	list<PointCloud> setPointCloud(double x, double y, double z,double x1,double y1, double z1) {
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
	PointCloud operator+(PointCloud &a) {
		PointCloud npc(6);
		npc.setPointCloud(this->x, this->y, this->z, a.x, a.y, a.z);
		cout << "\nIki nokta bulutunun toplami:\n";

		
		return npc;
	}
	Point operator=(Point &a) {
		Point kopya;
		kopya.x = a.x;
		kopya.y = a.y;
		kopya.z = a.z;
		return kopya;
	}
};
ostream& operator<<(ostream& os, const Point& dt)
{
	os << dt.x << '/' << dt.y << '/' << dt.z;
	return os;
}


class Transform :public PointCloud {
private:
	double angles[3];
	double trans[3];
	double transMatrix[4][4];
public:
	Transform(string name)
	{
		if (name == "cam.txt")
		{
			double cam1transMatrix[4][4] =
			{ {-0.7076050, 0.0065031, -0.7065783, 1.95704},
			  { 0.7066082, 0.0065134, -0.7075750, 1.93000},
			  { 0.0000008,-0.9999576, -0.0092041, 1.05707},
			  {0,         0,          0,         1}
			};
			memcpy(transMatrix, cam1transMatrix, sizeof(transMatrix));
		}

	}
	Transform(double trans[3], double angles[3]) {
		setTranslation(trans);
		setRotation(angles);
	}
	~Transform()
	{

	}

	//set/get functions...
	void setRotation(double ang[]) {
		for (int i = 0; i < 3; i++)
			angles[i] = ang[i] * (PI / 180);
	}
	void setTranslation(double tr[]) {
		for (int i = 0; i < 3; i++)
			trans[i] = tr[i];
	}
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
		file << pc.x << " " << pc.y << " " << pc.z;
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
	bool map[50][50][50] = { false };
	float gridSize;
	int depth;
public:
	ThreeDGridMap() {
		map[49][49][49] = this->map;
		depth = 1;
		gridSize = 1;
	}
	//set/get functions...
	void insertPointCloud(PointCloud& pc) {
		int xctr=1, yctr=1, zctr=1;
		while (float(pc.points.front()) > gridSize) {
			pc.points->x -= gridSize;
			xctr++;
		}
		while (pc.points->y > gridSize) {
			pc.points->y -= gridSize;
			yctr++;
		}
		while (pc.points->z > gridSize) {
			pc.points->z -= gridSize;
			zctr++;
		}
		int xpoint, ypoint, zpoint;
		xpoint = xctr * points[0];
		ypoint = yctr * pc.points->y;
		zpoint = zctr * pc.points->z;
		if (depth < xpoint * ypoint * zpoint) {
			depth = xpoint * ypoint * zpoint;
			cout << "depth: " << depth << endl;
		}
		if (depth >= xpoint * ypoint * zpoint) {

		}
		if (map[xpoint - 1][ypoint - 1][zpoint - 1] = true) {
			
		}
		else {
			map[xpoint - 1][ypoint - 1][zpoint - 1] = true;
		}
		

	}
	void insertPoint(Point& p) {
		int xctr = 1, yctr =1, zctr = 1;
		while (p.x > gridSize) {
			p.x -= gridSize;
			xctr++;
		}
		while (p.y > gridSize) {
			p.y -= gridSize;
			yctr++;
		}
		while (p.z > gridSize) {
			p.z -= gridSize;
			zctr++;
		}
		int xpoint, ypoint, zpoint;
		xpoint = xctr * p.x;
		ypoint = yctr * p.y;
		zpoint = zctr * p.z;
		if (depth < xpoint * ypoint * zpoint) {
			depth = xpoint * ypoint * zpoint;
			cout << "depth: " << depth << endl;
		}
		if (depth >= xpoint * ypoint * zpoint) {

		}
		if (map[xpoint - 1][ypoint - 1][zpoint - 1] = true) {

		}
		else {
			map[xpoint - 1][ypoint - 1][zpoint - 1] = true;
		}
	}
	bool getGrid(int x, int y, int z) {
		if(map[x-1][y-1][z-1] == true){
			cout << "kup dolu.\n";
			return true;
		}
		else {
			cout << "kup bos.\n";
			return false;
		}
	}
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
	ThreeDGridMap ab;
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
	ab.insertPointCloud(c);
	ab.insertPoint(u);
}