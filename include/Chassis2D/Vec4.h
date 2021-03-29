#ifndef VEC4_H
#define VEC4_H 

#include <iostream>

#include "Class.h"

using namespace std;

class Vec4{
 private:
 public:
  float x, y, w, h; 
  Vec4(){}
  Vec4(float x, float y, float w, float h) { this->x = x; this->y = y; this->w = w; this->h = h; }

  void Multi(Vec4 val) { x *= val.x; y *= val.y; w *= val.w; h *= val.h; }
  void Multi(float val) { x *= val; y *= val; w *= val; h *= val; }
  void Div(Vec4 val) { x /= val.x; y /= val.y; w /= val.w; h /= val.h; }
  void Div(float val) { x /= val; y /= val; w /= val; h /= val; }
  void Subt(Vec4 val) { x -= val.x; y -= val.y; w -= val.w; h -= val.h; }
  void Subt(float val) { x -= val; y -= val; w -= val; h -= val; }
  void Add(Vec4 val) { x += val.x; y += val.y; w += val.w; h += val.h; }
  void Add(float val) { x += val; y += val; w += val; h += val; }

  Vec4 operator *(Vec4 val) { return Vec4(x * val.x, y * val.y, w * val.w, h * val.h); }
  Vec4 operator *(float val) { return Vec4(x * val, y * val, w * val, h * val); }
  Vec4 operator /(Vec4 val) { return Vec4(x / val.x, y / val.y, w / val.w, h / val.h); }
  Vec4 operator /(float val) { return Vec4(x / val, y / val, w / val, h / val); }
  Vec4 operator -(Vec4 val) { return Vec4(x - val.x, y - val.y, w - val.w, h - val.h); }
  Vec4 operator -(float val) { return Vec4(x - val, y - val, w - val, h - val); }
  Vec4 operator +(Vec4 val) { return Vec4(x + val.x, y + val.y, w + val.w, h + val.h); }
  Vec4 operator +(float val) { return Vec4(x + val, y + val, w + val, h + val); }
};

#endif