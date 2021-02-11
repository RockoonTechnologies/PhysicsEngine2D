
#include "Collision.h"
#include "Rigidbody.h"
#include "Vector2.h"
#include <vector>

using namespace std;

//float boundingBoxSize = 50;


vector<RectCollider*> globalList;

void CollisionUpdate() {
	for (int x = 0; x < globalList.size(); x++) {
		globalList[x]->Update();
		globalList[x]->inCollision = false;
	}

	for (int x = 0; x < globalList.size(); x++) {
		RectCollider* obj1 = globalList[x];
		for (int x = 0; x < globalList.size(); x++) {
			RectCollider* obj2 = globalList[x];

			if (obj1->id == obj2->id) {
				continue;
			}

			if (obj1->position.x < obj2->position.x + obj2->dimensions.x &&
				obj1->position.x + obj2->dimensions.x > obj2->position.x &&
				obj1->position.y < obj2->position.y + obj2->dimensions.y &&
				obj1->position.y + obj1->dimensions.y > obj2->position.y)
			{
				obj2->inCollision = true;
			}

		}
	}
}

/*
vector<RectCollider*> getPotentialCollisions() {
	vector<RectCollider*> potentialCollisions;



}
*/

RectCollider::RectCollider(Vector2 dim) {
	this->dimensions = dim;
	this->id = globalList.size();
	globalList.push_back(this);
}

RectCollider::~RectCollider() {}

void RectCollider::Attach(Rigidbody* toAttach) {
	rb = toAttach;
}

void RectCollider::Update() {
	this->position = rb->position;
}
