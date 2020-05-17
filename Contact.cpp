#include "Contact.h"

#include "Chassis2D.h"

Contact::Contact(Object* o1, Object* o2, bool collide){
  o[0] = o1;
  o[1] = o2;

  this->collide = collide;
}
