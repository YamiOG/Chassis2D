#ifndef OBJECT_H
#define OBJECT_H 

#include <iostream>
#include <memory>
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
  App *a = nullptr;
  b2Body* body = nullptr;
  shared_ptr<Texture> texture;

  float width, height;
  int scale;
  bool hide = false;
 public:

  Object(){}
  Object(App *a, float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, bool isD, int scale);
  virtual int Setup(App *a, float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, bool isD, int scale);

  //Physics
  b2Body *GetBody(){ return body; }
  void SetBody(b2Body *body) {this->body = body; }
  void SetVelocity(Vec2 v) { if(body) body->SetLinearVelocity(v.ToB2()); }
  void RotationFixed(bool fixed) { if(body) body->SetFixedRotation(fixed); }
  int ApplyConstVelocity(Vec2 v);
  int ApplyConstVelocity(Vec2 v, bool jumping);
  void ApplyImpulse(Vec2 v) { v.Multi(body->GetMass()); if(body) body->ApplyLinearImpulse( v.ToB2(), body->GetWorldCenter(), true); } 
  Vec2 GetVelocity() { return (body) ? Vec2(body->GetLinearVelocity()) : Vec2(0,0); }
  void SetActive(bool set) { if(body) body->SetAwake(set); }
  int GetScale() { return scale; }
  void SetPosition(Vec2 position) { if(body) body->SetTransform(position.ToB2(), 0); } 
  void SetSensor(float x, float y, float w, float h, uint16 categoryBits, uint16 maskBits, int id);
  void SetBullet(bool bullet) { if(body) body->SetBullet(bullet); }
  float GetMass() { return body->GetMass(); }
  float GetAngle() { return body->GetAngle(); }
  bool IsActive() { return (body) ? body->IsAwake() : false; }

  //Render
  void SetTexture(Texture* t) { shared_ptr<Texture> sharedTex(t); texture = sharedTex; }
  Vec4 GetRect();
  shared_ptr<Texture> GetTexture(){ return texture; }

  void Hide() { hide = true; }
  void Show() { hide = false; }
  void SetHide(bool hide) { this->hide = hide; }
  bool IsHidden() { return hide; }

  //Destructor
  virtual ~Object();
};

#endif
