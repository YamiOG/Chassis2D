#ifndef SLIDER_H
#define SLIDER_H

#include <iostream>

#include "Global.h"
#include "Class.h"

#include "UIObject.h"
#include "Vec2.h"
#include "Vec4.h"

using namespace std; 

class Slider : public UIObject{
 private:
  float percent = 0.0f; 
 public:
  void SetPercent(float percent) { this->percent = percent; } 
};

#endif