#include "UIObject.h"

#include "Chassis2D.h"

UIObject::UIObject(int x, int y, int w, int h){
    Setup(x, y, w, h);
}

void UIObject::Setup(int x, int y, int w, int h){
    rect = Vec4(x, y, w, h);
}

Vec2 UIObject::GetOrigin(){
  if(center){
    origin = Vec2(rect.w/2, rect.h/2);
  }
  return origin;
}