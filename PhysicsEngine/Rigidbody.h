#pragma once
#include "Vector2.h"

class Rigidbody {
public:
	double time;
	double dt = .01;
	double mass = 1;
	double gravity = -9.8;

	Vector2 forces;
	Vector2 acceleration;
	Vector2 velocity;
	Vector2 position;


	Rigidbody(double mass, Vector2 pos);
	~Rigidbody();

	void Update();
};
