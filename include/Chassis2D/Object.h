#ifndef OBJECT_H
#define OBJECT_H 

#include <iostream>
#include <memory>
#include <cstdint>

#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class b2Body;

class Object{
 private:
 protected:
  App *a = nullptr;
  b2Body* body = nullptr;
  shared_ptr<Texture> texture;

  float width, height;
  int xOffset, yOffset, tWidth, tHeight, scale;
  bool hide = false;
 public:
  Object(){}
  Object(App *a, float x, float y, float w, float h, int categoryBits, int maskBits, int scale);
  int Setup(App *a, float x, float y, float w, float h, int categoryBits, int maskBits, int scale);
  int Static(App *a, float x, float y, float w, float h, int categoryBits, int maskBits, int scale);
  Object(App *a, float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int scale);
  int Setup(App *a, float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int scale);
  int Dynamic(App *a, float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int scale);
  Object(App *a, float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, bool isDynamic, int scale);
  int Setup(App *a, float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, bool isDynamic, int scale);

  //Physics
  b2Body *GetBody(){ return body; }
  void SetBody(b2Body *body) {this->body = body; }
  void SetVelocity(Vec2 v);
  void RotationFixed(bool fixed);
  int ApplyConstVelocity(Vec2 v);
  int ApplyConstVelocity(Vec2 v, bool jumping);
  void ApplyImpulse(Vec2 v);
  Vec2 GetVelocity();
  Vec4 GetCollisionBox();
  void SetActive(bool set);
  int GetScale() { return scale; }
  void SetPosition(Vec2 position);
  void SetSensor(float x, float y, float w, float h, int categoryBits, int maskBits, int id);
  void SetBullet(bool bullet);
  float GetMass();
  float GetAngle();
  bool IsActive();

  //Render
  void SetTexture(Texture* t, int xOffset, int yOffset, int w, int h);
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
