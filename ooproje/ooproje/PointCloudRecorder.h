#include "PointCloud.h"

class PointCloudRecorder {
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
