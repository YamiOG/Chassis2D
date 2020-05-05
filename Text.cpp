#include "Text.h"

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

SDL_Texture *Text::GetText(App *a){
  SDL_Texture *t;
  if(f->GetRGB()){
    f->GetText(a->GetRenderer(), pos.x, pos.y, text.c_str(), iTime, &t, &rect);
  }
  else{
    f->GetText(a->GetRenderer(), pos.x, pos.y, text.c_str(), &t, &rect);
  }

  if(!t){
    cout << "ERROR:Texture is Null" << endl;
  }
  return t;
}
