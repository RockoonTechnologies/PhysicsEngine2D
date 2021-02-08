// PhysicsEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Rigidbody.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    Rigidbody rb = Rigidbody(3, Vector2(0, 0));
    
    for (int x = 0; x < 20; x++) {
        rb.Update();
        cout << to_string(rb.position.x) + "," + to_string(rb.position.y) + "\n";
    }
}

