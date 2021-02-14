#pragma once
#include "Vector2.h"

class Rigidbody {
public:

	

	double time;
	double dt = .01;
	double gravity = -9.8;

	double mass = 1;
	double KE;
	double area;
	double density;
	Vector2 dimensions = (1, 1);

	Vector2 forces;
	Vector2 acceleration;
	Vector2 velocity;
	Vector2 position;


	Rigidbody(double mass=1, Vector2 pos=(0,0));
	Rigidbody();
	~Rigidbody();

	void Update();
	void addForces(Vector2 toAdd);
};
