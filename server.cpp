#include "server.hpp"


Server::Server(int port)
{
    std::cout << "Server Constructor Called\n";

    network.serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if(network.serverSocket < 0)
    {
        std::cout << "Error: Func ==> Socket\n";
        exit(1);
    }
    network.serverAddress.sin_family = AF_INET;
    network.serverAddress.sin_port = htons(port);
    network.serverAddress.sin_addr.s_addr = 0; //INADDR_ANY

    

}
Server::~Server()
{
    std::cout << "Server Destructor Called\n";
}