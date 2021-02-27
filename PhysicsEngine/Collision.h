#pragma once

#include "Rigidbody.h"
#include "Vector2.h"



namespace Phys {

	//vector<RectCollider*> getPotentialCollisions();


	class RectCollider {
	public:
		int id;
		bool inCollision;
		Vector2 dimensions;
		Vector2 position;
		Rigidbody* rb;
		RectCollider(Vector2 dim = (100, 100));
		~RectCollider();

		void Attach(Rigidbody* toAttach);
		void Update();


	};

	class CircleCollider {
	public:
		int id;
		bool inCollision;
		double diameter;
		Vector2 position;
		Rigidbody* rb;
		CircleCollider(double diam);
		~CircleCollider();

		void Attach(Rigidbody* toAttach);
		void Update();


	};

	void resolveCollision(RectCollider* obj1, RectCollider* obj2);

	void resolveCollision(CircleCollider* obj1, CircleCollider* obj2);

	void resolveCollision(RectCollider* obj1, CircleCollider* obj2);


	void CollisionUpdate(vector<RectCollider*> globalRectList, vector<CircleCollider*> globalCircleList);

	
}