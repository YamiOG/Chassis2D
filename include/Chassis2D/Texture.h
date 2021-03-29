#ifndef TEXTURE_H
#define TEXTURE_H 

#include <iostream>

#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

struct SDL_Surface;
struct SDL_Texture;

class Texture{
 private:
  SDL_Texture *texture;
  int width, height;
 public:
  Texture(){}
  Texture(App *a, const char* location);
  Texture(SDL_Texture *t);
  Texture(App *a, SDL_Surface *surface);
  int Setup(App *a, const char* location);
  int Setup(SDL_Texture *t);
  int Setup(App *a, SDL_Surface *surface);
  SDL_Texture *GetData(){ return texture;}
  Vec4 GetCrop();
  Vec2 GetSize() { return Vec2((float)width, (float)height); }

  ~Texture();
};

#endif