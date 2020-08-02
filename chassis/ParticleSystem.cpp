#include "ParticleSystem.h"

#include "Chassis2D.h"

ParticleSystem::ParticleSystem(Particle* p, float minAngle, float maxAngle, int rate, int max){
  bParticle = p;

  this->minAngle = minAngle;
  this->maxAngle = maxAngle;
  this->rate = rate;
  this->maximum = max;
}

void ParticleSystem::Setup(Particle* p, float minAngle, float maxAngle, int rate, int max){
  bParticle = p;

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

      particles.push_back(p);
    }
  }

  for(int i = 0; i < particles.size(); i++){
    if(SDL_GetTicks() >= particles[i]->GetTime()){
      particles.erase(particles.begin()+i);
    }
  }
}

int ParticleSystem::AddParticle(Particle *particle){
  if(particle){
    particles.push_back(particle);
  }
  else{
    cout << "ERROR::Particle is NULL"<< endl;
    return -1;
  }
  return 0;
}

void ParticleSystem::CheckParticles(){
  for(int i = 0; i < particles.size(); i++){
    if(SDL_GetTicks() >= particles[i]->GetTime()){
      particles.erase(particles.begin()+i);
    }
  }
}

ParticleSystem::~ParticleSystem(){
  delete bParticle;
}
