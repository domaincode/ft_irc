#include "server.hpp"




int main(int argc, char** argv)
{

    // Client a(12);

    // Client b = a;

    if(argc != 2)
    {
        std::cout << "Error: arguments must be 2\n";
        return 1;
    }
    Server a(std::atoi(argv[1]));

   // std::cout << "FD_SETSIZE: " << FD_SETSIZE << std::endl;
    a.Start();
    

}