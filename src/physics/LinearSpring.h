#ifndef OGRECAM_LINEARSPRING_H
#define OGRECAM_LINEARSPRING_H

#include <Ogre.h>
#include "PhysNode.h"
#include "../config.h"

using namespace Ogre;

class LinearSpring {
public:
	PhysNode *n0, *n1;
	double restLength;  // Spring's rest length
	double ks; // Spring constant
	double kd; // Damping constant
	
	LinearSpring(PhysNode *n0, PhysNode *n1, double restLength);
	double length();
	void updatePhysics();
};


#endif //OGRECAM_LINEARSPRING_H
