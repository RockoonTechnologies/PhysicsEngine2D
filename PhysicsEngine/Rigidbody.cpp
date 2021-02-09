#include "Rigidbody.h"
#include "Vector2.h"

using namespace std;

Rigidbody::Rigidbody(double mass, Vector2 pos) {
    this->mass = mass;
    this->position = pos;

}

Rigidbody::~Rigidbody() {}

void Rigidbody::Update() {

    //update time
    this->time += this->dt;


    this->forces.y = gravity;

    this->acceleration.x = this->forces.x / this->mass;
    this->acceleration.y = this->forces.y / this->mass;


    //update position
    this->position.x += this->velocity.x * this->dt + .5 * this->acceleration.x * (this->dt * this->dt);
    this->position.y += this->velocity.y * this->dt + .5 * this->acceleration.y * (this->dt * this->dt);

    this->velocity.x += this->acceleration.x * this->dt;
    this->velocity.y += this->acceleration.y * this->dt;


    this->forces.x = 0;
    this->forces.y = 0;

    
}

void Rigidbody::addForces(Vector2 toAdd) {
    this->forces += toAdd;
}