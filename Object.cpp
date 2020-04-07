#include "Object.h"

int Object::Setup(Chassis c, float x, float y, float w, float h, float friction, float density, float restitution, bool isD, int setScale){
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
  else{
    cout << "ERROR:b2World was null" << endl;
    return 1;
  }
  return 0;
}
int Object::SetTexture(Chassis c, const char* loc){
  SDL_Surface *surf = IMG_Load(loc);
  if(surf){
    texture = SDL_CreateTextureFromSurface(c.GetRenderer(), surf);
  }
  else{
    cout << "ERROR:Failed to load file" << endl;
    return 1;
  }
  SDL_FreeSurface(surf);
  return 0;
}

SDL_Rect Object::GetScaledPosition() {
  SDL_Rect rect = { (int)((body->GetPosition().x * scale) - (width / 2)), (int)((body->GetPosition().y * scale) - (height / 2)), (int)width, (int)height };
    return rect;
}

void Object::Draw(Chassis c){
  SDL_Rect rect = GetScaledPosition();
  SDL_RenderCopy(c.GetRenderer(), texture, NULL, &rect);
}
