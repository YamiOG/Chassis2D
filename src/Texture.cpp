#include "Texture.h"

#include "Chassis2D.h"

#include <SDL.h>

#include "stb_image.h"

Texture::Texture(const char* location){
  Setup(location);
}

Texture::Texture(string location){
  Setup(location);
}

Texture::Texture(SDL_Texture *texture){
  if(texture){
    this->texture = texture;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  }
  else{
    cout << "ERROR:Texture is NULL" << endl;
  }
}

Texture::Texture(SDL_Surface *surface){
  Setup(surface);
}

int Texture::Setup(const char* location){
  int req_format = STBI_rgb_alpha;
  int width, height, orig_format;
  unsigned char* data = stbi_load(location, &width, &height, &orig_format, req_format);
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
    texture = SDL_CreateTextureFromSurface(c2Renderer, surface);
  }
  else{
    cout << "ERROR:Failed to load file" << endl;
    return -1;
  }
  SDL_FreeSurface(surface);
  return 0;
}

int Texture::Setup(string location){
  int req_format = STBI_rgb_alpha;
  int width, height, orig_format;
  unsigned char* data = stbi_load(location.c_str(), &width, &height, &orig_format, req_format);
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
    texture = SDL_CreateTextureFromSurface(c2Renderer, surface);
  }
  else{
    cout << "ERROR:Failed to load file" << endl;
    return -1;
  }
  SDL_FreeSurface(surface);
  return 0;
}

int Texture::Setup(SDL_Texture *texture){
  if(texture){
    this->texture = texture;
    SDL_QueryTexture(texture, NULL, NULL, &width, &height);
  }
  else{
    cout << "ERROR:Texture is NULL" << endl;
    return -1;
  }
  return 0;
}

int Texture::Setup(SDL_Surface *surface){
  if(surface){
    width = surface->w;
    height = surface->h;
    texture = SDL_CreateTextureFromSurface(c2Renderer, surface);
  }
  else{
    cout << "ERROR:Surface is NULL" << endl;
    return -1;
  }
  return 0;
}

Vec4 Texture::GetCrop(){
  Vec4 rect = Vec4(0.0f, 0.0f, (float)width, (float)height);
  return rect;
}

Texture::~Texture(){
  SDL_DestroyTexture(texture);
}
