#include "Vec2.h"

#include <Box2D/Box2D.h>

Vec2::Vec2(b2Vec2 p) { 
    this->x = p.x; this->y = p.y;
}

b2Vec2 *Vec2::ToB2() { 
    return &b2Vec2(x,y);
}
