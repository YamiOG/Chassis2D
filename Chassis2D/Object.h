#ifndef OBJECT_H
#define OBJECT_H 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>

#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class Object{
 private:
 protected:
  b2Body* body;

  Texture* texture;
  float width, height;
  int scale;
 public:

  Object(){}
  Object(App *a, float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, bool isD, int scale);
  virtual int Setup(App *a, float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, bool isD, int scale);

  //Physics
  b2Body *GetBody(){ return body; }
  void SetBody(b2Body *body) {this->body = body; }
  void SetVelocity(Vec2 v) { if(body) body->SetLinearVelocity(v.ToB2()); }
  void RotationFixed(bool fixed) { if(body) body->SetFixedRotation(fixed); }
  void ApplyConstVelocity(Vec2 v, bool jumping);
  void ApplyImpulse(Vec2 v) { v.Multi(body->GetMass()); if(body) body->ApplyLinearImpulse( v.ToB2(), body->GetWorldCenter(), true); } 
  Vec2 GetVelocity() { return (body) ? Vec2(body->GetLinearVelocity()) : Vec2(0,0); }
  void SetActive(bool set) { if(body) body->SetActive(set); }
  int GetScale() { return scale; }
  void SetPosition(Vec2 position) { if(body) body->SetTransform(position.ToB2(), 0); } 
  void SetSensor(float x, float y, float w, float h, uint16 categoryBits, uint16 maskBits, int id);
  float GetMass() { return body->GetMass(); }
  float GetAngle() { return body->GetAngle(); }

  //Render
  void SetTexture(Texture* t) { texture = t; }
  Vec4 GetRect();
  Texture* GetTexture(){ return texture; }
  bool IsActive() { return (body) ? body->IsActive() : false; }

  //Destructor
  ~Object();
};

#endif
