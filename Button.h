#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL2/SDL.h>

#include "Text.h"

using namespace std;

class Button{
 private:
  Text text;
  SDL_Texture *texture;
  SDL_Point pos;
 public:
  Button(){}
  Button(int x, int y, int w, int h, const char* text, Font f);
  int Setup(int x, int y, int w, int h, const char* text, Font f);
  void Draw(App a);
};

#endif
