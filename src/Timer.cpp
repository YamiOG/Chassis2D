#include "Timer.h"

#include "Chassis2D.h"

#include <SDL.h>

void Timer::Start(){
    past = SDL_GetTicks();
}

void Timer::Start(int millis){
    this->millis = millis;
    past = SDL_GetTicks();
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