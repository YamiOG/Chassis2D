#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>

#include "Class.h"

using namespace std;

class Contact{
 private:
  Object *o[2];

  bool collide;
 public:
  Contact(){}
  Contact(Object *o1, Object *o2, bool collide);
  Contact(Entity *o1, Object *o2, bool collide);
  Contact(Object *o1, Entity *o2, bool collide);
  Contact(Entity *o1, Entity *o2, bool collide);

  Object *GetObject(int i){return o[i];}
  bool GetCollide(){ return collide; }

  void SetCollision(bool val) { collide = val; }

  ~Contact();
};

#endif
