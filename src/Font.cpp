#include "Font.h"

#include "Chassis2D.h"

#include <SDL.h>
#include <SDL_ttf.h>

Font::Font(const char* loc, int size, Color color){
  Setup(loc, size, color);
}

int Font::Setup(const char* loc, int size, Color color){
  font = TTF_OpenFont(loc, size);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
    return -1;
  }
  this->size = size;
  this->color = color;
  rgb = false; 
}

Font::Font(const char* loc, int size, int r, int g, int b){
  Setup(loc, size, r, g, b);
}

int Font::Setup(const char* loc, int size, int r, int g, int b){
  font = TTF_OpenFont(loc, size);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
    return -1;
  }
  this->size = size;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255;
  rgb = false; 
  return 0;
}

Font::Font(const char* loc, int size, int r, int g, int b, int a){
  Setup(loc, size, r, g, b, a);
}

int Font::Setup(const char* loc, int size, int r, int g, int b, int a){
  font = TTF_OpenFont(loc, size);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
    return -1;
  }
  this->size = size;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  rgb = false; 
  return 0;
}

Font::Font(const char* loc, int size, int divisor){
  Setup(loc, size, divisor);
}

int Font::Setup(const char* loc, int size, int divisor){
  font = TTF_OpenFont(loc, size);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
    return -1;
  }
  this->size = size;
  this->divisor = divisor;

  rgb = true; 
  return 0;
}

Font::~Font(){
  if(font){
    TTF_CloseFont(font);
  }
}

shared_ptr<Texture> Font::GetText(App *a, const char* text){
  SDL_Color tmp = {color.r, color.g, color.b, color.a};
  SDL_Surface *s = TTF_RenderText_Solid(font, text, tmp);
  if(!s){
    cout << "ERROR:Text Surface is NULL" << endl;
  }

  shared_ptr<Texture> t = make_shared<Texture>(SDL_CreateTextureFromSurface(a->GetRenderer(), s));
  if(!t){
    cout << "ERROR:Text Texture is NULL" << endl;
  }

  if(s){
    SDL_FreeSurface(s);
  }
  
  return t;
}

shared_ptr<Texture> Font::GetText(App *a, const char* text, int &iTime){
  if(iTime == -1){
    iTime = SDL_GetTicks();
  }

  //RGB Color
  int interval = 256*divisor;

  float i = ((float)((SDL_GetTicks()-iTime)%interval))/interval;
  if(SDL_GetTicks()-iTime >= interval){
    iTime = SDL_GetTicks();
  }

  int n = i * 256 * 6;
  int c = n % 256;

  SDL_Color rgbColor;

  rgbColor.a = 255;

  switch(n / 256)
  {
    case 0: rgbColor.r = 255;      rgbColor.g = c;        rgbColor.b = 0;       break;//red
    case 1: rgbColor.r = 255 - c;  rgbColor.g = 255;      rgbColor.b = 0;       break;//yellow
    case 2: rgbColor.r = 0;        rgbColor.g = 255;      rgbColor.b = c;       break;//green
    case 3: rgbColor.r = 0;        rgbColor.g = 255 - c;  rgbColor.b = 255;     break;//cyan
    case 4: rgbColor.r = c;        rgbColor.g = 0;        rgbColor.b = 255;     break;//blue
    case 5: rgbColor.r = 255;      rgbColor.g = 0;        rgbColor.b = 255 - c; break;//magenta
  }

  SDL_Surface *s = TTF_RenderText_Solid(font, text, rgbColor);
  if(!s){
    cout << "ERROR:Text Surface is NULL" << endl;
  }

  shared_ptr<Texture> t = make_shared<Texture>(SDL_CreateTextureFromSurface(a->GetRenderer(), s));
  if(!t){
    cout << "ERROR:Text Texture is NULL" << endl;
  }

  if(s){
    SDL_FreeSurface(s);
  }

  return t;
}