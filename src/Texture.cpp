#include "Texture.h"

#include "Chassis2D.h"

#include <SDL.h>

#include "stb_image.h"

Texture::Texture(App *a, const char* loc){
  Setup(a, loc);
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

Texture::Texture(App *a, SDL_Surface *surface){
  Setup(a, surface);
}

int Texture::Setup(App *a, const char* loc){
  int req_format = STBI_rgb_alpha;
  int width, height, orig_format;
  unsigned char* data = stbi_load(loc, &width, &height, &orig_format, req_format);
  if (data == NULL) {
      cout << "ERROR:stb_image Failed to load file" << endl;
      return -1;
  }

  int depth = 32;
  int pitch = 4*width;

  SDL_Surface *surface = SDL_CreateRGBSurfaceWithFormatFrom((void*)data, width, height, depth, pitch, SDL_PIXELFORMAT_RGBA32);

  if(surface){
    width = surface->w;
    height = surface->h;
    texture = SDL_CreateTextureFromSurface(a->GetRenderer(), surface);
  }
  else{
    cout << "ERROR:Failed to load file" << endl;
    return -1;
  }
  SDL_FreeSurface(surface);
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

int Texture::Setup(App *a, SDL_Surface *surface){
  if(surface){
    width = surface->w;
    height = surface->h;
    texture = SDL_CreateTextureFromSurface(a->GetRenderer(), surface);
  }
  else{
    cout << "ERROR:Surface is NULL" << endl;
    return -1;
  }
  return 0;
}

Vec4 Texture::GetCrop(){
  Vec4 rect = Vec4(0,0,width,height);
  return rect;
}

Texture::~Texture(){
  SDL_DestroyTexture(texture);
}
