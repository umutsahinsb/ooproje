#include "PointCloud.h"
#include "Transform.h"

class PointCloudGenerator {
private:
	Transform transform;
public:
	PointCloudGenerator();
	virtual PointCloud capture() = 0;
	virtual PointCloud captureFor() = 0;
};