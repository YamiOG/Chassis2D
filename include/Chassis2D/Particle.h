#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <vector>

#include "Global.h"
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
  Particle(Vec4 rect, int lifetime);
  int Setup(Vec4 rect, int lifetime);
  Particle(Vec4 rect, float friction, float density, float restitution, int lifetime);
  int Setup(Vec4 rect, float friction, float density, float restitution, int lifetime);
  Particle(Vec4 rect, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime);
  int Setup(Vec4 rect, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime);
  Particle(float x, float y, float w, float h, int lifetime);
  int Setup(float x, float y, float w, float h, int lifetime);
  Particle(float x, float y, float w, float h, float friction, float density, float restitution, int lifetime);
  int Setup(float x, float y, float w, float h, float friction, float density, float restitution, int lifetime);
  Particle(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime);
  int Setup(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime);

  int GetTime() { return time; }
  int GetLifetime() { return lifetime; }
  void SetLifetime(int lifetime) { this->lifetime = lifetime; }
  void SetTime(int time) { this->time = time; }

  ~Particle();
};

#endif
