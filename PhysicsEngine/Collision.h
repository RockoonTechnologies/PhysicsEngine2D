#pragma once

#include "Rigidbody.h"
#include "Vector2.h"

void Update();

class RectCollider {
public:
	int id;
	Vector2 dimensions;
	Vector2 position;
	Rigidbody rb;
	RectCollider(Vector2 dim=(1,1));
	~RectCollider();

	void Attach(Rigidbody toAttach);
	void Update();


};
