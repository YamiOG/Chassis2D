#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL2/SDL.h>

#include "App.h"
#include "Texture.h"
#include "Text.h"

using namespace std;

class Button{
 private:
  Text *text;
  Texture *texture;
  SDL_Rect rect;
  bool prev = false;
  bool pressed = false;
 public:
  Button(){}
  Button(int x, int y, int w, int h, Texture *t, const char* tx, Font *f);
  int Setup(int x, int y, int w, int h, Texture *t, const char* tx, Font *f);
  bool IsPressed(App *a);
  SDL_Rect GetRect() {return rect;}
  Texture* GetTexture() {return texture;}
  Text* GetText() {return text;}
};

#endif
