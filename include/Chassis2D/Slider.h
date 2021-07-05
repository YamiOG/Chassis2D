#ifndef SLIDER_H
#define SLIDER_H

#include <iostream>
#include <memory>

#include "Global.h"
#include "Class.h"

#include "UIObject.h"
#include "Color.h"
#include "Vec2.h"
#include "Vec4.h"

using namespace std; 

class Slider : public UIObject{
 private:
  Vec2 size;

  float percent; 
  Color thumbColor, activeColor, baseColor, hoverColor;
 public:
  Slider(){}
  Slider(float x, float y, float w, float h);
  void Setup(float x, float y, float w, float h);
  Slider(float x, float y, float w, float h, float percent);
  void Setup(float x, float y, float w, float h, float percent);

  void SetThumbRect(float w, float h) { size = Vec2(w, h); }
  void SetThumbRect(Vec2 size) { this->size = size; }

  void SetPercent(float percent) { this->percent = percent; } 

  void SetBaseColor(Color color) { this->baseColor = color; }
  void SetActiveColor(Color color) { this->activeColor = color; }
  void SetThumbColor(Color color) { this->thumbColor = color; }
  void SetHoverColor(Color color) { this->hoverColor = color; }

  //shared_ptr<Texture> GetTexture();

};

#endif