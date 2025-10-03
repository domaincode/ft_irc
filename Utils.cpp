#include "server.hpp"


void get_clients_fd(std::vector<pollfd>& fds)
{
    int i = 0;
    std::cout << "Clients: \n"; 
    while(i < fds.size())
    {
        std::cout << fds.at(i).fd << std::endl;
        i++;
    }
    std::cout << "End of clients\n";
}


void Start_communication(Client& client)
{
    std::cout << "start comminication for new client.\n";
    char buffer[1024] = {0};

    std::cout << "client: " << client.get_fd() << std::endl;
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

    client.Set_msg() = buffer;
    std::cout << "Read from client: " << client.get_fd() << nb_read << std::endl;
    std::cout << "Message: " << client.Get_msg() << std::endl;


}