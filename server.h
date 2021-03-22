#ifndef SERVER_H
#define SERVER_H

#include <vector>
#include <string>

#include "channel.h"

using namespace std;

class Server {
    private:
        int ownerUserId;
        string name;
        string description;
        string inviteCode;
        vector<int> participantIds;

    public:
        vector<Channel *> channels;
        
        Server();

        ~Server();

        Server(int ownerUserId, string name);

        void addParticipantIDs(int participantId);

        void addChannel(Channel channel);   

        int getOwnerUserId();
        void setOwnerUserId(int id);

        string getName();
        void setName(string name);

        string getDescription();
        void setDescription(string description);

        string getInviteCode();
        void setInviteCode(string inviteCode);

        vector<int> getParticipantIds();
        void setParticipantIds(vector<int> participantIds);
};

#endif