#ifndef SERVER_H
#define SERVER_H

#include <string>

using namespace std;

class Server {
    private:
        int ownerUserId;
        string name;
        string description;
        string inviteCode;

    public:
        Server();

        ~Server();

        Server(int ownerUserId, string name, string description, string inviteCode);   

        int getOwnerUserId();
        void setOwnerUserId(int id);

        string getName();
        void setName(string name);

        string getDescription();
        void setDescription(string description);

        string getInviteCode();
        void setInviteCode(string inviteCode);
};

#endif