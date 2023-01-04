#include "PointCloud.h"

class Map {
public:
	Map();
	void setMap();
	Map getMap(); // fonk. türü bu mu olmasý gerekiyor emin deðilim
	virtual void insertPointCloud(PointCloud& pc) = 0;
	virtual bool loadMap(string fileName) = 0; // bu ve saveMap'in parametresi olan fileName PointCloudRecorder'daki fileName nesnesi olabilir emin deðilim
	virtual bool saveMap(string fileName) = 0;
};
