#include "text_channel.h"

TextChannel::TextChannel() {}

TextChannel::~TextChannel(){}

TextChannel::TextChannel(vector<Message> messages) {
    this->messages = messages;
}

void TextChannel::addMessage(Message message) {
    this->messages.push_back(message);
}

vector<Message> TextChannel::getMessages() {
    return this->messages;
}

void TextChannel::setMessages(vector<Message> messages) {
    this->messages = messages;
}