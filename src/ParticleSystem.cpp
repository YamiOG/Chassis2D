#include "ParticleSystem.h"

#include "Chassis2D.h"

#include <SDL.h>
#include <box2d/box2d.h>

ParticleSystem::ParticleSystem(int minAngle, int maxAngle, int rate, int maximum, float speed){
  Setup(minAngle, maxAngle, rate, maximum, speed);
}

void ParticleSystem::Setup(int minAngle, int maxAngle, int rate, int maximum, float speed){
  this->minAngle = minAngle;
  this->maxAngle = maxAngle;
  this->rate = rate;
  this->maximum = maximum;
  this->speed = speed;
}

void ParticleSystem::SetParticle(float x, float y, float w, float h, int lifetime){
  this->rect = Vec4(x, y, w, h); 
  this->lifetime = lifetime;
}

void ParticleSystem::SetParticle(float x, float y, float w, float h, float friction, float density, float restitution, int lifetime){
  this->rect = Vec4(x, y, w, h);
  this->friction = friction;
  this->density = density;
  this->restitution = restitution;
  this->lifetime = lifetime;
}

void ParticleSystem::SetParticle(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime){
  this->rect = Vec4(x, y, w, h);
  this->friction = friction;
  this->density = density;
  this->restitution = restitution;
  this->categoryBits = categoryBits;
  this->maskBits = maskBits;
  this->lifetime = lifetime;
}

void ParticleSystem::SetParticle(Vec4 rect, int lifetime){
  this->rect = rect;
  this->lifetime = lifetime;
}

void ParticleSystem::SetParticle(Vec4 rect, float friction, float density, float restitution, int lifetime){
  this->rect = rect;
  this->friction = friction;
  this->density = density;
  this->restitution = restitution;
  this->lifetime = lifetime;
}

void ParticleSystem::SetParticle(Vec4 rect, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime){
  this->rect = rect;
  this->friction = friction;
  this->density = density;
  this->restitution = restitution;
  this->categoryBits = categoryBits;
  this->maskBits = maskBits;
  this->lifetime = lifetime;
}

void ParticleSystem::Update(){
  for(int i = 0; i < rate; i++){
    if(particles.size() < maximum){ //particles.size() returns 0
      Particle *p = new Particle(rect, friction, density, restitution, categoryBits, maskBits, lifetime);
      p->SetTexture(texture.get(), offset, size);

      int diff = 180 - abs(abs(minAngle - maxAngle) - 180); 
      double angle = minAngle + (rand() % diff);

      Vec2 velocity = Vec2(cos(angle * M_PI / 180), -sin(angle * M_PI / 180));
      velocity = velocity * speed;

      p->SetVelocity(velocity);
      p->SetTime(SDL_GetTicks() + p->GetLifetime());

      shared_ptr<Particle> sharedParticle(p);
      particles.push_back(sharedParticle);
    }
  }

  for(int i = 0; i < particles.size();){
   if(SDL_GetTicks() >= particles[i]->GetTime()){
      particles.erase(particles.begin()+i);
    }
    else{
      i++;
    }
  }
}

void ParticleSystem::SetTexture(Texture* t){
  shared_ptr<Texture> sharedTexture(t); 
  texture = sharedTexture;

  offset = Vec2(0,0);
  size = Vec2(rect.w, rect.h);
}

void ParticleSystem::SetTexture(Texture* t, int width, int height){
  shared_ptr<Texture> sharedTexture(t); 
  texture = sharedTexture;

  offset = Vec2(0,0);
  size = Vec2(width, height);
}

void ParticleSystem::SetTexture(Texture* t, int xOffset, int yOffset, int width, int height) { 
  shared_ptr<Texture> sharedTexture(t); 
  texture = sharedTexture;

  offset = Vec2(xOffset, yOffset);
  size = Vec2(width, height);
}

void ParticleSystem::SetTexture(Texture* t, Vec2 offset, int width, int height) { 
  shared_ptr<Texture> sharedTexture(t); 
  texture = sharedTexture;

  this->offset = offset;
  size = Vec2(width, height);
}

void ParticleSystem::SetTexture(Texture* t, int xOffset, int yOffset, Vec2 size) { 
  shared_ptr<Texture> sharedTexture(t); 
  texture = sharedTexture;

  offset = Vec2(xOffset, yOffset);
  this->size = size;
}

void ParticleSystem::SetTexture(Texture* t, Vec2 offset, Vec2 size) { 
  shared_ptr<Texture> sharedTexture(t); 
  texture = sharedTexture;

  this->offset = offset;
  this->size = size;
}

ParticleSystem::~ParticleSystem(){
}
