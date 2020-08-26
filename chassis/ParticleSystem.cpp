#include "ParticleSystem.h"

#include "Chassis2D.h"

ParticleSystem::ParticleSystem(Particle* particle, int minAngle, int maxAngle, int rate, int max, float speed){
  Setup(particle, minAngle, maxAngle, rate, max, speed);
}

void ParticleSystem::Setup(Particle* particle, int minAngle, int maxAngle, int rate, int max, float speed){
  shared_ptr<Particle> sharedParticle(particle);
  bParticle = sharedParticle;//make_shared<Particle>(*particle);

  this->minAngle = minAngle;
  this->maxAngle = maxAngle;
  this->rate = rate;
  this->maximum = max;
  this->speed = speed;
}

void ParticleSystem::Update(App *a){
  for(int i = 0; i < rate; i++){
    if(particles.size() < maximum){
      Particle *p = new Particle(*bParticle);

      int diff = 180 - abs(abs(minAngle - maxAngle) - 180); 
      float angle = minAngle + (rand() % diff);

      if(angle > 360.f) angle -= 360.f;
      angle -= 180;
      angle *= (3.14 / 180);
        
      Vec2 velocity(0, speed);

      velocity.x = velocity.x * cos(angle) - velocity.y * sin(angle);
      velocity.y = velocity.y * cos(angle) + velocity.x * sin(angle);

      p->Create(a, pos.x, pos.y);

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
