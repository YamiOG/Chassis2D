#include "Entity.h"

#include "Chassis2D.h"


Entity::Entity(App *a, float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, int scale){
  Setup(a, x, y, w, h, friction, density, restitution, categoryBits, maskBits, scale);
}

int Entity::Setup(App *a, float x, float y, float w, float h, float friction, float density, float restitution, uint16 categoryBits, uint16 maskBits, int scale){
  if(a->GetWorld() != nullptr){
    b2BodyDef bodyDef;
    b2FixtureDef fixture;
    b2PolygonShape shape;

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

    body = a->GetWorld()->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);
    body->SetUserData(this);
  }
  else{
    cout << "ERROR:b2World is nullptr" << endl;
    return -1;
  }
  return 0;
}
