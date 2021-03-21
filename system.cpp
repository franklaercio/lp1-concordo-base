#include "system.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

string System::quit() {
  return "See you son...";
}

string System::create_user (const string email, const string senha, const string nome) {
  if(nome == "" && email == "" && senha == ""){
    return "Something went wrong, check the reported values!";
  }  

  for(auto &user : users){
    if(user.getEmail() == email) {
      return nome + " already exists with " + email + "!";
    }  
  }

  countUsers += 1;

  User user(countUsers, nome, email, senha);

  users.push_back(user);

  return nome + " landed on the Moon!";
}

string System::login(const string email, const string senha) {
  if(email == "" && senha == "") {
    return "Something went wrong, check the reported values!";
  }

  for(auto &user : users) {
    if(user.getEmail() == email && user.getPassword() == senha) {
      loggedUserId = user.getId();

      return "Welcome " + user.getName() + "!";
    }
  }

  return "Check your email and password!";
}

string System::disconnect() {
  if(loggedUserId == 0) {
    return "Are you sure there is someone here?";
  }

  for(auto &user : users) {
    if(user.getId() == loggedUserId) {
      loggedUserId = 0;

      return "Disconnecting " + user.getName() + "..." + "You say good bye. I say hello!";
    }
  }

  return "Something went wrong!";
}

string System::create_server(const string nome) {
  return "create_server NÃO IMPLEMENTADO";
}

string System::set_server_desc(const string nome, const string descricao) {
  return "set_server_desc NÃO IMPLEMENTADO";
}

string System::set_server_invite_code(const string nome, const string codigo) {
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string System::list_servers() {
  return "list_servers NÃO IMPLEMENTADO";
}

string System::remove_server(const string nome) {
  return "remove_server NÃO IMPLEMENTADO";
}

string System::enter_server(const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string System::leave_server() {
  return "leave_server NÃO IMPLEMENTADO";
}

string System::list_participants() {
  return "list_participants NÃO IMPLEMENTADO";
}

string System::list_channels() {
  return "list_channels NÃO IMPLEMENTADO";
}

string System::create_channel(const string nome, const string tipo) {
  return "create_channel NÃO IMPLEMENTADO";
}

string System::enter_channel(const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string System::leave_channel() {
  return "leave_channel NÃO IMPLEMENTADO";
}

string System::send_message(const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string System::list_messages() {
  return "list_messages NÃO IMPLEMENTADO";
}