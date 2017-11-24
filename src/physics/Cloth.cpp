//
// Created by dany on 07/10/17.
//

#include "Cloth.h"
#include "../drawing/Line3D.h"

Cloth::Cloth(SceneManager *creator, char rows, char cols, double spaceRows, double spaceCols) {
	this->creator = creator;
	this->rows = rows;
	this->cols = cols;
	this->spaceRows = spaceRows;
	this->spaceCols = spaceCols;
	spaceDiagonal = sqrt(pow(spaceRows, 2) + pow(spaceCols, 2));
	gravity = Vector3(0, CONFIG_GRAVITY, 0);
	
	Entity *ent;
	uchar row, col;
	for (row = 0 ; row < rows ; row++) {
		for (col = 0 ; col < cols ; col++) {
			ent = creator->createEntity(Ogre::SceneManager::PT_SPHERE);
			ent->setMaterialName("Solid/Red");
			ent->setCastShadows(false);
			PhysNode n = PhysNode(creator, 1);
			n.node->attachObject(ent);
			n.node->setPosition(col * spaceCols, -row * spaceRows, row * spaceRows);
			n.node->setScale(0.01,0.01,0.01);
			physNodes.push_back(n);
		}
	}
	
	// add springs
	int pos, posDown;
	for (row = 0 ; row < rows ; row++) {
		for (col = 0 ; col < cols ; col++) {
			pos = row * cols + col;
			posDown = pos + cols;
			
			// Add structural springs
			if (row < rows - 1) createSpring(pos, posDown, spaceRows);
			if (col < cols - 1) createSpring(pos, pos + 1, spaceCols);
			
			// Add shear springs
			if (row < rows - 1) {
				if (col > 0) createSpring(pos, posDown - 1, spaceDiagonal);
				if (col < cols - 1) createSpring(pos, posDown + 1, spaceDiagonal);
			}
			
			// Add bending springs
			if (row < rows - 2) createSpring(pos, posDown + cols, spaceRows * 2);
			if (col < cols - 2) createSpring(pos, pos + 2, spaceCols * 2);
			
		}
	}
}

void Cloth::updatePhysics() {
	int n, steps = 1 / CONFIG_DT;
	
	Vector3 windDir = Vector3(0,0,1);
	int windMag = 100;
	float posWind;
	double r = sin(windFrame), x;
	
	for (n = 0 ; n < steps ; n++) {
		
		for (PhysNode &n : physNodes) {
			n.clearForces(); // Reset all forces
			n.f = gravity; // Apply gravity
			
			if (r > 0) {
				x = n.node->getPosition().x;
				posWind = 0.01 * (-0.1 * pow(50 - x*0.5, 2) + 100);
				//cout << "x=" << x << "posWind=" << posWind << endl;
				n.f.z += (0.02 * r) * posWind;
			}
		}
		
		for (LinearSpring &spring : springs) spring.updatePhysics();
		
		for (PhysNode &n : physNodes) n.updatePhysics(); // Update all physical nodes
	}
	
	// update lines
	for (Line3D &n : lines) n.update();
	
	windFrame += 0.08 - 0.01 * (rand() % 10);
}

Cloth::Cloth() {
	this->rows = 0;
	this->cols = 0;
	gravity = 0;
}

void Cloth::fixRow(char row) {
	int start = row * cols;
	int end = start + cols;
	int i;
	cout << "fixrow start " << start << " end:" << end << endl;
	
	for (i = start ; i < end ; i++) {
		cout << "fixing pos " << i << endl;
		physNodes[i].fixed = true;
	}
}

void Cloth::createSpring(int index1, int index2, double restLength) {
	PhysNode *pn1 = &physNodes[index1];
	PhysNode *pn2 = &physNodes[index2];
	springs.push_back(LinearSpring(pn1, pn2, restLength));
	lines.push_back(Line3D(creator, pn1->node, pn2->node));
}
