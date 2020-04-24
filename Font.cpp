#include "Font.h"


Font::Font(const char* fLoc, int r, int g, int b, int s, bool setRGB){
  font = TTF_OpenFont(fLoc, s);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
  }
  size = s;
  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255;
  rgb = setRGB;
}

int Font::Setup(const char* fLoc, int r, int g, int b, int s, bool setRGB){
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
  rgb = setRGB; 
  return 0;
}

int Font::GetText(SDL_Renderer *renderer, int x, int y, const char* text, SDL_Texture **t, SDL_Rect *r ){
  SDL_Surface *s;

  s = TTF_RenderText_Solid( font, text, color );
  if(!s){
    cout << "ERROR:Text Surface is NULL" << endl;
    return 1;
  }

  r->x = x - (s->w/2);
  r->y = y - (s->h/2);
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

int Font::GetText(SDL_Renderer *renderer, int x, int y, const char* text, int &iTime, SDL_Texture **t, SDL_Rect *r ){
  SDL_Surface *s;

  if(iTime == -1){
    iTime = SDL_GetTicks();
  }

  //RGB Color
  int divisor = 1;

  int interval = 256*divisor;

  float i = ((float)((SDL_GetTicks()-iTime)%interval))/interval;

  int n = i * 256 * 6;

  int c = n % 256;

  SDL_Color rgbC;

  switch(n / 256)
  {
    case 0: rgbC.r = 255;      rgbC.g = c;        rgbC.b = 0;       break;//red
    case 1: rgbC.r = 255 - c;  rgbC.g = 255;      rgbC.b = 0;       break;//yellow
    case 2: rgbC.r = 0;        rgbC.g = 255;      rgbC.b = c;       break;//green
    case 3: rgbC.r = 0;        rgbC.g = 255 - c;  rgbC.b = 255;     break;//cyan
    case 4: rgbC.r = c;        rgbC.g = 0;        rgbC.b = 255;     break;//blue
    case 5: rgbC.r = 255;      rgbC.g = 0;        rgbC.b = 255 - c; break;//magenta
  }

  s = TTF_RenderText_Solid( font, text, rgbC );
  if(!s){
    cout << "ERROR:Text Surface is NULL" << endl;
    return 1;
  }

  r->x = x - (s->w/2);
  r->y = y - (s->h/2);
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
