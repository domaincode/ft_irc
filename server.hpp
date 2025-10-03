#ifndef SERVER
#define server

#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <map>
#include <vector>
#include "Client.hpp"

#include <unistd.h>
#include <fcntl.h>
#include <string.h>


#include <poll.h>



class Server
{
    private:
        int port;
        std::map<int, Client> clients;
        std::vector<pollfd> _fds;
        int listen_fd;
        sockaddr_in sAddress;
        // t_server N;


    public:
        Server(int port);
        ~Server();
        void Start();
        void Accept_clients();
        void Check_IandO();

};

void get_clients_fd(std::vector<pollfd>& fds);
void Start_communication(Client& client);





#endif