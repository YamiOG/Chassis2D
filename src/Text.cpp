#include "Text.h"

#include "Chassis2D.h"

Text::Text(int x, int y, string text, Font *font){
  Setup(x, y, text, font);
}

int Text::Setup(int x, int y, string text, Font *font){
  this->font = font;
  this->text = text;

  //position = Vec2((float)x, (float)y);
  rect.x = x;
  rect.y = y;
  return 0;
}

shared_ptr<Texture> Text::GetText(){
  if(!text.empty()){
    if(font->GetRGB()){
      texture = font->GetText(text.c_str(), iTime);
    }
    else{
      texture = font->GetText(text.c_str());
    }

    if(!texture){
      cout << "ERROR:Text Texture is NULL" << endl;
      return nullptr;
    }

    Vec2 size = texture->GetSize();
    rect = Vec4(rect.x, rect.y, size.x, size.y);

    return texture;
  }
  return nullptr;
}

Vec2 Text::GetOrigin(){
  if(center){
    origin = Vec2(rect.w/2, rect.h/2);
  }
  return origin;
}