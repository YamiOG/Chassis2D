#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

#include "Class.h"

#include "Object.h"

#include "Vec2.h"

using namespace std;

class Particle : public Object{
 private:
  int lifetime, time;

  float friction, density, restitution;

 public:
  Particle(){}
  Particle(float width, float height, float friction, float density, float restitution, int lifetime, Texture *texture, int scale);
  int Setup(float width, float height, float friction, float density, float restitution, int lifetime, Texture *texture, int scale);

  int GetTime() {return time;}
  int GetLifetime() { return lifetime; }

  int Create(App *a, int x, int y);
  void SetLifetime(int set) {lifetime = set;}
  void SetTime(int set) {time = set;}

  //Destructor
  ~Particle();
};

#endif
