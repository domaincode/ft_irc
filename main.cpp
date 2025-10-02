#include "server.hpp"


int main(int argc, char** argv)
{
    if(argc != 2)
    {
        std::cout << "Error: arguments must be 2\n";
        return 1;
    }

    std::cout << SOCK_STREAM << std::endl;
    std::cout << SOCK_NONBLOCK << std::endl;

}