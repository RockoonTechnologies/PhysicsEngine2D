#pragma once
#include <math.h>
#include <iostream>
#include <string>


double Dot(Vector2 first, Vector2 second);

class Vector2 {
public:
	double x;
	double y;
	Vector2(double m_X=0, double m_Y=0);
	~Vector2();

	void operator+=(Vector2& vec2);
	void operator-=(Vector2& vec2);
	void operator*=(Vector2& vec2);
	void operator/=(Vector2& vec2);

	Vector2 differenceVector(Vector2& otherVec);
	double magnitude();
	double direction();
	Vector2 normal();
	void invert();
	
	void print();
};