#include "message.h"

Message::Message() {}

Message::~Message() {}

Message::Message(int sendUserId, string date, string content) {
    this->sendUserId = sendUserId;
    this->date = date;
    this->content = content;
}

int Message::getUserId(){
    return this->sendUserId;
}

void Message::setUserId(int sendUserId) {
    this->sendUserId = sendUserId;
}

string Message::getDate(){
    return this->date;
}

void Message::setDate(string date) {
    this->date = date;
}

string Message::getContent(){
    return this->content;
}

void Message::setContent(string content) {
    this->content = content;
}