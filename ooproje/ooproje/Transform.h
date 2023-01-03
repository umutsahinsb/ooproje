#include "PointCloud.h"

class Transform {
private:
	double angles[3];
	double trans[3];
	double transMatrix[4][4];
public:
	Transform(string name)
	{
		if (name == "cam.txt")
		{
			double cam1transMatrix[4][4] =
			{ {-0.7076050, 0.0065031, -0.7065783, 1.95704},
			  { 0.7066082, 0.0065134, -0.7075750, 1.93000},
			  { 0.0000008,-0.9999576, -0.0092041, 1.05707},
			  {0,         0,          0,         1}
			};
			memcpy(transMatrix, cam1transMatrix, sizeof(transMatrix));
		}

	}
	Transform(double trans[3], double angles[3]) {
		setTranslation(trans);
		setRotation(angles);
	}
	~Transform()
	{

	}

	//set/get functions...
	void setRotation(double ang[]) {
		for (int i = 0; i < 3; i++)
			angles[i] = ang[i] * (PI / 180);
	}
	void setTranslation(double tr[]) {
		for (int i = 0; i < 3; i++)
			trans[i] = tr[i];
	}
};
