#include "ParticleSystem.h"

#include "Chassis2D.h"

ParticleSystem::ParticleSystem(Particle* p, SDL_Point velocity, int delay, int amount, float variation){
  bParticle = p;

  this->velocity = velocity;
  this->delay = delay;
  this->amount = amount;
  this->variation = variation;
}

void ParticleSystem::Setup(Particle* p, SDL_Point velocity, int delay, int amount, float variation){
  bParticle = p;

  this->velocity = velocity;
  this->delay = delay;
  this->amount = amount;
  this->variation = variation;
}

/*int ParticleSystem::SpawnParticle(App *a, int x, int y){
  if(a){
    Particle *tmp = bParticle;

    int fX = x+((rand() % variation)-(variation/2));
    int fY = y+((rand() % variation)-(variation/2));

    int dX = velocity.y+((rand() % variation)-(variation/2));
    int dY = velocity.y+((rand() % variation)-(variation/2));

    tmp->Create(fX, fY, b2Vec2(dX, dY));

    a->Add(tmp);

    particles->push_back(tmp);

  }
  else{
    cout << "ERROR:App is Null" << endl;
    return -1;
  }
  return 0;
  }*/

ParticleSystem::~ParticleSystem(){
}
