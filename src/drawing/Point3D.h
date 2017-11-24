#ifndef OGRECAM_POINT3D_H
#define OGRECAM_POINT3D_H

#include <Ogre.h>

using namespace Ogre;


class Point3D {
public:
	Vector3 p;
	ManualObject* manual;
	SceneNode* node;
	
	Point3D(SceneManager* scnMgr, Vector3 p);
};

#endif //OGRECAM_POINT3D_H
