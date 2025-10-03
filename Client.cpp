#include "Client.hpp"

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
    std::cout << "blablalallalalaa\n";
    this->fd = other.fd;
        std::cout << fd << std::endl;

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