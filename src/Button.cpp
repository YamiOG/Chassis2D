#include "Button.h"

#include "Chassis2D.h"

Button::Button(int x, int y, int w, int h, Texture *t, const char* text, Font *font){
  Setup(x, y, w, h, t, text, font);
}

int Button::Setup(int x, int y, int w, int h, Texture *t, const char* text, Font *font){
  rect.x = (float)x;
  rect.y = (float)y;
  rect.w = (float)w;
  rect.h = (float)h;

  shared_ptr<Texture> sharedTex(t);
  texture = sharedTex;

  this->text = make_shared<Text>(rect.x + rect.w/2, rect.y + rect.h/2, text, font);
  if(!text){
    cout << "ERROR:Text Creation Failed" << endl;
    return -1;
  }
  return 0;
}

Vec2 Button::GetOrigin(){
  if(center){
    origin = Vec2(rect.w/2, rect.h/2);
  }
  return origin;
}

bool Button::IsPressed(int mouseButton){
  if(rect.x < mousePosition.x && mousePosition.x < rect.x + rect.w && rect.y < mousePosition.y && mousePosition.y < rect.y + rect.h){
    if(mouseClick[mouseButton] == 1){
      if(!previous){
        previous = true;
        return true;
      }
    }
    else{
      if(previous){
        previous = false;
      }
      return false;
    }
  }
  return false;
}