#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class Text{
 private:
  shared_ptr<Texture> texture;
  Vec2 pos;
  Vec4 rect;
  Font *f;
  string text;
  int iTime = -1;

 public:
  Text(){}
  Text(int x, int y, const char* tx, Font *font);
  int Setup(int x, int y, const char* tx, Font *font);
  shared_ptr<Texture> GetText(App *a);
  void SetPosition(int x, int y) { pos.x = x; pos.y = y; }
  Vec2 GetPosition() {return pos;}
  Vec4 GetRect() { return rect; }

  ~Text();
};

#endif
