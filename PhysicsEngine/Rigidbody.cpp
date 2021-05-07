#include "Rigidbody.h"
#include "Vector2.h"
#include <vector>
#include <iostream>

using namespace std;

namespace Phys {

    

    Rigidbody::Rigidbody(double mass, Vector2 pos) {
        this->mass = mass;
        this->position = pos;
    }



    Rigidbody::~Rigidbody() {}

    void Rigidbody::Update() {

        //update time
        this->time += this->dt;



        this->acceleration.x = this->forces.x / this->mass;
        this->acceleration.y = (this->forces.y / this->mass) + this->gravity;


        //update position
        if (!locked) {
            this->position.x += this->velocity.x * this->dt + .5 * this->acceleration.x * (this->dt * this->dt);
            this->position.y += this->velocity.y * this->dt + .5 * this->acceleration.y * (this->dt * this->dt);
        }

        this->velocity.x += this->acceleration.x * this->dt;
        this->velocity.y += this->acceleration.y * this->dt;


        this->KE = .5 * this->mass * (this->velocity.x * this->velocity.x) + (this->velocity.y * this->velocity.y);

        this->area = this->dimensions.x * this->dimensions.y;
        this->density = this->mass / this->area;



        this->forces.x = 0;
        this->forces.y = 0;


    }

    void Rigidbody::addForces(Vector2 toAdd) {
        this->forces += toAdd;
    }


    void RigidbodyUpdate(vector<Rigidbody*>& globalRigidbodyList) {
       
        for (int x = 0; x < globalRigidbodyList.size(); x++) {
            Rigidbody* obj = globalRigidbodyList[x];
            obj->Update();
            
        }
    }
}
