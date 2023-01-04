#include "PointCloud.h"

class Map {
public:
	Map();
	void setMap();
	Map getMap(); // fonk. t�r� bu mu olmas� gerekiyor emin de�ilim
	virtual void insertPointCloud(PointCloud& pc) = 0;
	virtual bool loadMap(string fileName) = 0; // bu ve saveMap'in parametresi olan fileName PointCloudRecorder'daki fileName nesnesi olabilir emin de�ilim
	virtual bool saveMap(string fileName) = 0;
};
