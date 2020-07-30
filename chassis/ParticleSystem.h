#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <iostream>
#include <vector>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

#include "Class.h"

#include "Vec2.h"

using namespace std;

class ParticleSystem{
 private:
  Vec2 velocity;
  int time = -1;
  int rate = 1;
  int maximum = -1;
  int count = 0;

  Vec2 pos = Vec2(0,0);
  Particle *bParticle;
  vector<Particle*> particles;
 public:

  ParticleSystem(){}
  ParticleSystem(Particle* particle, Vec2 velocity, int delay, int amount, int variation);
  void Setup(Particle* particle, Vec2 velocity, int delay, int amount, int variation);

  int AddParticle(Particle *particle);
  void CheckParticles();

  vector<Particle*> GetParticles() { return particles; }
  Particle *GetBaseParticle() {return bParticle;}
  Vec2 RandomizePosition(Vec2 pos);
  Vec2 GetParticleVelocity();

  void SetTime(int time) { this->time = time; }
  void SetMaximum(int max) { this->maximum = max; }
  void SetRate(int rate) { this->rate = rate; }

  int GetMaximum() { return maximum; }
  int GetTime() { return time; }
  int GetRate() { return rate; }

  //Destructor
  ~ParticleSystem();
};

#endif
