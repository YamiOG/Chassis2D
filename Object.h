#ifndef OBJECT_H
#define OBJECT_H 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>

#include "Class.h"

using namespace std;

class Object{
 private:
  b2Body* body;
  b2BodyDef bodyDef;
  b2FixtureDef fixture;
  b2PolygonShape shape;

  Texture* texture;
  float width, height;
  int scale;
 public:

  Object(){}
  Object(float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, bool isD, int setScale);
  int Setup(float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, bool isD, int setScale);

  //Physics
  b2Body *GetBody(){return body;}
  void SetBody(b2Body *sBody) {body = sBody;}
  b2BodyDef *const GetBodyDef() {return &bodyDef;}
  b2FixtureDef *const GetFixtureDef() {return &fixture;}
  void ApplyConstVelocity(b2Vec2 v);
  void ApplyImpulse(b2Vec2 v) { if(body) body->ApplyLinearImpulse( v, body->GetWorldCenter(), true);}
  b2Vec2 GetVelocity() { return (body) ? body->GetLinearVelocity() : b2Vec2(0,0); }

  //Render
  void SetTexture(Texture* t) { texture = t; }
  SDL_Rect GetScaledPosition();
  Texture* GetTexture(){return texture;}

  //Destructor
  ~Object();
};

#endif
