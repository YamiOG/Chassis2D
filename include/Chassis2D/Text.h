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
  Font *font;
  string text;
  Vec2 pos;
  Vec4 rect = Vec4(0,0,0,0);

  int iTime = -1;
  bool hide = false;
 public:
  Text(){}
  Text(int x, int y, string text, Font *font);
  int Setup(int x, int y, string text, Font *font);
  shared_ptr<Texture> GetText(App *a);
  void SetPosition(float x, float y) { pos.x = x; pos.y = y; }
  Vec2 GetPosition() {return pos;}
  Vec4 GetRect() { return rect; }
  void SetInitialTime(int set) { iTime = set; }

  void Hide() { hide = true; }
  void Show() { hide = false; }
  void SetHide(bool hide) { this->hide = hide; }
  bool IsHidden() { return hide; }

  ~Text();
};

#endif
