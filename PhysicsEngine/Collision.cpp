
#include "Collision.h"
#include "Rigidbody.h"
#include "Vector2.h"
#include <vector>

using namespace std;

float boundingBoxSize = 150;

bool elasticCollisions = true;


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

			if (obj1->id == obj2->id || (obj1->rb == NULL || obj2->rb == NULL)) {
				continue;
			}

			if (obj1->position.x < obj2->position.x + obj2->dimensions.x &&
				obj1->position.x + obj2->dimensions.x > obj2->position.x &&
				obj1->position.y < obj2->position.y + obj2->dimensions.y &&
				obj1->position.y + obj1->dimensions.y > obj2->position.y)
			{
				obj2->inCollision = true;

				Vector2 obj1VelocityBuffer(obj1->rb->velocity.x, obj1->rb->velocity.y);
				Vector2 obj2VelocityBuffer(obj2->rb->velocity.x, obj2->rb->velocity.y);

				if (elasticCollisions) {
					if (obj1->rb->mass == obj2->rb->mass) {
						obj1->rb->velocity.x = obj2->rb->velocity.x;
						obj2->rb->velocity.x = obj1VelocityBuffer.x;


						obj1->rb->velocity.y = obj2->rb->velocity.y;
						obj2->rb->velocity.y = obj1VelocityBuffer.y;
					}
					else {

						
						obj1->rb->velocity.x = (((obj1->rb->mass - obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.x) + (((2 * obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj2VelocityBuffer.x);
						obj2->rb->velocity.x = (((2 * obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.x) + (((obj2->rb->mass - obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass))) * obj2VelocityBuffer.x;

						obj1->rb->velocity.y = (((obj1->rb->mass - obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.y) + (((2 * obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj2VelocityBuffer.y);
						obj2->rb->velocity.y = (((2 * obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.y) + (((obj2->rb->mass - obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass))) * obj2VelocityBuffer.y;
					}
				}


			}

		}
	}
}

/*
vector<RectCollider*> getPotentialCollisions() {
	vector<RectCollider*> potentialCollisions;
	for (int x = 0; x < globalList.size(); x++) {
		RectCollider* obj1 = globalList[x];
		for (int x = 0; x < globalList.size(); x++) {
			RectCollider* obj2 = globalList[x];

			if (obj1->id == obj2->id) {
				continue;
			}

			if (obj1->position.x < obj2->position.x + obj2->dimensions.x &&
				obj1->position.x + obj2->dimensions.x > obj2->position.x)
			{
				potentialCollisions.push_back(obj2);
			}

		}
	}


}*/


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
