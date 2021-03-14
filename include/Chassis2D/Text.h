#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <memory>

#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class Text{
 private:
  shared_ptr<Texture> texture;
  Vec2 pos;
  Vec4 rect;
  string text;

  Font *font;

  int iTime = -1;

  bool hide = false;
 public:
  Text(){}
  Text(int x, int y, const char* text, Font *font);
  int Setup(int x, int y, const char* text, Font *font);
  shared_ptr<Texture> GetText(App *a);
  void SetPosition(int x, int y) { pos.x = x; pos.y = y; }
  Vec2 GetPosition() {return pos;}
  Vec4 GetRect() { return rect; }

  void Hide() { hide = true; }
  void Show() { hide = false; }
  void SetHide(bool hide) { this->hide = hide; }
  bool IsHidden() { return hide; }

  ~Text();
};

#endif
