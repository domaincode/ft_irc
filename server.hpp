#ifndef SERVER
#define server

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>


#include <vector>

typedef struct s_server
{
    std::vector<int> clients_fd;
    int serverSocket;
    sockaddr_in sAddress;
}t_server;


class Server
{
    private:
    t_server N;


    public:
        Server(int port);
        ~Server();
        void Accept_connection();

};

class Client
{
    private:
        // int fd;
        sockaddr_in cAddress;

    public:
            int fd;
        Client(int port);
        ~Client();
};




#endif