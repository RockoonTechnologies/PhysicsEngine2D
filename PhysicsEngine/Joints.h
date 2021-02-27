#pragma once

#include "Rigidbody.h"
#include "Vector2.h"
#include "Collision.h"
#include <vector>

namespace Phys {

	

	class SpringJoint {
	public:

		Rigidbody* rb1;
		Rigidbody* rb2;

		RectCollider* col;

		double Stiffness = .6;

		SpringJoint(Rigidbody* r, Rigidbody* rs1, RectCollider* col);
		~SpringJoint();

		void Update();

	};


	class FixedJoint {
	public:

		Rigidbody* rb1;
		Rigidbody* rb2;


		Vector2 offset = (1, 1);

		FixedJoint(Rigidbody* r, Rigidbody* rs1, Vector2 off);
		~FixedJoint();

		void Update();

	};

	void JointUpdate(std::vector<SpringJoint*> globalSpringList, std::vector<FixedJoint*> globalFixedList);
}
