#include "Joints.h"
#include "Rigidbody.h"
#include "Vector2.h"
#include "Utils.h"
#include <iostream>
#include <vector>

namespace Phys {

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



	RotationJoint::RotationJoint(Rigidbody* r, Rigidbody* rs1, Vector2 off) {
		this->rb1 = r;
		this->rb2 = rs1; 
		this->offset = off;
	}

	RotationJoint::~RotationJoint() {}

	void RotationJoint::Update() {
		
		double magnitude = rb1->position.magnitude();
		double a = atan(rb1->position.y / rb1->position.x);
		double rads = Phys::Radians(this->angle);

		this->offset = (this->rb2->position.x + this->offset.x, this->rb2->position.y + this->offset.y);

		this->rb1->position.x = (magnitude * cos(a + rads)) + this->offset.x;
		this->rb1->position.y = (magnitude * sin(a + rads)) + this->offset.y;

	}


	void JointUpdate(std::vector<SpringJoint*> globalSpringList, std::vector<FixedJoint*> globalFixedList) {
		for (int x = 0; x < globalSpringList.size(); x++) {
			globalSpringList[x]->Update();
		}
		for (int x = 0; x < globalFixedList.size(); x++) {
			globalFixedList[x]->Update();
		}
	}

}