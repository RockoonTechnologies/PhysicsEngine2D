// PhysicsEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Rigidbody.h"


using namespace std;

int main()
{
    

    Rigidbody rb(2, Vector2(0, 0));
    rb.addForces(Vector2(10, 0));
    for (int x = 0; x < 20000; x++) {
       
        rb.Update();
        rb.position.print();
        
    }
}

