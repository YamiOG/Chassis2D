#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Chassis.h"
#include "Font.h"

using namespace std;

class Text{
 private:
  SDL_Texture *t;
  SDL_Rect rect;
  Font f;
  string text;
  int iTime;

 public:
  Text(){}
  Text(int x, int y, Font font, const char* tx);
  int Setup(int x, int y, Font font, const char* tx);
  SDL_Texture *GetText(Chassis c);
  void Draw(Chassis c);
};

#endif
