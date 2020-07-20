#include "Text.h"

#include "Chassis2D.h"

Text::Text(int x, int y, const char* text, Font *font){
  this->font = font;

  pos = Vec2(x, y);
  rect = Vec4(0,0,0,0);

  this->text = (string)text;

}

int Text::Setup(int x, int y, const char* text, Font *font){
  this->font = font;

  pos = Vec2(x, y);
  rect = Vec4(0,0,0,0);

  this->text = (string)text;

  return 0;
}

Text::~Text(){
}

shared_ptr<Texture> Text::GetText(App *a){
  if(font->GetRGB()){
    texture = font->GetText(a, text.c_str(), iTime);
  }
  else{
    texture = font->GetText(a, text.c_str());
  }

  if(!texture){
    cout << "ERROR:Text Texture is NULL" << endl;
  }

  Vec2 size = texture->GetSize();
  rect = Vec4(pos.x-(size.x/2), pos.y-(size.y/2), size.x, size.y);

  return texture;
}