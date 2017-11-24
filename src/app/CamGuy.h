#ifndef OGRECAM_CAMGUY_H
#define OGRECAM_CAMGUY_H

#include <Ogre.h>
#include <OgreApplicationContext.h>

using namespace Ogre;

class CamGuy {
	bool mGoingForward = false;
	bool mGoingBack = false;
	bool mGoingLeft = false;
	bool mGoingRight = false;
	bool mGoingUp = false;
	bool mGoingDown = false;
	bool mFastMove = false;
	Real mTopSpeed;
	Vector3 mVelocity;
	
	SceneNode* camNode;
	
public:
	CamGuy();
	void setCamNode(SceneNode *camNode);
	void handleKeyReleased(SDL_Keycode key);
	void handleKeyPressed(SDL_Keycode key);
	void processFrame(Real timeSinceLastFrame);
};


#endif //OGRECAM_CAMGUY_H
