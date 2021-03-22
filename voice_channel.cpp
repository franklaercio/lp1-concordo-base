#include "voice_channel.h"

VoiceChannel::~VoiceChannel() {}

Message VoiceChannel::getLastMessage() {
    return this->lastMessage;
}

void VoiceChannel::setLastMessage(Message message) {
    this->lastMessage = message;
}


