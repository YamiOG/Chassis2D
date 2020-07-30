#include "Network.h"

#include "Chassis2D.h"


Network::Network(bool isServer){
    this->isServer = isServer;
}

/*int Network::Host(Uint16 port, int max){
    if(isServer){
        SDLNet_ResolveHost(server_ip, NULL, port);

        server = SDLNet_TCP_Open(&server_ip);

        socketSet = SDLNet_AllocSocketSet(max);
        this->max = max;
    }
    else{
        cout << "ERROR:This is not a Server" << endl;
        return -1;
    }
    return 0;
}

int Network::Connect(string ip, Uint16 port){
    if(isServer){
        cout << "ERROR:This is not a Client" << endl;
        return -1;
    }
    else{
        SDLNet_ResolveHost(server_ip, ip, port);
        TCPsocket client = SDLNet_TCP_Open(server_ip);

        sockets.push_back(client);

        socketSet = SDLNet_AllocSocketSet(1);
        SDLNet_TCP_AddSocket(socketSet, client);
    }
    return 0;
}*/