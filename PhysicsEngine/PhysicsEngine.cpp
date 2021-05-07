
#include "Simulation.h"
#include <iostream>


using namespace Phys;




int main()
{

    Rigidbody body1(1, Vector2(0, 0));
   


    AddToSimulation(&body1);
   
    for (int x = 0; x < 20; x++) {
        Update(1);
        body1.position.print();
        
    }
        
    
  
}

