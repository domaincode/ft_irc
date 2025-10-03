#include "server.hpp"

Server::~Server()
{
    std::cout << "Server Destructor Called\n";
}

Server::Server(int port)
{
    std::cout << "Server Constructor Called\n";
    this->port = port;
}

void Server::Start()
{
    listen_fd = socket(AF_INET, SOCK_STREAM | SOCK_NONBLOCK, 0);
    if(listen_fd < 0)
    {
        std::cout << "Error: Func ==> Socket\n";
        exit(1);
    }
    sAddress.sin_family = AF_INET;
    sAddress.sin_port = htons(port);
    sAddress.sin_addr.s_addr = 0; //INADDR_ANY
    
    std::cout << "Bind: " ;
    std::cout << (bind(listen_fd, (sockaddr* )&sAddress, sizeof(sAddress)) < 0 ? "Failed\n": "Success\n");

    std::cout << "Listen: " ;
    std::cout << (listen(listen_fd, 2) < 0 ? "Failed\n": "Success\n");
    Accept_clients();

}

void Server::Accept_clients()
{
    int j;

    pollfd fd;
    memset(&fd, 0, sizeof(fd));
    fd.events = POLLIN;
    fd.fd = listen_fd;
    _fds.push_back(fd);
  
    while(1)
    {
        j = poll(_fds.data(), _fds.size(), -1);
        if(j == -1)
        {
            std::cout << "error: in poll\n";
            exit(0);
        }
        else
        {
            std::cout << "_fds: " << j << std::endl;
        }
        Check_IandO();

        if(_fds.size() == 3)
            break;

}

get_clients_fd(_fds);

}


void Server::Check_IandO()
{
    if(_fds[0].revents == POLLIN)
    {
        pollfd fd;
        memset(&fd, 0, sizeof(fd));
        fd.events = POLLIN;
        //POLLIN

        fd.fd = accept(listen_fd, NULL, NULL);
        std::cout << "acceppppppppppppppppt: " << fd.fd << std::endl;
        if(fd.fd < 0)
        {
            std::cout << "Error: in accept\n";
            exit(1);
        }

        // Must be check: the preiveus flags for socket ?????
        fcntl(fd.fd, F_SETFL, O_NONBLOCK);

        //fcntl Non Blocking I/O
        _fds.push_back(fd);
        Client new_client(fd.fd);
                    std::cout << "qqqqqqqqqqqqqqsize of map " << clients.size() << std::endl;

        clients[fd.fd] = new_client;
    }
    for(unsigned int i = 1; i < _fds.size(); i++)
    {
        if(_fds[i].revents == POLLIN)
        {
            std::cout << "size of map " << clients.size() << std::endl;
            std::cout << "yow test=============================== for fd\n";
            std::cout << clients[4].get_fd() << std::endl;
            Start_communication(clients[4]);
        }
    }
}
