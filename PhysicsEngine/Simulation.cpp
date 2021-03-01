
#include "Simulation.h"
#include "Rigidbody.h"
#include "Collision.h"
#include "Vector2.h"
#include "Joints.h"
#include <vector>

using namespace Phys;
namespace Phys {
	std::vector<Rigidbody*> globalRigidbodyList;

	std::vector<RectCollider*> globalRectList;
	std::vector<CircleCollider*> globalCircleList;

	std::vector<SpringJoint*> globalSpringList;
	std::vector<FixedJoint*> globalFixedList;
	std::vector<RotationJoint*> globalRotationList;

	void Update(int steps = 1) {
		for (int x = 0; x < steps; x++) {

			RigidbodyUpdate(globalRigidbodyList);
			JointUpdate(globalSpringList, globalFixedList, globalRotationList);
			CollisionUpdate(globalRectList, globalCircleList);
		}
	}

	void AddToSimulation(Rigidbody* rb) {
		globalRigidbodyList.push_back(rb);
	}

	void AddToSimulation(RectCollider* rc) {
		globalRectList.push_back(rc);
	}
	void AddToSimulation(CircleCollider* cc) {
		globalCircleList.push_back(cc);
	}

	void AddToSimulation(FixedJoint* fj) {
		globalFixedList.push_back(fj);
	}
	void AddToSimulation(SpringJoint* sj) {
		globalSpringList.push_back(sj);
	}
	void AddToSimulation(RotationJoint* rj) {
		globalRotationList.push_back(rj);
	}

}