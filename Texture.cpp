#include "Texture.h"

#include "App.h"

Texture::Texture(App *a, const char* loc){
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

Texture::Texture(SDL_Texture *t){
  if(t){
    texture = t;
    SDL_QueryTexture(t, NULL, NULL, &width, &height);
  }
  else{
    cout << "ERROR:Texture is NULL" << endl;
  }
}

Texture::Texture(SDL_Texture *t, int hN, int vN, bool isS){
  if(isS){
    sheet = true;
    vNum = vN;
    hNum = hN;
    wFrame = width/vNum;
    hFrame = height/hNum;
  }
  if(t){
    texture = t;
    SDL_QueryTexture(t, NULL, NULL, &width, &height);
  }
  else{
    cout << "ERROR:Texture is NULL" << endl;
  }
}

Texture::Texture(App *a, SDL_Surface *surf){
  if(surf){
    width = surf->w;
    height = surf->h;
    texture = SDL_CreateTextureFromSurface(a->GetRenderer(), surf);
  }
  else{
    cout << "ERROR:Surface is NULL" << endl;
  }
}

Texture::Texture(App *a, SDL_Surface *surf, int hN, int vN, bool isS){
  if(isS){
    sheet = true;
    vNum = vN;
    hNum = hN;
    wFrame = width/vNum;
    hFrame = height/hNum;
  }

  if(surf){
    width = surf->w;
    height = surf->h;
    texture = SDL_CreateTextureFromSurface(a->GetRenderer(), surf);
  }
  else{
    cout << "ERROR:Surface is NULL" << endl;
  }
}

int Texture::Setup(App *a, const char* loc){
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

int Texture::Setup(SDL_Texture *t){
  if(t){
    texture = t;
    SDL_QueryTexture(t, NULL, NULL, &width, &height);
  }
  else{
    cout << "ERROR:Texture is NULL" << endl;
    return -1;
  }
  return 0;
}

int Texture::Setup(SDL_Texture *t, int hN, int vN, bool isS){
  if(isS){
    sheet = true;
    vNum = vN;
    hNum = hN;
    wFrame = width/vNum;
    hFrame = height/hNum;
  }
  if(t){
    texture = t;
    SDL_QueryTexture(t, NULL, NULL, &width, &height);
  }
  else{
    cout << "ERROR:Texture is NULL" << endl;
    return -1;
  }
  return 0;
}

int Texture::Setup(App *a, SDL_Surface *surf){
  if(surf){
    width = surf->w;
    height = surf->h;
    texture = SDL_CreateTextureFromSurface(a->GetRenderer(), surf);
  }
  else{
    cout << "ERROR:Surface is NULL" << endl;
    return -1;
  }
  return 0;
}

int Texture::Setup(App *a, SDL_Surface *surf, int hN, int vN, bool isS){
  if(isS){
    sheet = true;
    vNum = vN;
    hNum = hN;
    wFrame = width/vNum;
    hFrame = height/hNum;
  }

  if(surf){
    width = surf->w;
    height = surf->h;
    texture = SDL_CreateTextureFromSurface(a->GetRenderer(), surf);
  }
  else{
    cout << "ERROR:Surface is NULL" << endl;
    return -1;
  }
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

Texture::~Texture(){
  SDL_DestroyTexture(texture);
}
