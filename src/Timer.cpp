#include "Timer.h"

#include "Chassis2D.h"

#include <SDL.h>

int Timer::Start(int millis){
    this->millis = millis;
    past = SDL_GetTicks();
    return 0;
}

bool Timer::Ended(){
    if(SDL_GetTicks() >= past + millis){
        return true;
    }
    return false;
}

bool Timer::Stopped(){
    return Ended();
}