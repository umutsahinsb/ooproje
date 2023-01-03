#include "PointCloudGenerator.h"
#include "PointCloudRecorder.h"

class MapperInterface {
private:
	PointCloud poinCloud;
	PointCloud patch;
	vector <PointCloudGenerator*> generators;
	PointCloudRecorder* recorder;
public:
	MapperInterface();
	void addGenerator(PointCloudGenerator*);
	void setRecorder(PointCloudRecorder*);
	bool generate();
	bool recordPointCloud();
	bool recordMap();
	bool insertMap();
};