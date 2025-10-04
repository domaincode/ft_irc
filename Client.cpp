#include "Client.hpp"
// #include "Server.hpp"

Client::Client()
{
    std::cout << "Default Constructor Client Called\n";
}

Client::~Client()
{
    std::cout << "Destructor Client Called\n";
}

Client::Client(int fd)
{
    std::cout << "Parameter Constructor Client Called\n";
    this->fd = fd;
    this->is_authenticated = false;
    this->authenticate_level = 0;
}


Client::Client(const Client& other)
{
    std::cout << "Copy constructor Client Called\n";
    *this = other;
}


Client& Client::operator=(const Client& other)
{
    std::cout << "Assignement operator Client Called\n";

    if(this == &other)
    {
        //std::cout << "Nanyyyyyyyyyyyyyyyy\n";
        return *this;
    }
    this->fd = other.fd;
    this->is_authenticated = other.is_authenticated;
    this->authenticate_level = other.authenticate_level;
    //std::cout << fd << std::endl;

    return *this;
}

std::string& Client::Set_msg()
{
    return msg;
}

const std::string& Client::Get_msg()const
{
    return msg;
}

int Client::get_fd()const{ return fd;};




int& Client::get_auth_level()
{
    return authenticate_level;
}


void Client::Check_Pass(std::string& password)
{
    std::cout << "Start Check Password:\n";
    size_t pos = msg.find("PASS:");
    //check command && Check pass
    if(pos == std::string::npos)
    {
        send(fd, ENTERPASS, sizeof(ENTERPASS), 0);
    }
    else
    {
        //correct: set the auth flag to 1
        authenticate_level = 1;
        send(fd, PASSCMD, sizeof(PASSCMD), 0);
    }
    std::cout << "End Check Password:\n";
}

void Client::Check_Nickname(std::map<int, Client>& ptr)
{
    ///loop to check if the nick name is already taken by another user

    ///
    Nickname = msg;
    authenticate_level = 2;

}


std::string& Client::get_Nickname()
{
    return Nickname;
}