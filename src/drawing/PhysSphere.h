#ifndef OGRECAM_SPHERE_H
#define OGRECAM_SPHERE_H

#include <Ogre.h>

using namespace Ogre;

class PhysSphere {
public:
	Entity* ent;
	SceneNode* node;

	PhysSphere(SceneManager* scnMgr, Vector3 pos);
};


#endif //OGRECAM_SPHERE_H
