#include "PointCloudGenerator.h"

class DepthCamera : public PointCloudGenerator {
private:
	string fileName;
public:
	DepthCamera() {
		fileName = "cam1.txt";
	}
	//set/get functions...
	PointCloud capture() {
		PointCloud* readPoints;
		PointCloud d;
		Point s;
		string arr[6];
		int numLines = 0, p = 0, i = 0;
		ifstream file;
		file.open(fileName);
		string linectr;
		while (getline(file, linectr)) {
			++numLines;
		}
		readPoints = new PointCloud[numLines];
		readPoints->pointNumber = 3;
		readPoints->points = nullptr;
		file.close();
		file.open(fileName);
		int sayac = 1;
		while (getline(file, linectr)) {
			stringstream iss(linectr);
			stringstream abb(linectr);
			string k = linectr;
			while (iss >> linectr) {
				p++;
			}
			if (p % 6 == 0) {
				while (abb >> k) {
					arr[i] += k;
					i++;
				}
				readPoints->x = stod(arr[0]);
				readPoints->y = stod(arr[1]);
				readPoints->z = stod(arr[2]);

				i = 0;
				for (int k = 0; k < 6; k++) {
					arr[k] = " ";
				}

			}

			cout << sayac << "\t" << "x degeri: " << readPoints->x << "\ty degeri: " << readPoints->y << "\tz degeri: " << readPoints->z << endl;
			sayac++;
		}
		return *readPoints;
	}

	PointCloud captureFor(); // yeni fonk.
};
