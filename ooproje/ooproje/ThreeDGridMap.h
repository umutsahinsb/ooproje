#include "Map.h"

class ThreeDGridMap : public Map {  // 3DGridMap þeklinde yazýnca hata veriyordu ThreeD yazdým
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
		int xctr = 1, yctr = 1, zctr = 1;
		float a;
		
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
		int xctr = 1, yctr = 1, zctr = 1;
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
		if (map[x - 1][y - 1][z - 1] == true) {
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