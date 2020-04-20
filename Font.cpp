#include "Font.h"


Font::Font(const char* fLoc, int r, int g, int b, int s, bool ch){
  font = TTF_OpenFont(fLoc, s);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
  }
  size = s;
  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255;
  chroma = ch;
}

int Font::Setup(const char* fLoc, int r, int g, int b, int s, bool ch){
  font = TTF_OpenFont(fLoc, s);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
    return 1;
  }
  size = s;
  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255;
  chroma = ch;
  return 0;
}

int Font::GetText(SDL_Renderer *renderer, int x, int y, const char* text, SDL_Texture **t, SDL_Rect *r ){
  SDL_Surface *s;

  s = TTF_RenderText_Solid( font, text, color );
  if(!s){
    cout << "ERROR:Text Surface is NULL" << endl;
    return 1;
  }

  int xPos = x - (s->w/2);
  cout << xPos << endl;
  r->x = x;
  r->y = y;
  r->w = s->w;
  r->h = s->h;

  *t = SDL_CreateTextureFromSurface(renderer, s);
  if(!t){
    cout << "ERROR:Text Texture is NULL" << endl;
    return 1;
  }

  SDL_FreeSurface(s);
  return 0;
}

int Font::GetText(SDL_Renderer *renderer, int x, int y, const char* text, int iTime, SDL_Texture **t, SDL_Rect *r ){
  SDL_Surface *s;

  s = TTF_RenderText_Solid( font, text, color );
  if(!s){
    cout << "ERROR:Text Surface is NULL" << endl;
    return 1;
  }

  int xPos = x - (s->w/2);
  cout << xPos << endl;
  r->x = x;
  r->y = y;
  r->w = s->w;
  r->h = s->h;

  *t = SDL_CreateTextureFromSurface(renderer, s);
  if(!t){
    cout << "ERROR:Text Texture is NULL" << endl;
    return 1;
  }

  SDL_FreeSurface(s);
  return 0; 
}
