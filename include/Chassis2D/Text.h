#ifndef TEXT_H
#define TEXT_H

#include <iostream>
#include <memory>

#include "Global.h"
#include "Class.h"

#include "UIObject.h"
#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class Text : public UIObject{
 private:
  Font *font;
  string text, pText;

  int iTime = -1;
 public:
  Text(){}
  Text(float x, float y, string text, Font *font);
  int Setup(float x, float y, string text, Font *font);

  void SetText(string text) { this->text = text; }

  shared_ptr<Texture> GetTexture();

  void SetInitialTime(int set) { iTime = set; }
};

#endif
