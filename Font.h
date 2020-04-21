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
  bool chroma;
  int size;
 public:
  Font(){}
  Font(const char* fLoc, int r, int g, int b, int s, bool ch);
  int Setup(const char* fLoc, int r, int g, int b, int s, bool ch);
  int GetText(SDL_Renderer *renderer, int x, int y, const char* text, SDL_Texture **t, SDL_Rect *r );
  int GetText(SDL_Renderer *renderer, int x, int y, const char* text, int &iTime, SDL_Texture **t, SDL_Rect *r );
  bool GetChroma(){return chroma;}
};

#endif
