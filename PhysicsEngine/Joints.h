#pragma once

#include "Rigidbody.h"
#include "Vector2.h"
#include "Collision.h"

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