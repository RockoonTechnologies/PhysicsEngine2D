#include "Collision.h"
#include "Rigidbody.h"
#include "Vector2.h"
#include <vector>

using namespace std;


vector<RectCollider> globalList;


RectCollider::RectCollider(Vector2 dim=(0,0)) {
	this->dimensions = dim;
	this->id = globalList.size();
	globalList.push_back(this);

}

RectCollider::~RectCollider() {}

void RectCollider::Attach(Rigidbody toAttach) {
	this->rb = toAttach;
}

void RectCollider::Update() {

}
