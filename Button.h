#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL2/SDL.h>

#include "App.h"
#include "Text.h"

using namespace std;

class Button{
 private:
  Text text;
  SDL_Texture *texture;
  SDL_Rect rect;
  SDL_Point pos;
 public:
  Button(){}
  Button(int x, int y, int w, SDL_Texture *t, int h, const char* tx, Font f);
  int Setup(int x, int y, int w, int h, SDL_Texture *t, const char* tx, Font f);
  void Draw(App a);
};

#endif
