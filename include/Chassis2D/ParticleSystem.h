#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <iostream>
#include <vector>
#include <memory>

#include "Global.h"
#include "Class.h"

#include "Vec2.h"
#include "Vec4.h"

using namespace std;

class ParticleSystem{
 private:
  Vec2 velocity;
  int time = -1;
  int rate, maximum, minAngle, maxAngle, categoryBits, maskBits, lifetime;
  float speed = 1.0f;

  Vec2 position, size;
  float friction, density, restitution;
  vector<shared_ptr<Particle>> particles;

  bool hide = false;
 public:
  ParticleSystem() {}
  ParticleSystem(int minAngle, int maxAngle, int rate, int maximum, float speed);
  void Setup(int minAngle, int maxAngle, int rate, int maximum, float speed);

  void SetParticle(float x, float y,float w, float h, int lifetime, int scale);
  void SetParticle(float x, float y, float w, float h, float friction, float density, float restitution, int lifetime, int scale);
  void SetParticle(float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int lifetime, int scale);

  void Update();

  vector<shared_ptr<Particle>> GetParticles() { return particles; }

  void SetPosition(Vec2 position) { this->position = position; }
  void SetTime(int time) { this->time = time; }
  void SetMaximum(int max) { this->maximum = max; }
  void SetRate(int rate) { this->rate = rate; }

  Vec2 GetPosition() { return position; }
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