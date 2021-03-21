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

string System::create_server(const string name) {
  if(loggedUserId == 0) {
    return "Are you sure there is someone here?";
  }

  if(name == "") {
    return "Something went wrong, check the reported values!";
  }

  for(auto &server : servers) {
    if(server.getName() == name) {
      return "Server " + name + " already exists!";
    }  
  }

  Server server(loggedUserId, name);

  servers.push_back(server);

  return "Server " + name + " successfully created!";
}

string System::set_server_desc(const string name, const string description) {
  if(loggedUserId == 0) {
    return "Are you sure there is someone here?";
  }

  if(name == "" && description == "") {
    return "Something went wrong, check the reported values!";
  }

  Server serverAux;

  for(auto &server : servers) {
    if(server.getName() == name) {
      serverAux = server;
      break;
    }  
  }

  if(serverAux.getName().empty()) {
    return "Are you sure there is exists server?";
  }
  
  if(serverAux.getOwnerUserId() != loggedUserId) {
    return "Are you sure are the server owner?";
  }

  serverAux.setDescription(description);

  for(auto &server : servers) {
    if(server.getName() == name) {
      server = serverAux;
      break;
    }  
  }

  return name + " description updated successfully!";
}

string System::set_server_invite_code(const string name, const string code) {
  if(loggedUserId == 0) {
    return "Are you sure there is someone here?";
  }

  if(name == "" && code == "") {
    return "Something went wrong, check the reported values!";
  }

  Server serverAux;

  for(auto &server : servers) {
    if(server.getName() == name) {
      serverAux = server;
      break;
    }  
  }

  if(serverAux.getName().empty()) {
    return "Are you sure there is exists server?";
  }
  
  if(serverAux.getOwnerUserId() != loggedUserId) {
    return "Are you sure are the server owner?";
  }

  serverAux.setInviteCode(code);

  for(auto &server : servers) {
    if(server.getName() == name) {
      server = serverAux;
      break;
    }  
  }

  return name + " code updated successfully!";
}

string System::list_servers() {
  if(servers.empty()) {
    return "There is no registered server!";
  }

  string listServers = "";

  for(auto &server : servers) {
    listServers += server.getName() + " - " + (server.getInviteCode().empty() || server.getInviteCode() == " " ? "public": "private") + "\n";
  }

  return listServers;
}

string System::remove_server(const string name) {
  if(loggedUserId == 0) {
    return "Are you sure there is someone here?";
  }

  if(name == "") {
    return "Something went wrong, check the reported values!";
  }

  bool isServerExist = false;

  for(int i=0; i < servers.size(); i++) {
    if(servers[i].getName() == name && servers[i].getOwnerUserId() == loggedUserId) {
      servers.erase(servers.begin() + i);
      isServerExist = true;
      break;
    }  
  }

  if(isServerExist) {
    return name + " successfully deleted!";
  }else{
    return "Are you sure there is exists server or are the server owner?";
  }
}

string System::enter_server(const string name, const string code) {
  if(name == "") {
    return "Something went wrong, check the reported values!";
  }

  if(loggedUserId == 0) {
    return "Are you sure there is someone here?";
  }

  bool isServerExist = false;

  for(auto &server : servers) {
    if(server.getName() == name 
        && (server.getInviteCode().empty() 
            || server.getInviteCode() == code 
            || server.getOwnerUserId() == loggedUserId)) {
      server.addParticipantIDs(loggedUserId);      
      serverNameLogged = server.getName();
      isServerExist = true;
      break;
    }  
  }

  if(isServerExist) {
    return "Parachuted on the server " + name + "!";
  }else{
    return "Are you sure that the server exists and the code is valid?";
  }
}

string System::leave_server() {
  if(serverNameLogged.empty()) {
    return "You are not on any server!";
  }

  string message = "Jumping out of " + serverNameLogged;

  serverNameLogged = "";

  return message;
}

string System::list_participants() {
  if(servers.empty() || serverNameLogged.empty()) {
    return "There is no registered server!";
  }

  string listParticipants = "";

  for(auto &server : servers) {
    if(server.getName() == serverNameLogged) {
      for(auto &userId : server.getParticipantIds()) {
          for(auto &user: users) {
            if(userId == user.getId()) {
                listParticipants += user.getName() += "\n";
                break;
            }
          }
      }
      break;
    }
  }

  return listParticipants;
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