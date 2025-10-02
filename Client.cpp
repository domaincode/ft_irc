#include "server.hpp"

Client::~Client()
{
    std::cout << "Client Destructor Called\n";
}

Client::Client(int port)
{
    std::cout << "Client Constructor Called\n";

    fd = socket(AF_INET, SOCK_STREAM , 0);
    if(fd < 0)
    {
        std::cout << "Error: Func ==> Socket\n";
        exit(1);
    }
    cAddress.sin_family = AF_INET;
    cAddress.sin_port = htons(port);
    cAddress.sin_addr.s_addr = 0; //INADDR_ANY


    std::cout << "Connect: " << fd << " ";
    std::cout << (connect(fd, (sockaddr* )&cAddress, sizeof(cAddress)) < 0 ? "Failed\n": "Success\n");

    std::cout << errno << std::endl;
    if(errno == ECONNREFUSED)
    {
        std::cout << "ECONNREFUSED===================\n";
    }
    
}


int main(int argc, char** argv)
{
    std::string msg;

    if(argc != 2)
    {
        std::cout << "Error: arguments must be 2\n";
        return 1;
    }
    Client a(std::atoi(argv[1]));

    std::cout << "Enter: ";
    std::getline(std::cin, msg);

    // std::cout << "message: " << msg << std::endl;
    // std::cout << "socket used: " << a.fd << std::endl;
    send(a.fd, msg.c_str(), msg.size(), 0);

    
}