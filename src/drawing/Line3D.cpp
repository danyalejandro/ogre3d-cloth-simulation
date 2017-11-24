//
// Created by dany on 05/10/17.
//

#include "Line3D.h"

Line3D::Line3D(SceneManager* scnMgr, SceneNode *n0, SceneNode *n1) {
	this->n0 = n0;
	this->n1 = n1;
	lineNode = scnMgr->getRootSceneNode()->createChildSceneNode();;
	
	//cout << "Line3D between " << n0->getPosition() << " and " << n1->getPosition() << endl;
	
	manual = scnMgr->createManualObject();
	manual->setDynamic(true);
	manual->begin("BaseWhiteNoLighting", RenderOperation::OT_LINE_LIST);
	manual->position(n0->getPosition());
	manual->position(n1->getPosition());
	manual->index(0);
	manual->index(1);
	manual->end();
	
	lineNode->attachObject(manual);
}

void Line3D::update() {
	manual->beginUpdate(0);
	manual->position(n0->getPosition());
	manual->position(n1->getPosition());
	manual->end();
}
