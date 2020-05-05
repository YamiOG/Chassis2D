#include "Button.h"

Button::Button(int x, int y, int w, int h, Texture *t, const char* tx, Font *f){
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  texture = t;

  text = new Text(x+w/2, y+h/2, tx, f);
}

int Button::Setup(int x, int y, int w, int h, Texture *t, const char* tx, Font *f){
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  texture = t;

  text = new Text(x+w/2, y+h/2, tx, f);
  if(!text){
    cout << "ERROR:Text Creation Failed" << endl;
    return -1;
  }
  return 0;
}

bool Button::IsPressed(App *a){
  if(a->IsMouseInRect(rect)){
    if(a->GetEvent().type == SDL_MOUSEBUTTONDOWN) {
      if(a->GetEvent().button.button == SDL_BUTTON_LEFT && prev == false){
        pressed = true;
        prev = true;
        return true;
      }
      else{
        pressed = false;
        prev = false;
        return false;
      }
    }
  }
  return false;
}
