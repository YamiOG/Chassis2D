#include "Text.h"

#include "Chassis2D.h"

Text::Text(int x, int y, const char* tx, Font *font){
  f = font;
  pos.x = x;
  pos.y = y;

  rect.x = 0;
  rect.y = 0;
  rect.w = 0;
  rect.h = 0;

  text = (string)tx;

}

int Text::Setup(int x, int y, const char* tx, Font *font){
  f = font;
  pos.x = x;
  pos.y = y;

  rect.x = 0;
  rect.y = 0;
  rect.w = 0;
  rect.h = 0;

  text = (string)tx;

  return 0;
}

Text::~Text(){
  f->~Font();
}

shared_ptr<Texture> Text::GetText(App *a){
  if(f->GetRGB()){
    texture = f->GetText(a, text.c_str(), iTime);
  }
  else{
    texture = f->GetText(a, text.c_str());
  }

  if(!texture){
    cout << "ERROR:Text Texture is NULL" << endl;
  }

  Vec2 size = texture->GetSize();
  rect = Vec4(pos.x-(size.x/2), pos.y-(size.y/2), size.x, size.y);

  return texture;
}