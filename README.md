# Hi!

## What is this?
This is an attempt to teach myself C++ and reintroduce basic Physics concepts to myself, the end result is a C++ library designed for basic (yet accurate) physics simulations for whatever your desire is.

Keep in mind this is my first big C++ fueled adventure, so dont expect *quality* code

## How Can I use it?
Currently the option is simply: pull the files.
I will make a tidy package and  a DLL once I am happy with the result.

# What Can it Do?
**Messing with forces, etc- Basic Kinematics**

**[Springs, and harmonic motion- Basic Joints](https://imgur.com/OnvdAoF)**

**Elastic and Inelastic Collisions![Elastic and Inelastic Collisions](https://i.imgur.com/nKGVOIG.gif)** (still need work lol)

**Circle & Rectangular Colliders**


And its really easy to use :)

# Basic Usage
```c++
//import the main thing
#include "Simulation.h"

//everything uses the "Phys" namespace
using namespace Phys;

int main()
{
    //create Rigidbodies, at different positions with the same mass
    Rigidbody body1(1, Vector2(0, 0));
    Rigidbody body2(1, Vector2(0, 5));

    //add them to the sim
    AddToSimulation(&body1);
    AddToSimulation(&body2);
   
    // a loop to run
    for (int x = 0; x < 20; x++) {
        //update the simulation by one step
        Update(1);
        //print the position of the first body
        body1.position.print();    
    }
            
}
```

# Overview

This package operates with a basic style:

1. Create a physics object with some parameters
2. Add that to the simulation
3. Done!

The simulation holds lists of every object, manages them, and updates them, makes it super easy.

The most common object you will use is the `Rigidbody` this is a standard, solid shape (ie: a Rectangle or Circle) that can experience physics. This is the good stuff.

Another Biggie is the `Vector2` object that holds 2 dimensional data and is what holds everything from position, to forces in literally everything. It also comes with basic math methods that make life a little easier.

Then you have `colliders`, which "Attach" to Rigidbodies and allow them to interact with eachother. There are two modes: Elastic and Inelastic Collisions.

Lastly, you have `joints` which allow Rigidbodies to interact with eachother in more innovative ways, creating "bonds/realtionships" between them.


# Reference
How to actually use stuff!

### `Rigidbody(double mass, Vector2(positionX, positionY))`
- `double gravity`- the gravity the rigidbody experiences
- `double dt` - dt for the body, soon this will be controlled from `Simulation`- by default this is `0.01`
- `bool locked` - prevents the rigidbody from moving, kinda glitchy
- `Vector2 velocity`
- `Vector2 position`
- `void addForces(Vector2 forcesToAdd)` - adds forces to the body.


### `RectCollider(Vector2 dimensions)`
- `bool inCollision`- shows wether the object is currently in collision
- `Vector2 dimensions` - the dimensions of the Collider
- `Vector2 position` position of the collider
- `void Attach(Rigidbody* rb)` - connects the collider to a Rigidbody, **is required for operation**


### `CircleCollider(double diameter)`
- `bool inCollision`- shows wether the object is currently in collision
- `Vector2 diameter` - the diameter of the Collider
- `Vector2 position` position of the collider
- `void Attach(Rigidbody* rb)` - connects the collider to a Rigidbody, **is required for operation**


### `SpringJoint(Rigidbody* r1, Rigidbody* r2, RectCollider* col);`
- `double stiffness` - the Stiffness of the "spring"

### `FixedJoint(Rigidbody* r, Rigidbody* rs1, Vector2 offset);`
