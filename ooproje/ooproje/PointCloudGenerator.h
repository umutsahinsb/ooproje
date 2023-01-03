#include "PointCloud.h"
#include "Transform.h"

class PointCloudGenerator {
private:
	Transform transform;
public:
	PointCloudGenerator();
	PointCloud capture();
	PointCloud captureFor();
};