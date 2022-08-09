#ifndef OBJECT_H
#define OBJECT_H 

#include <iostream>
#include <memory>
#include <cstdint>

#include "Global.h"
#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class b2Body;

class Object{
 private:
 protected:
  b2Body* body = nullptr;
  shared_ptr<Texture> texture;

  float width, height;

  Vec2 texSize, offset;

  bool hide = false;
 public:
  Object(){}

  //Creates a static object taking x, y, w, and h as inputs
  Object(float x, float y, float w, float h);
  int Setup(float x, float y, float w, float h);
  int Static(float x, float y, float w, float h);

  //Creates a static object taking x, y, w, h, categoryBits, and maskBits as inputs
  Object(float x, float y, float w, float h, int categoryBits, int maskBits);
  int Setup(float x, float y, float w, float h, int categoryBits, int maskBits);
  int Static(float x, float y, float w, float h, int categoryBits, int maskBits);

  //Creates a dynamic object taking x, y, w, h, friction, density, and restitution as inputs
  Object(float x, float y, float w, float h, float friction, float density, float restitution);
  int Setup(float x, float y, float w, float h, float friction, float density, float restitution);
  int Dynamic(float x, float y, float w, float h, float friction, float density, float restitution);

  //Creates a dynamic object taking x, y, w, h, friction, density, restitution, categoryBits, and maskBits as inputs
  Object(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits);
  int Setup(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits);
  int Dynamic(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits);
 
  //Creates a dynamic or static object taking x, y, w, h, friction, density, restitution, categoryBits, and maskBits as inputs
  Object(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, bool isDynamic);
  int Setup(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, bool isDynamic);

  /////////
  //Physics
  b2Body *GetBody(){ return body; }
  void SetBody(b2Body *body) {this->body = body; }
  Vec4 GetCollisionBox(); //Returns position and the size of the collision box

  void SetVelocity(Vec2 velocity); //Sets the xy velocity
  void SetVelocity(float magnitude, float angle); //Use magnitude and an angle to set xy velocity
  void SetAngularVelocity(float magnitude);
  Vec2 GetVelocity();

  int ApplyConstSpeed(Vec2 velocity); //Applies a force that creates a constant desired velocity
  int ApplyConstSpeed(Vec2 velocity, bool jumping); //Applies a force that creates a constant desired velocity; can disable in one axis
  void ApplyImpulse(Vec2 impulse);

  void SetActive(bool set); //Sets object active or inactive in the simulation
  bool IsActive(); //Checks if the object is active in the simulation

  void SetPosition(Vec2 position);
  void SetPosition(Vec2 position, float angle);

  void SetSensor(float xOffset, float yOffset, float w, float h, int categoryBits, int maskBits, int id); //Creates a sensor on the object that can be used to detect specific collisions
  bool IsSensorColliding(int id); //Checks for collisions on sensors using an sensor ID defined previously

  void SetGravityScale(float value);
  float GetGravityScale();

  void RotationFixed(bool fixed); //Freezes rotation of object; fixes the rotation
  void SetBullet(bool bullet); //Checks continously for collisions; used for fast moving objects
  float GetMass();
  float GetAngle();

  ////////
  //Render
  Vec4 GetRect(); //Returns a position and texture size; ideal for rendering
  void SetRect(Vec4 rect); //Sets a position and texture size; sets rendering attributes not physics 

  void SetTexture(Texture* t);
  void SetTexture(Texture* t, int width, int height);

  shared_ptr<Texture> GetTexture(){ return texture; }

  //Sets the texture and its offset from the collision box
  void SetTexture(Texture* t, int xOffset, int yOffset, int width, int height); 
  void SetTexture(Texture* t, Vec2 offset, int width, int height);
  void SetTexture(Texture* t, int xOffset, int yOffset, Vec2 size);
  void SetTexture(Texture* t, Vec2 offset, Vec2 size);

  Vec2 GetTextureSize() { return texSize; } //Returns the size that the texture will be rendered at
  void SetTextureSize(Vec2 size) { texSize = size; } //Sets the size that the texture will be rendered at

  //Sets the offset of the texture from the collision box
  void SetOffset(int xOffset, int yOffset) { offset.x = (float)xOffset; offset.y = (float)yOffset; }
  void SetOffset(Vec2 offset) { this->offset = offset; }

  Vec2 GetOffset() { return offset; }

  void Hide() { hide = true; }
  void Show() { hide = false; }
  void SetHide(bool hide) { this->hide = hide; }
  bool IsHidden() { return hide; }

  //Destructor
  virtual ~Object();
};

#endif