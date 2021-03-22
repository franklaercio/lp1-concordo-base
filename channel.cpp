#include "channel.h"

Channel::Channel() {}

Channel::~Channel(){}

Channel::Channel(string name) {
    this->name = name;
}

string Channel::getName() {
    return this->name;
}

void Channel::setName(string name) {
    this->name = name;
}