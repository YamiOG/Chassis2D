#include "Vec2.h"

#include <box2d/box2d.h>

Vec2::Vec2(b2Vec2 p) { 
    this->x = p.x; this->y = p.y;
}

b2Vec2 *Vec2::ToB2() { 
    tmp->Set(x, y);
    return tmp; 
}
