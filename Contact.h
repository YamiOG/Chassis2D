#ifndef CONTACT_H
#define CONTACT_H

#include <iostream>
#include <Box2D/Box2D.h>

#include "Class.h"

using namespace std;

class Contact{
 private:
  Object *o[2];

  bool collide;
 public:
  Contact(){}
  Contact(Object *o1, Object *o2, bool collide);

  Object *GetObject(int i){return o[i];}
  bool GetCollide(){ return collide; }

  void SetCollision(bool val) { collide = val; }
};

#endif
