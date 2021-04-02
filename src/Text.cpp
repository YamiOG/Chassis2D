#include "Text.h"

#include "Chassis2D.h"

Text::Text(int x, int y, string text, Font *font){
  Setup(x, y, text, font);
}

int Text::Setup(int x, int y, string text, Font *font){
  this->font = font;
  this->text = text;

  pos = Vec2((float)x, (float)y);

  return 0;
}

shared_ptr<Texture> Text::GetText(App *a){
  if(!text.empty()){
    if(font->GetRGB()){
      texture = font->GetText(a, text.c_str(), iTime);
    }
    else{
      texture = font->GetText(a, text.c_str());
    }

    if(!texture){
      cout << "ERROR:Text Texture is NULL" << endl;
      return nullptr;
    }

    Vec2 size = texture->GetSize();
    rect = Vec4(pos.x-(size.x/2), pos.y-(size.y/2), size.x, size.y);

    return texture;
  }
  return nullptr;
}