#ifndef TEXTURE_H
#define TEXTURE_H 

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Box2D/Box2D.h>

#include "Class.h"

using namespace std;

class Texture{
 private:
  SDL_Texture *texture;
  int width, height, hNum, vNum, wFrame, hFrame;
  bool sheet;
 public:
  Texture(){}
  Texture(App *a, const char* loc, int hN, int vN, bool isS);
  int Setup(App *a, const char* loc, int hN, int vN, bool isS);
  SDL_Texture *GetTexture(){return texture;}
  SDL_Rect GetCrop();
  SDL_Rect GetFrame(int num);
};

#endif
