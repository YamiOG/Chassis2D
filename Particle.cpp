#include "Particle.h"

#include "Chassis2D.h"

Particle::Particle(App* a, int width, int height, int lifetime, Texture *texture){
  this->width = width;
  this->height = height;
  this->lifetime = lifetime;
  this->texture = texture;
}

void Particle::Setup(App *a, int width, int height, int lifetime, Texture *texture){
  this->lifetime = lifetime;
  this->width = width;
  this->height = height;

  this->texture = texture;
}



Particle::~Particle(){
  delete texture;
}
