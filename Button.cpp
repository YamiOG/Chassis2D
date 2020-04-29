#include "Button.h"

Button::Button(int x, int y, int w, int h, SDL_Texture *t, const char* tx, Font f){
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  texture = t;

  text.Setup(x, y, tx, f);
}

int Button::Setup(int x, int y, int w, int h, SDL_Texture *t, const char* tx, Font f){
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  texture = t;

  if(text.Setup(x, y, tx, f) == -1){
    cout << "ERROR:Text Creation Failed" << endl;
    return -1;
  }
  return 0;
}

bool Button::IsPressed(App a){
  (a.IsMouseInRect(rect)){
    if(event.type == SDL_MOUSEBUTTONDOWN) {
      
    }
           
  }
}

void Button::Draw(App a){
  
}


