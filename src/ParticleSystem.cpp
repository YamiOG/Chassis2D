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

void ParticleSystem::SetParticle(float x, float y, float w, float h, int lifetime, int scale){
  position = Vec2(x, y);
  size = Vec2(w, h);
  this->lifetime = lifetime;
}

void ParticleSystem::SetParticle(float x, float y, float w, float h, float friction, float density, float restitution, int lifetime, int scale){
  position = Vec2(x, y);
  size = Vec2(w, h);
  this->friction = friction;
  this->density = density;
  this->restitution = restitution;
  this->lifetime = lifetime;
}

void ParticleSystem::SetParticle(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime, int scale){
  position = Vec2(x, y);
  size = Vec2(w, h);
  this->friction = friction;
  this->density = density;
  this->restitution = restitution;
  this->categoryBits = categoryBits;
  this->maskBits = maskBits;
  this->lifetime = lifetime;
}

void ParticleSystem::Update(){
  for(int i = 0; i < rate; i++){
    if(particles.size() < maximum){
      Particle *p = new Particle(position.x, position.y, size.x, size.y, friction, density, restitution, categoryBits, maskBits, lifetime);

      int diff = 180 - abs(abs(minAngle - maxAngle) - 180); 
      double angle = minAngle + (rand() % diff);

      if(angle > 360.f) angle -= 360.f;
      angle -= 180;
      angle *= (3.14 / 180);
        
      Vec2 velocity(0.0f, speed);

      velocity.x = velocity.x * cos(angle) - velocity.y * sin(angle);
      velocity.y = velocity.y * cos(angle) + velocity.x * sin(angle);

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

ParticleSystem::~ParticleSystem(){
}
