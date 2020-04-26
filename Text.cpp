#include "Text.h"

Text::Text(int x, int y, const char* tx, Font font){
  f = font;
  pos.x = x;
  pos.y = y;
  text = (string)tx;
}

int Text::Setup(int x, int y, const char* tx, Font font){
  f = font;
  if(!font){
    cout << "ERROR:Font was Unable to Load" << endl;
    return -1;
  }
  pos.x = x;
  pos.y = y;
  text = (string)tx;
  return 0;
}

SDL_Texture *Text::GetText(App a){
  SDL_Texture *t;
  if(f.GetRGB()){
    f.GetText(a.GetRenderer(), pos.x, pos.y, text.c_str(), iTime, &t, &rect);
  }
  else{
    f.GetText(a.GetRenderer(), pos.x, pos.y, text.c_str(), &t, &rect);
  }

  if(!t){
    cout << "ERROR:Texture is Null" << endl;
  }
  return t;
}

void Text::Draw(App a){
  SDL_RenderCopy(a.GetRenderer(), GetText(a), NULL, &rect);
}
