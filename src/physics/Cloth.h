#ifndef OGRECAM_CLOTH_H
#define OGRECAM_CLOTH_H


#include "LinearSpring.h"
#include "../drawing/Line3D.h"

class Cloth {
public:
	float windFrame = 0;
	char rows;
	char cols;
	double spaceRows;
	double spaceCols;
	double spaceDiagonal;
	
	SceneManager *creator;
	std::vector<PhysNode> physNodes;
	std::vector<LinearSpring> springs;
	std::vector<Line3D> lines;
	Vector3 gravity;
	
	Cloth();
	Cloth(SceneManager *creator, char rows, char cols, double spaceRows, double spaceCols);
	void updatePhysics();
	void fixRow(char row);
	void createSpring(int index1, int index2, double restLength);
};


#endif //OGRECAM_CLOTH_H
