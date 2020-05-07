#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>

#include "Class.h"

using namespace std;

class ParticleSystem{
 private:
  int time = -1;
  int amount;
  int delay;
  float variation;
  SDL_Point velocity;
 public:
  ParticleSystem(){}
  ParticleSystem(Particle* p, SDL_Point velocity, int delay, int amount, float variation);
  void Setup(Particle* p, SDL_Point velocity, int delay, int amount, float variation);

  int SpawnParticle(int x, int y, App *a);
  void SetTime(int set) {time = set;}

  int GetTime() {return time;}

  //Destructor
  ~ParticleSystem();
};

#endif
