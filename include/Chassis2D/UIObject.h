#ifndef UIOBJECT_H
#define UIOBJECT_H

#include <iostream>
#include <memory>

#include "Global.h"
#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"
#include "Color.h"

using namespace std;

class UIObject{
 protected:
  shared_ptr<Texture> texture;
  Color color = Color(0, 0, 0);

  Vec2 origin = Vec2(0, 0);
  Vec4 rect;
  int radius = 0;

  bool hide = false;
  bool center = false;
 public:
  UIObject(){}

  UIObject(int x, int y, int w, int h);
  void Setup(int x, int y, int w, int h); 

  void SetTexture(Texture* texture);
  virtual shared_ptr<Texture> GetTexture();

  void SetColor(int r, int g, int b) { color.r = r; color.g = g; color.b = b; }
  void SetColor(int r, int g, int b, int a) { color.r = r; color.g = g; color.b = b; color.a = a; }
  Color GetColor() { return color; }

  Vec2 GetPosition() { return Vec2(rect.x, rect.y); }
  void SetPosition(float x, float y) { this->rect.x = x; this->rect.y = y; }
  void SetPosition(Vec2 position) { this->rect.x = position.x; this->rect.y = position.y; }

  Vec4 GetRect() { return rect; }
  void SetRect(Vec4 rect) { this->rect = rect; }

  void SetRadius(int radius) { this->radius = radius; }
  int GetRadius() { return radius; }

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