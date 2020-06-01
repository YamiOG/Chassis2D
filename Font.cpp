#include "Font.h"

#include "Chassis2D.h"

Font::Font(const char* fLoc, int s, int r, int g, int b, bool setRGB){
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

int Font::Setup(const char* fLoc, int s, int r, int g, int b, bool setRGB){
  font = TTF_OpenFont(fLoc, s);
  if(!font){
    cout << "ERROR:Font Loading Failed" << endl;
    return -1;
  }
  size = s;
  color.r = r;
  color.g = g;
  color.b = b;
  color.a = 255;
  rgb = setRGB; 
  return 0;
}


Font::~Font(){

}

shared_ptr<Texture> Font::GetText(App *a, const char* text){
  SDL_Surface *s = TTF_RenderText_Solid( font, text, color );
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

  SDL_Color rgbC;

  rgbC.a = 255;

  switch(n / 256)
  {
    case 0: rgbC.r = 255;      rgbC.g = c;        rgbC.b = 0;       break;//red
    case 1: rgbC.r = 255 - c;  rgbC.g = 255;      rgbC.b = 0;       break;//yellow
    case 2: rgbC.r = 0;        rgbC.g = 255;      rgbC.b = c;       break;//green
    case 3: rgbC.r = 0;        rgbC.g = 255 - c;  rgbC.b = 255;     break;//cyan
    case 4: rgbC.r = c;        rgbC.g = 0;        rgbC.b = 255;     break;//blue
    case 5: rgbC.r = 255;      rgbC.g = 0;        rgbC.b = 255 - c; break;//magenta
  }

  SDL_Surface *s = TTF_RenderText_Solid( font, text, rgbC );
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