#ifndef OGRECAM_APP_H
#define OGRECAM_APP_H

#include <Ogre.h>
#include <OgreApplicationContext.h>
#include <OgreResourceGroupManager.h>
#include "Sample.h"
#include "CamGuy.h"
#include "../config.h"
#include "../drawing/Line3D.h"
#include "../drawing/Point3D.h"
#include "../drawing/PhysSphere.h"
#include "../physics/PhysNode.h"
#include "../physics/LinearSpring.h"
#include "../physics/Cloth.h"


using namespace Ogre;
using namespace OgreBites;

class App : public OgreBites::ApplicationContext, public OgreBites::InputListener {
	SceneNode* camNode;
	SceneManager* scnMgr;
	CamGuy camGuy;
	
	Cloth cloth;

public:
	App();
	void setup();
	
	void createCamera();
	void createLights();
	void createObjects();
	
	bool keyPressed(const KeyboardEvent &evt);
	bool keyReleased(const KeyboardEvent &evt);
	bool mouseMoved(const MouseMotionEvent &evt);
	bool frameRenderingQueued(const FrameEvent &evt);
};


#endif //OGRECAM_APP_H
