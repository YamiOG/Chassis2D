#ifndef OBJECT_H
#define OBEJCT_H

#include <iostream>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

#include "Chassis.h"

using namespace std;

class Object{
 private:
  float width, height;
  int scale;
 public:
  b2Body* body;
  Object(){}
  void Setup(Chassis c, float x, float y, float w, float h, float friction, float density, float restitution, bool isD, int setScale);
  SDL_Rect GetScaledPosition();
};

#endif
