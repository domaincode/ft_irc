#ifndef SERVER
#define server

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>

typedef struct s_server
{
    int serverSocket;
    sockaddr_in serverAddress;
}t_server;


class Server
{
    private:
    t_server network;


    public:
        Server(int port);
        ~Server();

};




#endif