// PhysicsEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Rigidbody.h"

using namespace std;

int main()
{
    std::cout << "Hello World!\n";

    Vector2 vec1(1, 2);
    Vector2 vec2(5, 5);
    vec2 += vec1;

    Rigidbody rb(2, Vector2(0, 0));
    
    for (int x = 0; x < 20000000000; x++) {
        rb.Update();
        cout << to_string(rb.position.x) + "," + to_string(rb.position.y) + "\n";
    }
}

