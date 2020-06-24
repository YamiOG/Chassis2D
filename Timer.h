#ifndef TIMER_H
#define TIMER_H

#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

class Timer{
  private:
    int millis = 0;
    int past = 0;
  public:
    Timer(){} 

    int Start(int millis);

    bool Ended();
};

#endif