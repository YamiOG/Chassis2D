#ifndef OBJECT_H
#define OBJECT_H 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>

#include "Class.h"

#include "Vec2.h"

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
  b2BodyDef *GetBodyDef() {return &bodyDef;}
  b2FixtureDef *GetFixtureDef() {return &fixture;}
  void ApplyConstVelocity(Vec2 v);
  void ApplyImpulse(Vec2 v) { if(body) body->ApplyLinearImpulse( v.ToB2(), body->GetWorldCenter(), true);}
  Vec2 GetVelocity() { return (body) ? Vec2(body->GetLinearVelocity()) : Vec2(0,0); }
  void SetActive(bool set) { if(body) body->SetActive(set); }
  void SetCollision(bool val);

  //Render
  void SetTexture(Texture* t) { texture = t; }
  SDL_Rect GetScaledPosition();
  Texture* GetTexture(){return texture;}
  bool GetActive() { return (body) ? body->IsActive() : false; }

  //Destructor
  ~Object();
};

#endif
