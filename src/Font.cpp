#include "Font.h"

#include "Chassis2D.h"

#include <SDL.h>
#include <SDL_ttf.h>

Font::Font(const char* location, int size, Color color){
  Setup(location, size, color);
}

int Font::Setup(const char* location, int size, Color color){
  font = TTF_OpenFont(location, size);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
    return -1;
  }
  this->size = size;
  this->color = color;
  return 0;
}

Font::Font(const char* location, int size, int r, int g, int b){
  Setup(location, size, r, g, b);
}

int Font::Setup(const char* location, int size, int r, int g, int b){
  font = TTF_OpenFont(location, size);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
    return -1;
  }
  this->size = size;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255;
  return 0;
}

Font::Font(const char* location, int size, int r, int g, int b, int a){
  Setup(location, size, r, g, b, a);
}

int Font::Setup(const char* location, int size, int r, int g, int b, int a){
  font = TTF_OpenFont(location, size);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
    return -1;
  }
  this->size = size;

  color.r = r;
  color.g = g;
  color.b = b;
  color.a = a;
  return 0;
}

Font::~Font(){
  if(font){
    TTF_CloseFont(font);
  }
}

shared_ptr<Texture> Font::GetText(const char* text){
  SDL_Surface *surface = TTF_RenderText_Solid(font, text, color.ToSDL());
  if(!surface){
    cout << "ERROR:Text Surface is NULL" << endl;
  }

  shared_ptr<Texture> texture = make_shared<Texture>(surface);
  if(!texture){
    cout << "ERROR:Text Texture is NULL" << endl;
  }

  if(surface){
    SDL_FreeSurface(surface);
  }
  
  return texture;
}