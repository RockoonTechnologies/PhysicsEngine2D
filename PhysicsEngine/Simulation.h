#pragma once


#include "Rigidbody.h"
#include "Collision.h"
#include "Vector2.h"
#include "Joints.h"

using namespace Phys;
namespace Phys {

	void Update(int steps);

	void AddToSimulation(Rigidbody* rb);
	void AddToSimulation(RectCollider* rc);
	void AddToSimulation(CircleCollider* cc);
	void AddToSimulation(FixedJoint* fj);
	void AddToSimulation(SpringJoint* sj);

}