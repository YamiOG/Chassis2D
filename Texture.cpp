#include "Texture.h"

#include "App.h"

Texture::Texture(App *a, const char* loc, int hN, int vN, bool isS){
  if(isS){
    sheet = true;
    vNum = vN;
    hNum = hN;
    wFrame = width/vNum;
    hFrame = height/hNum;
  }
  SDL_Surface *surf = IMG_Load(loc);
  if(surf){
    width = surf->w;
    height = surf->h;
    texture = SDL_CreateTextureFromSurface(a->GetRenderer(), surf);
  }
  else{
    cout << "ERROR:Failed to load file" << endl;
  }
  SDL_FreeSurface(surf);
}

int Texture::Setup(App *a, const char* loc, int hN, int vN, bool isS){
  if(isS){
    sheet = true;
    vNum = vN;
    hNum = hN;
    wFrame = width/vNum;
    hFrame = height/hNum;
  }
  SDL_Surface *surf = IMG_Load(loc);
  if(surf){
    width = surf->w;
    height = surf->h;
    texture = SDL_CreateTextureFromSurface(a->GetRenderer(), surf);
  }
  else{
    cout << "ERROR:Failed to load file" << endl;
    return -1;
  }

  SDL_FreeSurface(surf);
  return 0;
}

SDL_Rect Texture::GetCrop(){
  SDL_Rect rect = {0,0,width,height}; 
  return rect;
}

SDL_Rect Texture::GetFrame(int num){
  if(!sheet){
    cout << "WARNING:Not A Sprite Sheet" << endl;
    SDL_Rect rect = {0,0,width,height}; 
    return rect;
  }
  int y = 0;
  if(num > hNum){
    y = hFrame * ((int)(num/hNum));
  }
  int x = num % hNum;

  SDL_Rect rect = {x, y, wFrame, hFrame};
  return rect;
}
