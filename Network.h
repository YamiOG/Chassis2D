#ifndef NETWORK_H
#define NETWORK_H

#include <iostream>
#include <string>
#include <vector>
#include <SDL2/SDL.h>
#include <SDL2/SDL_net.h>

#include "Class.h"

using namespace std;

struct NetData{
  vector<Object*> object;
  vector<Entity*> entity;
};

class Network{
 private:
   bool isServer;

   IPaddress server_ip;
   TCPsocket server;

   vector<TCPsocket> sockets;
   SDLNet_SocketSet socketSet;
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
