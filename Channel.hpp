#ifndef CHANNEL_HPP
#define CHANNEL_HPP

#include "Client.hpp"

class Channel
{
    private:
        std::string name;

        
        std::vector<Client* > users;
        std::vector<Client* > operators;
        std::vector<Client* > invited_users;
        std::vector<bool> Modes;
    
    public:

};





#endif