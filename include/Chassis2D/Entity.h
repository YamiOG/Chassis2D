#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

#include "Class.h"

#include "Object.h"
#include "Vec2.h"

using namespace std;

class Entity : public Object{
 private:
  float hp, speed;

  bool dead, jumping;

 public:
  Entity(){}
  Entity(App *a, float x, float y, float w, float h, float friction, float density, int scale);
  int Setup(App *a, float x, float y, float w, float h, float friction, float density, int scale);
  Entity(App *a, float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int scale);
  int Setup(App *a, float x, float y, float w, float h, float friction, float density, float restitution, int categoryBits, int maskBits, int scale);

  void SetHP(float hp) { this->hp = hp; }
  void SetDead(bool dead) { this->dead = dead; }

  float GetHP() { return hp; }
  bool IsDead() { return dead; }
};

#endif
