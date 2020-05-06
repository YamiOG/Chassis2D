#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <SDL2/SDL.h>

#include "Class.h"

using namespace std;

class Button{
 private:
  Text *text;
  Texture *texture;
  SDL_Rect rect;
  bool prev = false;
 public:
  Button(){}
  Button(int x, int y, int w, int h, Texture *t, const char* tx, Font *f);
  int Setup(int x, int y, int w, int h, Texture *t, const char* tx, Font *f);
  void SetPrev(bool set) { prev = set; }
  bool GetPrev() { return prev; }
  SDL_Rect GetRect() {return rect;}
  Texture* GetTexture() {return texture;}
  Text* GetText() {return text;}
};

#endif
