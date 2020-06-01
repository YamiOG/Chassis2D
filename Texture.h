#ifndef TEXTURE_H
#define TEXTURE_H 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class Texture{
 private:
  SDL_Texture *texture;
  int width, height, hNum, vNum, wFrame, hFrame;
  bool sheet;
 public:
  Texture(){}
  Texture(App *a, const char* loc);
  Texture(App *a, const char* loc, int hN, int vN, bool isS);
  Texture(SDL_Texture *t);
  Texture(SDL_Texture *t, int hN, int vN, bool isS);
  Texture(App *a, SDL_Surface *surf);
  Texture(App *a, SDL_Surface *surf, int hN, int vN, bool isS);
  int Setup(App *a, const char* loc);
  int Setup(App *a, const char* loc, int hN, int vN, bool isS);
  int Setup(SDL_Texture *t);
  int Setup(SDL_Texture *t, int hN, int vN, bool isS);
  int Setup(App *a, SDL_Surface *surf);
  int Setup(App *a, SDL_Surface *surf, int hN, int vN, bool isS);
  SDL_Texture *GetData(){return texture;}
  SDL_Rect GetCrop();
  SDL_Rect GetFrame(int num);
  Vec2 GetSize() { return Vec2(width, height); }

  ~Texture();
};

#endif