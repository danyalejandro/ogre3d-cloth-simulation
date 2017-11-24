//
// Created by dany on 05/10/17.
//

#include "CamGuy.h"


CamGuy::CamGuy() {
	this->camNode = NULL;
	mTopSpeed = 150.0;
	mVelocity = Vector3::ZERO;
}

void CamGuy::handleKeyPressed(SDL_Keycode key) {
	if (key == 'w' || key == SDLK_UP) mGoingForward = true;
	else if (key == 's' || key == SDLK_DOWN) mGoingBack = true;
	else if (key == 'a' || key == SDLK_LEFT) mGoingLeft = true;
	else if (key == 'd' || key == SDLK_RIGHT) mGoingRight = true;
	else if (key == SDLK_PAGEUP) mGoingUp = true;
	else if (key == SDLK_PAGEDOWN) mGoingDown = true;
	else if (key == SDLK_LSHIFT) mFastMove = true;
}

void CamGuy::handleKeyReleased(SDL_Keycode key) {
	if (key == 'w' || key == SDLK_UP) mGoingForward = false;
	else if (key == 's' || key == SDLK_DOWN) mGoingBack = false;
	else if (key == 'a' || key == SDLK_LEFT) mGoingLeft = false;
	else if (key == 'd' || key == SDLK_RIGHT) mGoingRight = false;
	else if (key == SDLK_PAGEUP) mGoingUp = false;
	else if (key == SDLK_PAGEDOWN) mGoingDown = false;
	else if (key == SDLK_LSHIFT) mFastMove = false;
}

void CamGuy::processFrame(Real timeSinceLastFrame) {
	Ogre::Vector3 accel = Ogre::Vector3::ZERO;
	Ogre::Matrix3 axes = camNode->getLocalAxes();
	if (mGoingForward) accel -= axes.GetColumn(2);
	if (mGoingBack) accel += axes.GetColumn(2);
	if (mGoingRight) accel += axes.GetColumn(0);
	if (mGoingLeft) accel -= axes.GetColumn(0);
	if (mGoingUp) accel += axes.GetColumn(1);
	if (mGoingDown) accel -= axes.GetColumn(1);
	
	// if accelerating, try to reach top speed in a certain time
	Ogre::Real topSpeed = mFastMove ? mTopSpeed * 20 : mTopSpeed;
	if (accel.squaredLength() != 0)
	{
		accel.normalise();
		mVelocity += accel * topSpeed * timeSinceLastFrame * 10;
	}
		// if not accelerating, try to stop in a certain time
	else mVelocity -= mVelocity * timeSinceLastFrame * 10;
	
	Ogre::Real tooSmall = std::numeric_limits<Ogre::Real>::epsilon();
	
	// keep camera velocity below top speed and above epsilon
	if (mVelocity.squaredLength() > topSpeed * topSpeed)
	{
		mVelocity.normalise();
		mVelocity *= topSpeed;
	}
	else if (mVelocity.squaredLength() < tooSmall * tooSmall)
		mVelocity = Ogre::Vector3::ZERO;
	
	if (mVelocity != Ogre::Vector3::ZERO) camNode->translate(mVelocity * timeSinceLastFrame);
	
}

void CamGuy::setCamNode(SceneNode *camNode) {
	this->camNode = camNode;
}
