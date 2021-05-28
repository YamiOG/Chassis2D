#ifndef TIMER_H
#define TIMER_H

#include <iostream>

using namespace std;
class Timer{
  private:
    int millis = 0;
    int past = 0;
  public:
    Timer(){} 

    int Setup(int millis) { this->millis = millis; }
    int SetLength(int millis) { Setup(millis); }
    
    int Start();
    int Start(int millis);
    bool Stopped();
    bool Ended();
};

#endif