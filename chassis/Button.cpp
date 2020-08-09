#include "Button.h"

#include "Chassis2D.h"

Button::Button(int x, int y, int w, int h, Texture *t, const char* text, Font *f){
  Setup(x, y, w, h, t, text, f);
}

int Button::Setup(int x, int y, int w, int h, Texture *t, const char* text, Font *f){
  rect.x = x;
  rect.y = y;
  rect.w = w;
  rect.h = h;

  shared_ptr<Texture> sharedTex(t);
  texture = sharedTex;

  this->text = make_shared<Text>(x+w/2, y+h/2, text, f);
  if(!text){
    cout << "ERROR:Text Creation Failed" << endl;
    return -1;
  }
  return 0;
}
