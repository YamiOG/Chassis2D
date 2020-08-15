#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <memory>
#include <SDL2/SDL.h>

#include "Class.h"

#include "Vec4.h"

using namespace std;

class Button{
 private:
  shared_ptr<Text> text;
  shared_ptr<Texture> texture;
  Vec4 rect;
  bool prev = false;
  
  bool hide = false;
 public:
  Button(){}
  Button(int x, int y, int w, int h, Texture *t, const char* text, Font *f);
  int Setup(int x, int y, int w, int h, Texture *t, const char* text, Font *f);
  void SetPrev(bool set) { prev = set; }
  bool GetPrev() { return prev; }
  Vec4 GetRect() {return rect;}

  shared_ptr<Texture> GetTexture() {return texture;}
  shared_ptr<Text> GetText() {return text;}

  void Hide() { hide = true; }
  void Show() { hide = false; }
  void SetHide(bool hide) { this->hide = hide; }
  bool IsHidden() { return hide; }
};

#endif
