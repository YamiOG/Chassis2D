#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <SDL2/SDL.h>
#include <Box2D/Box2D.h>

#include "Class.h"

#include "Object.h"
#include "Vec2.h"

using namespace std;

class Entity : public Object{
 private:
  float hp, speed;

  bool dead;

 public:
  Entity(){}
  Entity(float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, int scale);
  int Setup(float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, int scale);
  void SetSensor(float x, float y, float w, float h);
  void SetHP(float hp) {this->hp = hp;}
};

#endif
