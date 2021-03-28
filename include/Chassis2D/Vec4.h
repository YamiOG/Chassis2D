#ifndef VEC4_H
#define VEC4_H 

#include <iostream>

#include <SDL.h>

#include "Class.h"

using namespace std;

struct SDL_Rect;

class Vec4{
 private:
  SDL_Rect *rect;
 public:
  float x, y, w, h; 
  Vec4(){}
  Vec4(float x, float y, float w, float h) { this->x = x; this->y = y; this->w = w; this->h = h; }
  Vec4(SDL_Rect *p);

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

  SDL_Rect *ToSDL();
};

#endif