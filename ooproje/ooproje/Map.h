#include "PointCloud.h"

class Map {
public:
	Map();
	void setMap();
	Map getMap(); // fonk. türü bu mu olmasý gerekiyor emin deðilim
	void insertPointCloud(PointCloud& pc);
	bool loadMap(string fileName); // bu ve saveMap'in parametresi olan fileName PointCloudRecorder'daki fileName nesnesi olabilir emin deðilim
	bool saveMap(string fileName);
};
