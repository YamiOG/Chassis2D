#ifndef OBJECT_H
#define OBJECT_H 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>

#include "App.h"
#include "Texture.h"

using namespace std;

class Object{
 private:
  b2Body* body;

  Texture texture;
  float width, height;
  int scale;
 public:
  Object(){}
  Object(App a, float x, float y, float w, float h, float friction, float density, float restitution, bool isD, int setScale);
  int Setup(App a, float x, float y, float w, float h, float friction, float density, float restitution, bool isD, int setScale);

  //Physics
  b2Body *GetBody(){return body;}
  void SetBody(b2Body *sBody) {body = sBody;}
  void ApplyConstVelocity(b2Vec2 v);
  void ApplyImpulse(b2Vec2 v) { body->ApplyLinearImpulse( v, body->GetWorldCenter(), true); }
  b2Vec2 GetVelocity() { return body->GetLinearVelocity(); }

  //Render
  void Draw(App a);
  void SetTexture(Texture t) { texture = t; }
  SDL_Rect GetScaledPosition();
  Texture GetTexture(){return texture;}
};

#endif
