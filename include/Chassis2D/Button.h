#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <memory>

#include "Global.h"
#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class Button{
 private:
  shared_ptr<Text> text;
  shared_ptr<Texture> texture;
  Vec2 origin = Vec2(0, 0);
  Vec4 rect = Vec4(0, 0, 0, 0);
  bool previous = false;
  
  bool hide = false;
  bool center = false;
 public:
  Button(){}
  Button(int x, int y, int w, int h, Texture *t, const char* text, Font *font);
  int Setup(int x, int y, int w, int h, Texture *t, const char* text, Font *font);
  void SetPrevious(bool set) { previous = set; }
  bool GetPrevious() { return previous; }
  Vec4 GetRect() { return rect; }
  void SetRect(Vec4 rect) { this->rect = rect; }

  shared_ptr<Texture> GetTexture() {return texture;}
  shared_ptr<Text> GetText() {return text;}

  void SetOrigin(Vec2 origin) { this->origin = origin; }
  Vec2 GetOrigin();
  void SetOriginCenter(bool center) { this->center = center; }
  bool IsOriginCenter(bool center) { return center; }

  void Hide() { hide = true; }
  void Show() { hide = false; }
  void SetHide(bool hide) { this->hide = hide; }
  bool IsHidden() { return hide; }
};

#endif