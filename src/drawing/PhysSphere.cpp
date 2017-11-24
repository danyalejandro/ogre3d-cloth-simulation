#include "PhysSphere.h"

PhysSphere::PhysSphere(SceneManager* scnMgr, Vector3 pos) {
	ent = scnMgr->createEntity(Ogre::SceneManager::PT_SPHERE); // works for PLANE, CUBE and SPHERE
	ent->setMaterialName("Solid/Red");
	node = scnMgr->getRootSceneNode()->createChildSceneNode();
	node->attachObject(ent);
	node->setPosition(pos);
	node->setScale(0.1, 0.1, 0.1);
	
}
