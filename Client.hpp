#ifndef CLIENT_HPP
#define CLIENT_HPP



#include "Server.hpp"
#include <iostream>
#include <vector>


class Client
{
    private:
        // flags
        
        bool is_authenticated;
        int authenticate_level;
        int fd;
        std::string Nickname;

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
        int& get_auth_level();
        std::string& get_Nickname();
        void Check_Pass(std::string& password);
        void Check_Nickname(std::map<int, Client>& ptr);
        
};


#endif