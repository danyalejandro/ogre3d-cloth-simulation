#include <Overlay/OgreOverlayManager.h>
#include <Overlay/OgreOverlayElement.h>
#include "App.h"

App::App() : OgreBites::ApplicationContext("BasicApp") {
	camGuy = CamGuy();
}

// ##### EVENTS

bool App::keyPressed(const OgreBites::KeyboardEvent& evt)  {
	Keycode key = evt.keysym.sym;
	
	if (key == SDLK_ESCAPE) getRoot()->queueEndRendering();
	else camGuy.handleKeyPressed(key);
	
	return InputListener::keyPressed(evt);
}

bool App::keyReleased(const OgreBites::KeyboardEvent& evt)  {
	Keycode key = evt.keysym.sym;
	camGuy.handleKeyReleased(key);
	return InputListener::keyPressed(evt);
}

bool App::frameRenderingQueued(const FrameEvent &evt) {
	camGuy.processFrame(evt.timeSinceLastFrame);
	cloth.updatePhysics();
	return ApplicationContext::frameRenderingQueued(evt);
}

bool App::mouseMoved(const MouseMotionEvent &evt) {
	camNode->yaw(Ogre::Degree(-evt.xrel * 0.15f), Ogre::Node::TS_PARENT);
	camNode->pitch(Ogre::Degree(-evt.yrel * 0.15f));
	return InputListener::mouseMoved(evt);
}


// ##### FUNCTIONS

void App::setup(void)  {
	
	// Initialize scene
	//ResourceGroupManager::getSingleton().addResourceLocation("/home/dany/CLionProjects/ogrecam/media", "FileSystem");
	OgreBites::ApplicationContext::setup();
	
	Root* root = getRoot();
	scnMgr = root->createSceneManager(ST_GENERIC);
	addInputListener(this);
	RTShader::ShaderGenerator* shadergen = RTShader::ShaderGenerator::getSingletonPtr();
	shadergen->addSceneManager(scnMgr);
	scnMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);
	
	createCamera();
	createLights();
	createObjects();
}

void App::createLights() {
	Light* light = scnMgr->createLight("MainLight");
	SceneNode* lightNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	lightNode->setPosition(0, 500, 150);
	lightNode->attachObject(light);
}

void App::createObjects() {
	//ninja
	/*Entity* ninjaEntity = scnMgr->createEntity("ninja.mesh");
	SceneNode* node = scnMgr->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ninjaEntity);*/
	
	// create ManualObject
	//Line3D(scnMgr, Vector3(0,0,0), Vector3(100,100,100));
	//Point3D(scnMgr, Vector3(100,100,100));
	
	
	cloth = Cloth(scnMgr, 15, 20, 10, 10);
	cloth.fixRow(0);
	
	// spring
	//springs.push_back(LinearSpring(&physNodes[0], &physNodes[1], 10));
	
	
	// ground
	Plane plane(Vector3::UNIT_Y, -500);
	MeshManager::getSingleton().createPlane(
			"ground",
			ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME,
			plane,
			1500, 1500,
			20, 20,
			true,
			1, 5, 5,
			Vector3::UNIT_Z);
	Entity* groundEntity = scnMgr->createEntity("ground");
	groundEntity->setCastShadows(false);
	groundEntity->setMaterialName("Examples/Rockwall");
	scnMgr->getRootSceneNode()->createChildSceneNode()->attachObject(groundEntity);
}

void App::createCamera() {
	Camera* cam = scnMgr->createCamera("myCam");
	cam->setNearClipDistance(5);
	cam->setAutoAspectRatio(true);
	getRenderWindow()->addViewport(cam);
	
	camNode = scnMgr->getRootSceneNode()->createChildSceneNode();
	camNode->setPosition(-180, -50, 180);
	camNode->lookAt(Ogre::Vector3(0, 0, 0), Node::TS_PARENT);
	camNode->attachObject(cam);
	camGuy.setCamNode(camNode);
}
