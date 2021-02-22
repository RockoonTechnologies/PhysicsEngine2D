
#include "Collision.h"
#include "Rigidbody.h"
#include "Vector2.h"
#include <vector>




using namespace std;

float boundingBoxSize = 150;

bool elasticCollisions = false;
double Cr = .1;


vector<RectCollider*> globalRectList;
vector<CircleCollider*> globalCircleList;




void CollisionUpdate() {
	for (int x = 0; x < globalRectList.size(); x++) {
		globalRectList[x]->Update();
		globalRectList[x]->inCollision = false;
	}

	for (int x = 0; x < globalCircleList.size(); x++) {
		globalCircleList[x]->Update();
		globalCircleList[x]->inCollision = false;
	}

	for (int x = 0; x < globalRectList.size(); x++) {
		
		for (int y = x; y < globalRectList.size(); y++) {
			RectCollider* obj1 = globalRectList[x];
			RectCollider* obj2 = globalRectList[y];


			if (obj1->id == obj2->id) {
				continue;
			}

			if (obj1->position.x < obj2->position.x + obj2->dimensions.x &&
				obj1->position.x + obj1->dimensions.x > obj2->position.x &&
				obj1->position.y < obj2->position.y + obj2->dimensions.y &&
				obj1->position.y + obj1->dimensions.y > obj2->position.y)
			{
				resolveAABB(obj1, obj2);
			}

		}
	}

	for (int x = 0; x < globalCircleList.size(); x++) {

		for (int y = x; y < globalCircleList.size(); y++) {

			CircleCollider* obj1 = globalCircleList[x];
			CircleCollider* obj2 = globalCircleList[y];

			if (obj1->id == obj2->id) {
				continue;
			}

			Vector2 relativePosition(obj1->position.x - obj2->position.x, obj1->position.y - obj2->position.y);
			
			double distance = sqrt(relativePosition.x * relativePosition.x + relativePosition.y * relativePosition.y);
			if (distance < obj1->diameter/2 + obj2->diameter / 2) {
				resolveCirc(obj1, obj2);
			}
		}
	}
}

