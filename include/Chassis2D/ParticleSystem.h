#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <iostream>
#include <vector>
#include <memory>

#include "Global.h"
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
  int minAngle, maxAngle;
  float speed = 1.f;

  Vec2 position = Vec2(0,0);
  shared_ptr<Particle> bParticle;
  vector<shared_ptr<Particle>> particles;

  bool hide = false;
 public:

  ParticleSystem(){}
  ParticleSystem(Particle* particle, int minAngle, int maxAngle, int rate, int max, float speed);
  void Setup(Particle* particle, int minAngle, int maxAngle, int rate, int max, float speed);

  void Update();

  vector<shared_ptr<Particle>> GetParticles() { return particles; }

  void SetPosition(Vec2 position) { this->position = position; }
  void SetTime(int time) { this->time = time; }
  void SetMaximum(int max) { this->maximum = max; }
  void SetRate(int rate) { this->rate = rate; }

  int GetTime() { return time; }
  int GetMaximum() { return maximum; }
  int GetRate() { return rate; }

  void Hide() { hide = true; }
  void Show() { hide = false; }
  void SetHide(bool hide) { this->hide = hide; }
  bool IsHidden() { return hide; }

  //Destructor
  ~ParticleSystem();
};

#endif