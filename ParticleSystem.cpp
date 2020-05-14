#include "ParticleSystem.h"

#include "Chassis2D.h"

ParticleSystem::ParticleSystem(Particle* p, Vec2 velocity, int delay, int amount, int variation){
  bParticle = p;

  this->velocity = velocity;
  this->delay = delay;
  this->amount = amount;
  this->variation = variation;
}

void ParticleSystem::Setup(Particle* p, Vec2 velocity, int delay, int amount, int variation){
  bParticle = p;

  this->velocity = velocity;
  this->delay = delay;
  this->amount = amount;
  this->variation = variation;
}

Vec2 ParticleSystem::RandomizePosition(Vec2 pos){
  return Vec2(pos.x+((rand()%variation)-(variation/2)), pos.y+((rand()%variation)-(variation/2)));
}

Vec2 ParticleSystem::GetParticleVelocity(){
  return Vec2(velocity.x+((rand()%variation)-(variation/2)), velocity.y+((rand()%variation)-(variation/2)));
}

int ParticleSystem::GetLifetime(){
  if(bParticle){
    return bParticle->GetLifetime();
  }
  return 0;
}

ParticleSystem::~ParticleSystem(){
}
