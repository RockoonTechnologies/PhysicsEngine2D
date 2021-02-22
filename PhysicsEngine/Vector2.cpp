#include "Vector2.h"
#include <math.h>
#include <iostream>
#include <string>

using namespace std;

double Dot(Vector2 first, Vector2 second) {
	double final = (first.x * second.x) + (first.y * second.y);
}

Vector2::Vector2(double m_X, double m_Y) {
	this->x = m_X;
	this->y = m_Y;
}

Vector2::~Vector2() {}


void Vector2::operator+=(Vector2& vec2) {
	this->x += vec2.x;
	this->y += vec2.y;
}

void Vector2::operator-=(Vector2& vec2) {
	this->x -= vec2.x;
	this->y -= vec2.y;
}

void Vector2::operator*=(Vector2& vec2) {
	this->x *= vec2.x;
	this->y *= vec2.y;
}

void Vector2::operator/=(Vector2& vec2) {
	this->x /= vec2.x;
	this->y /= vec2.y;
}


Vector2 Vector2::differenceVector(Vector2& otherVec) {
	Vector2 newVec(this->x - otherVec.x, this->y - otherVec.y);
	return newVec;
}

double Vector2::magnitude() {
	return sqrt((this->x * this->x) + (this->y * this->y));
}

double Vector2::direction() {
	
	return pow(tan(this->x / this->y), -1);
}

Vector2 Vector2::normal() {

	double mag = magnitude();
	Vector2 vec(this->x / mag, this->y / mag);
	return vec;
}

void Vector2::invert() {
	this->x = -this->x;
	this->y = -this->y;
}

void Vector2::print() {
	cout << "X: " << this->x  << " | " << "Y: " << this->y << "\n";

}

