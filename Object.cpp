#include "Object.h"

void Object::Setup(Chassis c, float x, float y, float w, float h, float friction, float density, float restitution, bool isD, int setScale){
  if(c.GetWorld() != nullptr){
    b2BodyDef bodyDef;
    b2PolygonShape shape;
    b2FixtureDef fixture;

    width = w;
    height = h;
    scale = setScale;

    bodyDef.position.Set((x + (width/2))/scale, (y + (height/2))/scale);
    shape.SetAsBox((width/2)/scale, (height/2)/scale);
    fixture.shape = &shape;

    if(isD){
      bodyDef.type = b2_dynamicBody;
      fixture.density = density;
      fixture.friction = friction;
      fixture.restitution = restitution;
    }
    else{
      bodyDef.type = b2_staticBody;
    }
    body = c.GetWorld()->CreateBody(&bodyDef);
    body->CreateFixture(&fixture);

    body->SetUserData(this);
  }
}

SDL_Rect Object::GetScaledPosition() {
  SDL_Rect rect = { (int)((body->GetPosition().x * scale) - (width / 2)), (int)((body->GetPosition().y * scale) - (height / 2)), (int)width, (int)height };
    return rect;
}
