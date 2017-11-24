//
// Created by dany on 05/10/17.
//

#include "LinearSpring.h"

LinearSpring::LinearSpring(PhysNode *n0, PhysNode *n1, double restLength) {
	this->n0 = n0;
	this->n1 = n1;
	this->restLength = restLength;
	ks = CONFIG_SPRING_KS;
	kd = CONFIG_SPRING_KD;
	
}

// current length
double LinearSpring::length() {
	return n1->getPosition().distance(n0->getPosition());
}

// update physics for this spring, for 1 timestep
void LinearSpring::updatePhysics() {
	double dl = length() - restLength; // positive if stretched
	
	Vector3 dir_p0 = n0->getPosition() - n1->getPosition();
	dir_p0.normalise();
	Vector3 dir_p1 = -dir_p0;
	
	// Apply forces to both physical nodes
	n0->f += (ks * dl * dir_p1) - (kd * n0->v);
	n1->f += (ks * dl * dir_p0) - (kd * n1->v);
}
