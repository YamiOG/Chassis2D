#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <memory>

#include "Global.h"
#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class Text{
 private:
  shared_ptr<Texture> texture;
  Font *font;
  string text;
  Vec2 position;
  Vec2 origin = Vec2(0, 0);
  Vec4 rect = Vec4(0, 0, 0, 0);

  int iTime = -1;
  bool hide = false;
  bool center = false;
 public:
  Text(){}
  Text(int x, int y, string text, Font *font);
  int Setup(int x, int y, string text, Font *font);
  shared_ptr<Texture> GetText();
  void SetPosition(float x, float y) { position.x = x; position.y = y; }
  Vec2 GetPosition() {return position;}
  Vec4 GetRect() { return rect; }
  void SetRect(Vec4 rect) { this->rect = rect; }
  void SetInitialTime(int set) { iTime = set; }

  void SetOrigin(Vec2 origin) { this->origin = origin; }
  Vec2 GetOrigin();
  void SetOriginCenter(bool center) { this->center = center; }
  bool IsOriginCenter(bool center) { return center; }

  void Hide() { hide = true; }
  void Show() { hide = false; }
  void SetHide(bool hide) { this->hide = hide; }
  bool IsHidden() { return hide; }

  ~Text(){}
};

#endif
