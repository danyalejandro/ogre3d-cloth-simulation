//
// Created by dany on 06/10/17.
//

#include "Point3D.h"

Point3D::Point3D(SceneManager* scnMgr, Vector3 p) {
	this->p = p;
	manual = scnMgr->createManualObject("manual");
	manual->setDynamic(true);
	manual->begin("Solid/Red", RenderOperation::OT_POINT_LIST);
	manual->position(p);
	manual->index(0);
	manual->end();
	
	node = scnMgr->getRootSceneNode()->createChildSceneNode();
	node->attachObject(manual);
}
