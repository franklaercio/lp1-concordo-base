#ifndef VOICECHANNEL_H
#define VOICECHANNEL_H

#include <string>
#include <vector>

#include "channel.h"
#include "message.h"

using namespace std;

class VoiceChannel: private Channel {
    private:
        Message lastMessage;

    public:
        VoiceChannel();

        ~VoiceChannel();

        VoiceChannel(Message message);

        Message getLastMessage();
        void setLastMessage(Message message);
};

#endif