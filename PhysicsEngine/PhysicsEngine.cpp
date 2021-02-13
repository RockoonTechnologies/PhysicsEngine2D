// PhysicsEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Rigidbody.h"
#include "Collision.h"

using namespace std;

int main()
{
    

    Rigidbody rb1(1, Vector2(0, 2));
    Rigidbody rb2(4, Vector2(0, 0));

    rb2.gravity = 0;

    RectCollider coll1(Vector2(1, 1));
    RectCollider coll2(Vector2(1, 1));

    coll1.Attach(&rb1);
    coll2.Attach(&rb2);



    //rb1.addForces(Vector2(10, 0));
    for (int x = 0; x < 200; x++) {
       
        rb1.Update();
        rb2.Update();

        CollisionUpdate();

        if (coll1.inCollision) {
            cout << "Colliding!" << "\n";
        }
        else {
            cout << "Nope!" << "\n";
        }
        cout << "Body 1: \n";
        coll1.position.print();
        rb1.velocity.print();
        cout << "Body 2: \n";
        coll2.position.print();
        rb2.velocity.print();

       
       
        
    }
}

