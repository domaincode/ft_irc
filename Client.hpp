#ifndef CLIENT_HPP
#define CLIENT_HPP



#include "Server.hpp"
#include <iostream>
#include <vector>


class Server;
class Client
{
    private:
        Server* server;
        bool is_authenticated;
        int authenticate_level;
        int fd;
        std::string Nickname;

        //messages flags
        std::string msg;
        

    public:
        Client();
        ~Client();
        Client(int fd, Server* server);
        Client(const Client& other);
        Client& operator=(const Client& other);

        std::string& Get_msg();
        int get_fd()const;
        int& get_auth_level();
        std::string& get_Nickname();
        void Check_Pass();
        void Check_Nickname(std::map<int, Client>& ptr);
        void validate_Login();
        
};


#endif