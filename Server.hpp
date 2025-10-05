#ifndef SERVER
#define SERVER

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

#define ENTERPASS "\033[31mServer: Enter ""PASS"" as command.\033[0m\n"
#define PASSCMD "\033[32mserver: PASS COMMAND RECIVED.\033[0m\n"
#define LEVEL  "Current Level: "
#define WELCOME "Welcome to the ft_irc server\n"

class Client;

class Server
{
    private:
        std::string password; 
        int port;
        std::map<int, Client> clients;
        std::vector<pollfd> _fds;
        int listen_fd;
        sockaddr_in sAddress;


    public:
        Server(int port);
        ~Server();
        void Start();
        void Use_Poll();
        void Check_IandO();
        void Start_communication(Client& client);
        bool Nick_isDuplicated(std::string& Nickname);
        void print_clients();

};







#endif