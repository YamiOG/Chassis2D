#include "Entity.h"

#include "Chassis2D.h"


Entity::Entity(float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, int scale){
  Setup(x, y, w, h, friction, density, restitution, categoryBits, maskBits, scale);
}

int Entity::Setup(float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, int scale){

  width = w;
  height = h;
  this->scale = scale;

  bodyDef.position.Set((x + (width/2))/scale, (y + (height/2))/scale);
  shape.SetAsBox((width/2)/scale, (height/2)/scale);
  fixture.shape = &shape;

  fixture.filter.categoryBits = categoryBits;
  fixture.filter.maskBits = maskBits;

  bodyDef.type = b2_dynamicBody;
  fixture.friction = friction;
  fixture.density = density;
  fixture.restitution = restitution;
  return 0;
}
