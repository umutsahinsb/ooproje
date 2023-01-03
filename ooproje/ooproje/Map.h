#include "PointCloud.h"

class Map {
public:
	Map();
	void setMap();
	Map getMap(); // fonk. t�r� bu mu olmas� gerekiyor emin de�ilim
	void insertPointCloud(PointCloud& pc);
	bool loadMap(string fileName); // bu ve saveMap'in parametresi olan fileName PointCloudRecorder'daki fileName nesnesi olabilir emin de�ilim
	bool saveMap(string fileName);
};
