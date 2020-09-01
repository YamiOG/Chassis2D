#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>

#include "Class.h"

using namespace std;

class Network{
 private:
   bool isServer;

   int max;

 public:
  Network(){}
  Network(bool isServer);

  int Host(Uint16 port, int max);
  int Connect(string ip, Uint16 port);

  void AddQuene();

  ~Network();
};

#endif
