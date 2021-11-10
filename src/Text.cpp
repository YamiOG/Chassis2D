#include "Text.h"

#include "Chassis2D.h"

Text::Text(float x, float y, string text, Font *font){
  Setup(x, y, text, font);
}

int Text::Setup(float x, float y, string text, Font *font){
  this->font = font;
  this->text = text;

  rect.x = x;
  rect.y = y;
  return 0;
}

shared_ptr<Texture> Text::GetTexture(){
  if(!text.empty()){
    if(pText != text || &color != &font->GetColor()){
      texture = font->GetText(text.c_str());
      pText = text;
      color = font->GetColor();
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