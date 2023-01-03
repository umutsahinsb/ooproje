#include "Point.h"
#include "PointCloud.h"
#include "PointCloudRecorder.h"
#include "DepthCamera.h"
#include "ThreeDGridMap.h"
#include "Transform.h"

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