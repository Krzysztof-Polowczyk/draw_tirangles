#pragma once
#include "geometrickStructures.hpp"
#include <iostream>
#include <cmath>




class KKK
{
	float angle = 0.01;

	double rotZ[3][3] = {
		{cos(angle), -sin(angle), 0},
		{sin(angle),  cos(angle), 0},
		{         0,           0, 1}
	};
public:

	KKK(mesh mesh) {
		mainMesh = mesh;
	};
	void update() {
		
		for (int i = 0; i < mainMesh.size(); i++) {
			mainMesh[i].a = matMul(mainMesh[i].a, rotZ);
			mainMesh[i].b = matMul(mainMesh[i].b, rotZ);
			mainMesh[i].c = matMul(mainMesh[i].c, rotZ);
		}
		std::cout << mainMesh[0].a.x << " " << mainMesh[0].a.y << " " << mainMesh[0].a.x << " " << std::endl;
		
	}
	mesh getMesh() {
		return mainMesh;
	}



private:
	mesh mainMesh;

	vec1x3 matMul(vec1x3 vec, double rot[3][3]) {
		vec1x3 result = {
			rot[0][0] * vec.x + rot[0][1] * vec.y + rot[0][2] * vec.z,
			rot[1][0] * vec.x + rot[1][1] * vec.y + rot[1][2] * vec.z,
			rot[2][0] * vec.x + rot[2][1] * vec.y + rot[2][2] * vec.z
		};
		return result;
	};
};

