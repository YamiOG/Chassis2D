#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Class.h"

#include "Vec4.h"

using namespace std;

class Font{
 private:
  TTF_Font *font;
  SDL_Color color;
  bool rgb;
  int divisor = 1;
  int size;
 public:
  Font(){}
  Font(const char* fLoc, int s, int r, int g, int b, bool setRGB);
  int Setup(const char* fLoc, int s, int r, int g, int b, bool setRGB);
  shared_ptr<Texture> GetText(App *a, const char* text);
  shared_ptr<Texture> GetText(App *a, const char* text, int &iTime);
  bool GetRGB(){return rgb;}
  void SetDivisor(int d) { divisor = d; }

  ~Font();
};

#endif
