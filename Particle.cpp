#include "Particle.h"

#include "Chassis2D.h"

Particle::Particle(float width, float height, float friction, float density, float restitution, int lifetime, Texture *texture, int scale){
  this->width = width;
  this->height = height;
  this->lifetime = lifetime;
  this->texture = texture;

  this->scale = scale;

}

void Particle::Setup(float width, float height, float friction, float density, float restitution, int lifetime, Texture *texture, int scale){
  this->width = width;
  this->height = height;
  this->lifetime = lifetime;
  this->texture = texture;

  this->scale = scale;

  this->friction = friction;
  this->density = density;
  this->restitution = restitution;
}

int Particle::Create(int x, int y){
  bodyDef.position.Set((x + (width/2))/scale, (y + (height/2))/scale);
  shape.SetAsBox((width/2)/scale, (height/2)/scale);
  fixture.shape = &shape;

  fixture.filter.categoryBits = PARTICLE;
  fixture.filter.maskBits = PARTICLE;

  bodyDef.type = b2_dynamicBody;
  fixture.friction = friction;
  fixture.density = density;
  fixture.restitution = restitution;
  return 0;
}

SDL_Rect Particle::GetScaledPosition() {
  SDL_Rect rect = {0,0,0,0};
  if(body){
    rect = { (int)((body->GetPosition().x * scale) - (width / 2)), (int)((body->GetPosition().y * scale) - (height / 2)), (int)width, (int)height };
  }
  else{
    cout << "ERROR:Particle Body is NULL" << endl;
  }
  return rect;
}

Particle::~Particle(){
  delete texture;
}
