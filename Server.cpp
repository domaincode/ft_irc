#include "Server.hpp"

Server::~Server()
{
    std::cout << "Server Destructor Called\n";
}

Server::Server(int port)
{
    std::cout << "Server Constructor Called\n";
    this->port = port;
    this->password = "123";
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

    //// Back log find the best value ????
    std::cout << "Listen: " ;
    std::cout << (listen(listen_fd, 2) < 0 ? "Failed\n": "Success\n");
    Use_Poll();

}

void Server::Use_Poll()
{
    int j;

    pollfd fd;
    memset(&fd, 0, sizeof(fd));
    fd.events = POLLIN;
    fd.fd = listen_fd;
    _fds.push_back(fd);
  
    while(1)
    {
        //must set all the pollfd members 
        std::cout << "================Poll: Start========================================\n";
        j = poll(_fds.data(), _fds.size(), -1);
        if(j == -1)
        {
            std::cout << "error: in poll\n";
            exit(0);
        }
        else
        {
            std::cout << "Reads available: " << j << std::endl;
        }
        std::cout << "================Poll: End========================================\n";
        Check_IandO();

        //delete
        if(_fds.size() == 4)
            break;

}

}


void Server::Check_IandO()
{
    if(_fds[0].revents == POLLIN)
    {
        //New Client in the queue ???
        pollfd fd;
        memset(&fd, 0, sizeof(fd));
        fd.events = POLLIN;
        //POLLIN

        fd.fd = accept(listen_fd, NULL, NULL);
        std::cout << "/\\/\\/\\/\\/\\/\\/\\/\\/\\/\\Accept: " << fd.fd << " is connecting.\n";
        if(fd.fd < 0)
        {
            std::cout << "Error: in accept\n";
            exit(1);
        }

        // Must be check: the preiveus flags for socket ????? New client Flags ??
        fcntl(fd.fd, F_SETFL, O_NONBLOCK); //fcntl Non Blocking I/O

        //add the new client to the array for monitoring
        _fds.push_back(fd);
        Client new_client(fd.fd, this);

        // Client must have Default Constructor
        clients[fd.fd] = new_client;
         std::cout << "Server have: " << clients.size() << " Clients."<< std::endl;
    }
    for(unsigned int i = 1; i < _fds.size(); i++)
    {
        if(_fds[i].revents == POLLIN)
        {
            std::cout << "================Communication: Start========================================\n";
            std::cout << "Client n: " << _fds[i].fd << std::endl;
           // std::cout << "size of map " << clients.size() << std::endl;
            Start_communication(clients[_fds[i].fd]);
            std::cout << "================Communication: End========================================\n";
        }
        // else if(_fds[i].)
        // {

        // }
    }
}


void Server::Start_communication(Client& client)
{
    char buffer[1024] = {0};

    int nb_read = recv(client.get_fd(), buffer, 1023, 0);

    if(nb_read == 0)
    {
        std::cout << "Client: Shutdown\n";
        exit(0);
    }
    else if(nb_read < 0)
    {
        std::cout << "Error: in recv function\n";
        exit(0);
    }
    
    //buffer += read
    client.Get_msg() = buffer;
    client.validate_Login();
    
    std::cout << "Read from client: " << nb_read << std::endl;
    std::cout << "Message: ." << client.Get_msg() << "." << std::endl;
}


bool Server::Nick_isDuplicated(std::string& Nickname)
{
    for(std::map<int, Client>::iterator it = clients.begin(); it != clients.end(); it++)
    {
        if(Nickname == it->second.get_Nickname())
            return true;
    }
    return false;
}



void Server::print_clients()
{
    for(int i = 0; i < clients.size(); i++)
    {
        std::cout << "Client: " << clients[_fds[i].fd].get_fd();
        std::cout << " NICK: " << clients[_fds[i].fd].get_Nickname() << std::endl;

    }
}