void resolveAABB(RectCollider* obj1, RectCollider* obj2) {
	obj1->inCollision = true;
	obj2->inCollision = true;



	Vector2 obj1VelocityBuffer(obj1->rb->velocity.x, obj1->rb->velocity.y);
	Vector2 obj2VelocityBuffer(obj2->rb->velocity.x, obj2->rb->velocity.y);

	if (elasticCollisions) {

		obj1->rb->velocity.x = (((obj1->rb->mass - obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.x) + (((2 * obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj2VelocityBuffer.x);
		obj2->rb->velocity.x = (((2 * obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.x) + (((obj2->rb->mass - obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass))) * obj2VelocityBuffer.x;

		obj1->rb->velocity.y = (((obj1->rb->mass - obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.y) + (((2 * obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj2VelocityBuffer.y);
		obj2->rb->velocity.y = (((2 * obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.y) + (((obj2->rb->mass - obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass))) * obj2VelocityBuffer.y;

	}
	else {

		Vector2 relativeVelocity(obj2->rb->velocity.x - obj1->rb->velocity.x, obj2->rb->velocity.y - obj1->rb->velocity.y);
		Vector2 relativePosition(obj2->rb->position.x - obj1->rb->position.x, obj2->rb->position.y - obj1->rb->position.y);
		Vector2 normalRelativePosition = relativePosition.normal();



		//make a function for this soooooooon
		double dot = Dot(normalRelativePosition, relativeVelocity);



		//cout << dot << "- val \n";

		if (dot > 0) {
			return;
		}

		obj1->rb->velocity.x -= (Cr * obj2->rb->mass * (obj2VelocityBuffer.x - obj1VelocityBuffer.x) + obj1->rb->mass * obj1VelocityBuffer.x + obj2->rb->mass * obj2VelocityBuffer.x) / obj1->rb->mass * obj2->rb->mass;
		obj2->rb->velocity.x += (Cr * obj1->rb->mass * (obj1VelocityBuffer.x - obj2VelocityBuffer.x) + obj1->rb->mass * obj1VelocityBuffer.x + obj2->rb->mass * obj2VelocityBuffer.x) / obj1->rb->mass * obj2->rb->mass;

		obj1->rb->velocity.y -= (Cr * obj2->rb->mass * (obj2VelocityBuffer.y - obj1VelocityBuffer.y) + obj1->rb->mass * obj1VelocityBuffer.y + obj2->rb->mass * obj2VelocityBuffer.y) / obj1->rb->mass * obj2->rb->mass;
		obj2->rb->velocity.y += (Cr * obj1->rb->mass * (obj1VelocityBuffer.y - obj2VelocityBuffer.y) + obj1->rb->mass * obj1VelocityBuffer.y + obj2->rb->mass * obj2VelocityBuffer.y) / obj1->rb->mass * obj2->rb->mass;




		//obj2->rb->position.x += normalRelativePosition.x;
		obj2->rb->position.y += normalRelativePosition.y;
	}

}


void resolveCirc(CircleCollider* obj1, CircleCollider* obj2) {
	obj1->inCollision = true;
	obj2->inCollision = true;

	Vector2 obj1VelocityBuffer(obj1->rb->velocity.x, obj1->rb->velocity.y);
	Vector2 obj2VelocityBuffer(obj2->rb->velocity.x, obj2->rb->velocity.y);

	if (elasticCollisions) {

		obj1->rb->velocity.x = (((obj1->rb->mass - obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.x) + (((2 * obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj2VelocityBuffer.x);
		obj2->rb->velocity.x = (((2 * obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.x) + (((obj2->rb->mass - obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass))) * obj2VelocityBuffer.x;

		obj1->rb->velocity.y = (((obj1->rb->mass - obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.y) + (((2 * obj2->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj2VelocityBuffer.y);
		obj2->rb->velocity.y = (((2 * obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass)) * obj1VelocityBuffer.y) + (((obj2->rb->mass - obj1->rb->mass) / (obj1->rb->mass + obj2->rb->mass))) * obj2VelocityBuffer.y;

	}
	else {

		Vector2 relativeVelocity(obj2->rb->velocity.x - obj1->rb->velocity.x, obj2->rb->velocity.y - obj1->rb->velocity.y);
		Vector2 relativePosition(obj2->rb->position.x - obj1->rb->position.x, obj2->rb->position.y - obj1->rb->position.y);
		Vector2 normalRelativePosition = relativePosition.normal();



		double dot = Dot(normalRelativePosition, relativeVelocity);

		

		//cout << dot << "- val \n";

		if (dot > 0) {
			return;
		}

		obj1->rb->velocity.x -= (Cr * obj2->rb->mass * (obj2VelocityBuffer.x - obj1VelocityBuffer.x) + obj1->rb->mass * obj1VelocityBuffer.x + obj2->rb->mass * obj2VelocityBuffer.x) / obj1->rb->mass * obj2->rb->mass;
		obj2->rb->velocity.x += (Cr * obj1->rb->mass * (obj1VelocityBuffer.x - obj2VelocityBuffer.x) + obj1->rb->mass * obj1VelocityBuffer.x + obj2->rb->mass * obj2VelocityBuffer.x) / obj1->rb->mass * obj2->rb->mass;

		obj1->rb->velocity.y -= (Cr * obj2->rb->mass * (obj2VelocityBuffer.y - obj1VelocityBuffer.y) + obj1->rb->mass * obj1VelocityBuffer.y + obj2->rb->mass * obj2VelocityBuffer.y) / obj1->rb->mass * obj2->rb->mass;
		obj2->rb->velocity.y += (Cr * obj1->rb->mass * (obj1VelocityBuffer.y - obj2VelocityBuffer.y) + obj1->rb->mass * obj1VelocityBuffer.y + obj2->rb->mass * obj2VelocityBuffer.y) / obj1->rb->mass * obj2->rb->mass;




		//obj2->rb->position.x += normalRelativePosition.x;
		//obj2->rb->position.y += normalRelativePosition.y;
	}

}



RectCollider::RectCollider(Vector2 dim) {
	this->dimensions = dim;
	this->id = globalRectList.size();
	globalRectList.push_back(this);
}

RectCollider::~RectCollider() {}

void RectCollider::Attach(Rigidbody* toAttach) {
	rb = toAttach;
	
}

void RectCollider::Update() {
	this->position = rb->position;
}


// -------------------------------------------------------------------

CircleCollider::CircleCollider(double dia) {
	this->diameter = dia;
	this->id = globalCircleList.size();
	globalCircleList.push_back(this);
}

CircleCollider::~CircleCollider() {}

void CircleCollider::Attach(Rigidbody* toAttach) {
	this->rb = toAttach;

}

void CircleCollider::Update() {
	this->position = this->rb->position;
}

