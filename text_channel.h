#ifndef TEXTCHANNEL_H
#define TEXTCHANNEL_H

#include <string>

#include <vector>
#include "channel.h"
#include "message.h"

using namespace std;

class TextChannel: private Channel {
    private:
        vector<Message> messages;

    public:
        TextChannel();

        ~TextChannel();

        TextChannel(vector<Message> messages);

        void addMessage(Message message);

        vector<Message> getMessages();
        void setMessages(vector<Message> messages);
};

#endif