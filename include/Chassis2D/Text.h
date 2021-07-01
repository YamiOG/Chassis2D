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
  shared_ptr<Texture> texture;
  Font *font;
  string text;

  int iTime = -1;
 public:
  Text(){}
  Text(float x, float y, string text, Font *font);
  int Setup(float x, float y, string text, Font *font);

  void SetInitialTime(int set) { iTime = set; }

  shared_ptr<Texture> GetText();
};

#endif
