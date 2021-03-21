#include "user.h"
#include <string>

using namespace std;

User::User(){}

User::~User(){}

User::User(int id, string name, string email, string password){
    this->id = id;
    this->name = name;
    this->email = email;
    this->password = password;
}

int User::getId() {
    return this->id;
}

void User::setId(int id) {
    this->id = id;
}

string User::getName() {
    return this->name;
}

void User::setName(string name) {
    this->name = name;
}

string User::getEmail() {
    return this->email;
}

void User::setEmail(string email) {
    this->email = email;
}

string User::getPassword() {
    return this->password;
}

void User::setPassword(string password) {
    this->password = password;
}