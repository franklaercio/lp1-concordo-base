#ifndef TEXTCHANNEL_H
#define TEXTCHANNEL_H

#include <string>

#include <vector>
#include "channel.h"
#include "message.h"

using namespace std;

class TextChannel: public Channel {
    private:
        vector<Message> messages;

    public:
        TextChannel();

        ~TextChannel();

        TextChannel(string name): Channel(name){}

        void addMessage(Message message);

        vector<Message> getMessages();
        void setMessages(vector<Message> messages);
};

#endif