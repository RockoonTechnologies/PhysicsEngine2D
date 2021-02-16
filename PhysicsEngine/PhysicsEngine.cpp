// PhysicsEngine.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "Rigidbody.h"
#include "Collision.h"
#include "Joints.h"

#include <vector>


using namespace std;

Rigidbody body1(1, Vector2(0, 0));
Rigidbody body2(1, Vector2(0, 5));

int main()
{
    

    
    

    for (int x=0; x < 10; x++) {
        double xPos = (double)x * 10;
        Rigidbody rb(1, Vector2(xPos, 100));

        rbList.push_back(rb);
    }
   
    


    //rb1.addForces(Vector2(10, 0));
    for (int x = 0; x < 200; x++) {
       
        for (int y = 0; y < rbList.size(); y++) {
            rbList[y].Update();
        }

        rbList.position.print();

      

       

       
       
        
    }
}

