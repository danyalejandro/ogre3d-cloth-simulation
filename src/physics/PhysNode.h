#ifndef OGRECAM_PHYSNODE_H
#define OGRECAM_PHYSNODE_H

#include <Ogre.h>
#include <stdlib.h>
#include "../config.h"

using namespace Ogre;
using namespace std;

class PhysNode {
public:
	SceneNode* node;
	Vector3 f;
	Vector3 a;
	Vector3 v;
	double m;
	bool fixed; // true if position is fixed in space
	
	PhysNode(SceneManager *creator, double m);
	void updatePhysics();
	void clearForces();
	Vector3 getPosition();
	
};

#endif //OGRECAM_PHYSNODE_H
