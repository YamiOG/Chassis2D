#include "ParticleSystem.h"

#include "Chassis2D.h"

ParticleSystem::ParticleSystem(Particle* particle, float minAngle, float maxAngle, int rate, int max){
  Setup(particle, minAngle, maxAngle, rate, max);
}

void ParticleSystem::Setup(Particle* particle, float minAngle, float maxAngle, int rate, int max){
  bParticle = make_shared<Particle>(*particle);

  this->minAngle = minAngle;
  this->maxAngle = maxAngle;
  this->rate = rate;
  this->maximum = max;
}

void ParticleSystem::Update(App *a){
  for(int i = 0; i < rate; i++){
    if(particles.size() < maximum){
      Particle *p = new Particle(*bParticle);

      float diff = abs(maxAngle-minAngle);
      if(diff > 180.f){
        diff -= 180.f;
      }

      float angle = minAngle + (((float)rand() / (float)RAND_MAX) * diff);
      if(angle > 360.f){
        angle -= 360.f;
      }

      Vec2 velocity = Vec2(cos(angle * (3.14 / 180)), sin(angle * (3.14/180)));

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
