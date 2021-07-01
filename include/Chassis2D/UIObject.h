#ifndef UIOBJECT_H
#define UIOBJECT_H

#include <iostream>

#include "Global.h"
#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class UIObject{
 protected:
  shared_ptr<Texture> texture;

  Vec2 origin = Vec2(0, 0);
  Vec4 rect = Vec4(0, 0, 0, 0);

  bool hide = false;
  bool center = false;
 public:
  UIObject(){}

  UIObject(int x, int y, int w, int h);
  void Setup(int x, int y, int w, int h); 

  Vec4 GetRect() { return rect; }
  void SetRect(Vec4 rect) { this->rect = rect; }

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