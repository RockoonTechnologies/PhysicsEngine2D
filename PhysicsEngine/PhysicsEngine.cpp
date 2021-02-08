// PhysicsEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Rigidbody.h"
#include <chrono>

using namespace std;

int main()
{
    

    Rigidbody rb(2, Vector2(0, 0));
    
    for (int x = 0; x < 20000000000; x++) {
        auto start = std::chrono::high_resolution_clock::now();
        rb.Update();
        cout << to_string(rb.position.x) + "," + to_string(rb.position.y) + "\n";
        auto finish = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> elapsed = finish - start;
        cout << elapsed.count() << "\n";
    }
}

