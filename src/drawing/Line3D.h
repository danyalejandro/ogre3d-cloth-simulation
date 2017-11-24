#ifndef OGRECAM_LINE3D_H
#define OGRECAM_LINE3D_H

#include <Ogre.h>
#include <iostream>

using namespace Ogre;
using namespace std;

class Line3D {
public:
	ManualObject* manual;
	SceneNode *n0, *n1, *lineNode;
	
	Line3D(SceneManager *scnMgr, SceneNode *n0, SceneNode *n1);
	void update();
};

#endif //OGRECAM_LINE3D_H
