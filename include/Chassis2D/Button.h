#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <memory>

#include "Global.h"
#include "Class.h"

#include "UIObject.h"
#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class Button : public UIObject{
 private:
  shared_ptr<Text> text;
  shared_ptr<Texture> texture;
  
  bool previous = false;
 public:
  Button(){}
  Button(int x, int y, int w, int h, Texture *t, const char* text, Font *font);
  int Setup(int x, int y, int w, int h, Texture *t, const char* text, Font *font);
  void SetPrevious(bool set) { previous = set; }
  bool GetPrevious() { return previous; }

  shared_ptr<Texture> GetTexture() {return texture;}
  shared_ptr<Text> GetText() {return text;}

  bool IsPressed(int mouseButton);
};

#endif