#include "geometrickStructures.hpp"
#include <iostream>

class KKK
{

public:

	KKK(mesh mesh) {
		mainMesh = mesh;
	};
	void update() {
		mainMesh[0].a.x += mainMesh[0].a.x >= 150 ? -50 : 1;
		std::cout << "eej";

	}
	mesh getMesh() {
		return mainMesh;
	}



private:
	mesh mainMesh;
};

