#pragma once

#include "Rigidbody.h"
#include "Vector2.h"



void CollisionUpdate();



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

