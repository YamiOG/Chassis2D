#ifndef OBJECT_H
#define OBEJCT_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>

#include "Chassis.h"

using namespace std;

class Object{
 private:
  SDL_Texture *texture;
  float width, height;
  int scale;
 public:
  b2Body* body;
  Object(){}
  int Setup(Chassis c, float x, float y, float w, float h, float friction, float density, float restitution, bool isD, int setScale);
  int SetTexture(Chassis c, const char* loc);
  SDL_Rect GetScaledPosition();
  SDL_Texture *GetTexture(){return texture;}
  void Draw(Chassis c);
};

#endif
