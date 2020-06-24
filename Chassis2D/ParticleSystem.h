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
  int time = 0;
  int dTime = 0;
  int amount, delay, variation;
  int count = 0;
  Vec2 velocity;

  Vec2 pos = Vec2(0,0);
  Particle *bParticle;
  vector<int> spawnTimes;
 public:
  ParticleSystem(){}
  ParticleSystem(Particle* particle, Vec2 velocity, int delay, int amount, int variation);
  void Setup(Particle* particle, Vec2 velocity, int delay, int amount, int variation);

  void SetTime(int time) {this->time = time;}
  void SetDelayTime(int dTime) {this->dTime = dTime;}
  void SetCount(int count) {this->count = count;}
  void SetPosition(Vec2 pos) {this->pos = pos;}

  int GetTime() {return time;}
  int GetDelayTime() {return dTime;}
  int GetDelay() {return delay;}
  int GetAmount() {return amount;}
  int GetCount() {return count;}
  vector<int> GetSpawnTimes() { return spawnTimes; }
  int GetLifetime();
  Vec2 GetPosition() {return pos;}

  Particle *GetBaseParticle() {return bParticle;}
  Vec2 RandomizePosition(Vec2 pos);
  Vec2 GetParticleVelocity();

  //Destructor
  ~ParticleSystem();
};

#endif
