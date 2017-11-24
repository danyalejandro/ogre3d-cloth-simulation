#include "PhysNode.h"


PhysNode::PhysNode(SceneManager *creator, double m) {
	node = creator->getRootSceneNode()->createChildSceneNode();
	this->m = m;
	f = Vector3::ZERO;
	a = Vector3::ZERO;
	v = Vector3::ZERO;
	fixed = false;
}

void PhysNode::updatePhysics() {
	a = f / m;
	v += a;
	if (!fixed) {
		node->translate(v);
	}
}

Vector3 PhysNode::getPosition() {
	return node->getPosition();
}

void PhysNode::clearForces() {
	f = 0;
}
