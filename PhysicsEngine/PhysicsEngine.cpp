// PhysicsEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Rigidbody.h"
#include "Collision.h"

using namespace std;

int main()
{
    

    Rigidbody rb1(2, Vector2(0, 0));
    Rigidbody rb2(1, Vector2(0, 0));

    RectCollider coll1(Vector2(1, 1));
    RectCollider coll2(Vector2(1, 1));

    coll1.Attach(rb1);
    coll2.Attach(rb2);



    //rb1.addForces(Vector2(10, 0));
    for (int x = 0; x < 2000000; x++) {
       
        rb1.Update();
        rb2.Update();

        CollisionUpdate();

        if (coll1.inCollision) {
            cout << "Colliding!" << "\n";
        }
        else {
            cout << "Nope!" << "\n";
        }

       
       
        
    }
}

