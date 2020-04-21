#include "Text.h"

Text::Text(int x, int y, Font font, const char* tx){
  f = font;
  pos.x = x;
  pos.y = y;
  text = (string)tx;
}

int Text::Setup(int x, int y, Font font, const char* tx){
  f = font;
  pos.x = x;
  pos.y = y;
  text = (string)tx;
  return 0;
}

SDL_Texture *Text::GetText(Chassis c){
  SDL_Texture *t;
  if(f.GetChroma()){
    f.GetText(c.GetRenderer(), pos.x, pos.y, text.c_str(), iTime, &t, &rect);
  }
  else{
    f.GetText(c.GetRenderer(), pos.x, pos.y, text.c_str(), &t, &rect);
  }

  if(!t){
    cout << "ERROR:Texture is Null" << endl;
  }
  return t;
}

void Text::Draw(Chassis c){
  SDL_RenderCopy(c.GetRenderer(), GetText(c), NULL, &rect);
}
