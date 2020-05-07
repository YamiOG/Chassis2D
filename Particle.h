#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

#include "Class.h"

using namespace std;

class Particle{
 private:
  int lifetime;
  int width, height;
  float dx, dy;
  Texture *texture;

  b2Body *body;
  
 public:
  Particle(){}
  Particle(App* a, int width, int height, int lifetime, Texture *texture);
  void Setup(App* a, int width, int height, int lifetime, Texture *texture);

  Texture *GetTexture() { return texture; }

  //Destructor
  ~Particle();
};

#endif
