#ifndef OBJECT_H
#define OBJECT_H 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>

#include "Chassis.h"
#include "Texture.h"

using namespace std;

class Object{
 private:
  Texture texture;
  float width, height;
  int scale;

  b2Body* body;
 public:
  Object(){}
  int Setup(Chassis c, float x, float y, float w, float h, float friction, float density, float restitution, bool isD, int setScale);
  void SetTexture(Texture t) { texture = t; }
  SDL_Rect GetScaledPosition();
  Texture GetTexture(){return texture;}
  b2Body *GetBody(){return body;}
  void SetBody(b2Body *sBody) {body = sBody;}
  void Draw(Chassis c);
};

#endif
