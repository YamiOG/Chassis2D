#ifndef FONT_H
#define FONT_H

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

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
  int GetText(SDL_Renderer *renderer, int x, int y, const char* text, SDL_Texture **t, SDL_Rect *r );
  int GetText(SDL_Renderer *renderer, int x, int y, const char* text, int &iTime, SDL_Texture **t, SDL_Rect *r );
  bool GetRGB(){return rgb;}
  void SetDivisor(int d) { divisor = d; }
};

#endif
