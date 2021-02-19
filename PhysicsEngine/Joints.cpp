#include "Joints.h"
#include "Rigidbody.h"
#include "Vector2.h"
#include <iostream>


SpringJoint::SpringJoint(Rigidbody* r, Rigidbody* rs1, RectCollider* col) {
	this->rb1 = r;
	this->rb2 = rs1;

	this->col = col;
	
}


SpringJoint::~SpringJoint() {}


void SpringJoint::Update() {
	std::cout << this->col->inCollision + "\n";
	if (!this->col->inCollision) {
		Vector2 forcesToAdd(0, 0);

		forcesToAdd.x = -(this->Stiffness * (this->rb2->position.x - this->rb1->position.x));
		forcesToAdd.y = -(this->Stiffness * (this->rb2->position.y - this->rb1->position.y));
		this->rb2->addForces(forcesToAdd);
	}
	else {
		std::cout << "HEY BITCH";
	}
}


FixedJoint::FixedJoint(Rigidbody* r, Rigidbody* rs1, Vector2 off) {
	this->rb1 = r;
	this->rb2 = rs1;
	this->offset = off;
}

FixedJoint::~FixedJoint() {}

void FixedJoint::Update() {

	this->rb1->position.x = this->rb2->position.x + this->offset.x;
	this->rb1->position.y = this->rb2->position.y + this->offset.y;

}