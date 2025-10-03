#ifndef CLIENT_HPP
#define CLIENT_HPP


#include <iostream>
#include <vector>


class Client
{
    private:
        int fd;
        std::string nick_name;

        //messages flags
        std::string msg;
        

    public:
        Client();
        ~Client();
        Client(int fd);
        Client(const Client& other);
        Client& operator=(const Client& other);

        std::string& Set_msg();
        const std::string& Get_msg()const;
        int get_fd()const;
        
};


#endif