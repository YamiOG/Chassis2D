#include "ParticleSystem.h"

#include "Chassis2D.h"

ParticleSystem::ParticleSystem(Particle* p, Vec2 velocity, int delay, int amount, int variation){
  bParticle = p;

  this->velocity = velocity;
}

void ParticleSystem::Setup(Particle* p, Vec2 velocity, int delay, int amount, int variation){
  bParticle = p;

  this->velocity = velocity;
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
