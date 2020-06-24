#ifndef VEC2_H
#define VEC2_H

#include <iostream>
#include <Box2D/Box2D.h>

class Vec2{
 private:
 public:
  float x, y;
  Vec2(){}
  Vec2(float x, float y) { this->x = x; this->y = y; }
  Vec2(b2Vec2 p) { this->x = p.x; this->y = p.y; }

  void Multi(Vec2 val) { x *= val.x; y *= val.y; }
  void Multi(float val) { x *= val; y *= val; }
  void Div(Vec2 val) { x /= val.x; y /= val.y; }
  void Div(float val) { x /= val; y /= val; }
  void Subt(Vec2 val) { x -= val.x; y -= val.y; }
  void Subt(float val) { x -= val; y -= val; }
  void Add(Vec2 val) { x += val.x; y += val.y; }
  void Add(float val) { x += val; y += val; }

  Vec2 operator *(Vec2 val) { return Vec2(x * val.x, y * val.y); }
  Vec2 operator *(float val) { return Vec2(x * val, y * val); }
  Vec2 operator /(Vec2 val) { return Vec2(x / val.x, y / val.y); }
  Vec2 operator /(float val) { return Vec2(x / val, y / val); }
  Vec2 operator -(Vec2 val) { return Vec2(x - val.x, y - val.y); }
  Vec2 operator -(float val) { return Vec2(x - val, y - val); }
  Vec2 operator +(Vec2 val) { return Vec2(x + val.x, y + val.y); }
  Vec2 operator +(float val) { return Vec2(x + val, y + val); }

  b2Vec2 ToB2() { return b2Vec2(x, y);}
};

#endif
