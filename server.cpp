#include "server.h"

Server::Server(){}

Server::~Server(){}

Server::Server(int ownerUserId, string name, string description, string inviteCode) {
    this->ownerUserId = ownerUserId;
    this->name = name;
    this->description = description;
    this->inviteCode = inviteCode;
}

int Server::getOwnerUserId(){
    return this->ownerUserId;
}

void Server::setOwnerUserId(int ownerUserId) {
    this->ownerUserId = ownerUserId;
}

string Server::getName() {
    return this->name;
}

void Server::setName(string name) {
    this->name = name;
}

string Server::getDescription() {
    return this->description;
}

void Server::setDescription(string description) {
    this->description = description;
}

string Server::getInviteCode() {
    return this->inviteCode;
}

void Server::setInviteCode(string inviteCode) {
    this->inviteCode = inviteCode;
}