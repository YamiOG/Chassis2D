#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "App.h"
#include "Font.h"

using namespace std;

class Text{
 private:
  SDL_Texture *t;
  SDL_Point pos;
  SDL_Rect rect;
  Font f;
  string text;
  int iTime = -1;

 public:
  Text(){}
  Text(int x, int y, Font font, const char* tx);
  int Setup(int x, int y, Font font, const char* tx);
  SDL_Texture *GetText(App a);
  void Draw(App a);
};

#endif
