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

    void Setup(int millis) { this->millis = millis; }
    void SetLength(int millis) { Setup(millis); }
    
    void Start();
    void Start(int millis);
    bool Stopped();
    bool Ended();
};

#endif