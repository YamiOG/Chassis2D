#include "ParticleSystem.h"

#include "Chassis2D.h"

ParticleSystem::ParticleSystem(Particle* p, SDL_Point velocity, int delay, int amount, float variation){
  this->velocity = velocity;
  this->delay = delay;
  this->amount = amount;
  this->variation = variation;
}

void ParticleSystem::Setup(Particle* p, SDL_Point velocity, int delay, int amount, float variation){
  this->velocity = velocity;
  this->delay = delay;
  this->amount = amount;
  this->variation = variation;
}

int ParticleSystem::SpawnParticle(int x, int y, App *a){
  if(a){
  }
  else{
    cout << "ERROR:App is Null" << endl;
    return -1;
  }
  return 0;
}

ParticleSystem::~ParticleSystem(){
}
