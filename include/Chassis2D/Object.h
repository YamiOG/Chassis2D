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
  int scale;
  Vec2 size, offset, origin;

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
  void SetVelocity(Vec2 velocity);
  void RotationFixed(bool fixed);
  int ApplyConstVelocity(Vec2 velocity);
  int ApplyConstVelocity(Vec2 velocity, bool jumping);
  void ApplyImpulse(Vec2 velocity);
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
  Vec4 GetRect();
  void SetRect(Vec4 rect);

  void SetTexture(Texture* t, int xOffset, int yOffset, int width, int height);
  void SetTexture(Texture* t, Vec2 offset, int width, int height);
  void SetTexture(Texture* t, int xOffset, int yOffset, Vec2 size);
  void SetTexture(Texture* t, Vec2 offset, Vec2 size);
  shared_ptr<Texture> GetTexture(){ return texture; }
  Vec2 GetTextureSize() { return size; }

  void SetOffset(int xOffset, int yOffset) { offset.x = (float)xOffset; offset.y = (float)yOffset; }
  void SetOffset(Vec2 offset) { this->offset = offset; }
  Vec2 GetOffset() { return offset; }

  void SetOrigin(Vec2 origin) { this->origin = origin; }
  Vec2 GetOrigin() { return origin; }

  void Hide() { hide = true; }
  void Show() { hide = false; }
  void SetHide(bool hide) { this->hide = hide; }
  bool IsHidden() { return hide; }

  //Destructor
  virtual ~Object();
};

#endif
