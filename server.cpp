#include "server.h"

Server::Server(){}

Server::~Server(){}

Server::Server(int ownerUserId, string name) {
    this->ownerUserId = ownerUserId;
    this->name = name;
}

void Server::addParticipantIDs(int participantId) {
    bool existId = false;

    for (auto id: participantIds) {
      if(id == participantId) {
        existId = true;
      }
    }

    if(!existId) {
      this->participantIds.push_back(participantId);
    }
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

vector<int> Server::getParticipantIds() {
    return this->participantIds;
}

void Server::setParticipantIds(vector<int> participantIds) {
    this->participantIds = participantIds;
}