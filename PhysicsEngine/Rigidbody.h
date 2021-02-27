#pragma once
#include "Vector2.h"
#include <vector>

using namespace std;
namespace Phys {

	

	class Rigidbody {
	public:



		double time;
		double dt = .01;
		double gravity = -9.8;

		bool locked = false;

		double mass = 1;
		double KE;
		double area;
		double density;
		Vector2 dimensions = (1, 1);

		Vector2 forces;
		Vector2 acceleration;
		Vector2 velocity;
		Vector2 position;


		Rigidbody(double mass = 1, Vector2 pos = (0, 0));

		~Rigidbody();

		void Update();
		void addForces(Vector2 toAdd);
	};
	void RigidbodyUpdate(vector<Rigidbody*>& globalRigidbodyList);
}