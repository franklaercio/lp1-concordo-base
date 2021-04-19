#include "system.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <memory>
#include <fstream>
#include <stdio.h>
#include <string>

#include "text_channel.h"
#include "voice_channel.h"

using namespace std;

string System::quit() {
  save();
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

  save();

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

  save();

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

  save();

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

  save();

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
  if(servers.empty() || serverNameLogged.empty() || loggedUserId == 0) {
    return "There is no registered server!";
  }

  string listChannels = "";

  for(auto &server : servers) {
    if(server.getName() == serverNameLogged) {
      vector<shared_ptr<Channel>>::iterator it;

      listChannels += "#text channels\n";

      for(it = server.channels.begin(); it != server.channels.end(); it++) {
        shared_ptr<Channel> channel = *it;
        
        if(dynamic_pointer_cast<TextChannel>( channel ) != nullptr) {
          listChannels += channel->getName() + "\n";
        }
      }

      listChannels += "#voice channels\n";

      for(it = server.channels.begin(); it != server.channels.end(); it++) {
        shared_ptr<Channel> channel = *it;
        
        if(dynamic_pointer_cast<VoiceChannel>( channel ) != nullptr) {
          listChannels += channel->getName() + "\n";
        }
      }
    }
  }

  return "listChannels";
}

string System::create_channel(const string name, const string type) {
  if(servers.empty() || serverNameLogged.empty() || loggedUserId == 0) {
    return "There is no registered server!";
  }

  if(name == "" || type == "") {
    return "Something went wrong, check the reported values!";
  }

  for(auto &server : servers) {
    if(server.getName() == serverNameLogged) {
      vector<shared_ptr<Channel>>::iterator it;

      for(it = server.channels.begin(); it != server.channels.end(); it++) {
        shared_ptr<Channel> channel = *it;

        if(channel-> getName() == name) {
          return "Channel " + name + " exists!";
        }
      }

      if(type == "texto") {
        shared_ptr<TextChannel> newChannel = make_shared<TextChannel>(name);
        server.channels.push_back(newChannel);
      }else if(type == "voz") {
        shared_ptr<VoiceChannel> newChannel = make_shared<VoiceChannel>(name);
        server.channels.push_back(newChannel);
      }
    }
  }

  save();

  return "Channel " + name + " successfully created!";
}

string System::enter_channel(const string name) {
  if(servers.empty() || serverNameLogged.empty() || loggedUserId == 0) {
    return "There is no registered server!";
  }

  if(name == "") {
    return "Something went wrong, check the reported values!";
  }

  channelNameLogged = name;

  return "Joined the channel " + name + "!";
}

string System::leave_channel() {
  if(servers.empty() || serverNameLogged.empty() || channelNameLogged.empty() || loggedUserId == 0) {
    return "There is no registered channel or server!";
  }

  string channelLeave = channelNameLogged;

  channelNameLogged = "";

  return "Leave the channel " + channelLeave + "!";
}

string System::send_message(const string message) {
  if(servers.empty() || serverNameLogged.empty() || channelNameLogged.empty() || loggedUserId == 0) {
    return "There is no registered channel or server!";
  }

  if(message == "") {
    return "Something went wrong, check the reported values!";
  }

  for(auto &server : servers) {
    if(server.getName() == serverNameLogged) {
      vector<shared_ptr<Channel>>::iterator it;

      for(it = server.channels.begin(); it != server.channels.end(); it++) {
        shared_ptr<Channel> channel = *it;

        if(channel-> getName() == channelNameLogged) {
          if(dynamic_pointer_cast<TextChannel>(channel) != nullptr) {
            Message sendMessage(loggedUserId, "21/03/2021", message);
            dynamic_pointer_cast<TextChannel>(channel)->addMessage(sendMessage);

            save();

            return "Text " + message + " sended successfully!";
          }else if (dynamic_pointer_cast<VoiceChannel>(channel) != nullptr) {
            Message sendMessage(loggedUserId, "21/03/2021", message);
            dynamic_pointer_cast<VoiceChannel>(channel)->setLastMessage(sendMessage);

            save();

            return "Voice message " + message + " sended successfully!";
          }
        }
      }
    }
  }

  return "Something went wrong!";
}

string System::list_messages() {
  if(servers.empty() || serverNameLogged.empty() || channelNameLogged.empty() || loggedUserId == 0) {
    return "There is no registered channel or server!";
  }

  for(auto &server : servers) {
    if(server.getName() == serverNameLogged) {
      vector<shared_ptr<Channel>>::iterator it;

      string output = "";

      for(it = server.channels.begin(); it != server.channels.end(); it++) {
        shared_ptr<Channel> channel = *it;
        
        if(dynamic_pointer_cast<TextChannel>(channel) != nullptr) {
          if(dynamic_pointer_cast<TextChannel>(channel)->getMessages().size() > 0) {
            for(auto &message : dynamic_pointer_cast<TextChannel>(channel)->getMessages()) {
              string userName = "";

              for(auto &user : users) {
                if(message.getUserId() == user.getId()) {
                  userName = user.getName();
                  break;
                }
              }

              output += userName + "<" + message.getDate() + ">:" + message.getContent() + "\n";
            }
          }
        }
        
        if (dynamic_pointer_cast<VoiceChannel>(channel) != nullptr) {
          Message message = dynamic_pointer_cast<VoiceChannel>(channel)->getLastMessage();
          
          if(!message.getContent().empty()) {
            string userName = "";

            for(auto &user : users) {
              if(message.getUserId() == user.getId()) {
                userName = user.getName();
                break;
              }
            }

            output += userName + "<" + message.getDate() + ">:" + message.getContent() + "\n";
          }
        }
      }

      if(output.empty()) {
        return "There is no message!";
      }else{
        return output;
      }
    }
  }

  return "Something went wrong!";
}

void System::saveUsers() {
  fstream usersTxt;
  
  usersTxt.open("usuarios.txt", ios::out | ios::app);

  usersTxt << users.size() << "\n";

  for (auto user: users) {
    usersTxt << user.getId() << "\n";
    usersTxt << user.getName() << "\n";
    usersTxt << user.getEmail() << "\n";
    usersTxt << user.getPassword() << "\n";
  }
  
  usersTxt.close();
}

void System::saveServers() {
  fstream serversTxt;
  
  serversTxt.open("servidores.txt", ios::out | ios::app);

  serversTxt << servers.size() << "\n";

  for (auto server: servers) {
    serversTxt << server.getOwnerUserId() << "\n";
    serversTxt << server.getName() << "\n";
    serversTxt << server.getDescription() << "\n";
    serversTxt << server.getInviteCode() << "\n";

    serversTxt << server.getParticipantIds().size() << "\n";

    for (auto participantId: server.getParticipantIds()){
      serversTxt << participantId << "\n";
    }

    vector<shared_ptr<Channel>>::iterator it;

    serversTxt << server.channels.size() << "\n";

    for(it = server.channels.begin(); it != server.channels.end(); it++) {
      shared_ptr<Channel> channel = *it;

      if(dynamic_pointer_cast<TextChannel>(channel) != nullptr) {
        if(dynamic_pointer_cast<TextChannel>(channel)->getMessages().size() > 0) {
          serversTxt << dynamic_pointer_cast<TextChannel>(channel)->getName() << "\n";
          serversTxt << "TEXTO" << "\n";
          serversTxt << dynamic_pointer_cast<TextChannel>(channel)->getMessages().size() << "\n";
          
          for(auto &message : dynamic_pointer_cast<TextChannel>(channel)->getMessages()) {
            serversTxt << message.getUserId() << "\n";
            serversTxt << message.getDate() << "\n";
            serversTxt << message.getContent() << "\n";
          }
        }
      }
      
      if (dynamic_pointer_cast<VoiceChannel>(channel) != nullptr) {
        Message message = dynamic_pointer_cast<VoiceChannel>(channel)->getLastMessage();
        serversTxt << dynamic_pointer_cast<VoiceChannel>(channel)->getName() << "\n";
        serversTxt << "VOZ" << "\n";
        serversTxt << 1 << "\n";
        serversTxt << message.getUserId() << "\n";
        serversTxt << message.getDate() << "\n";
        serversTxt << message.getContent() << "\n";
      }
    }
  }
  
  serversTxt.close();
}

void System::save() {
  remove("usuarios.txt");
  remove("servidores.txt");

  saveUsers();
  saveServers();
}

void System::loadUsers() {
  ifstream usersTxt;
  
  usersTxt.open("usuarios.txt", ios::out | ios::app);

  if (usersTxt.is_open()) {
    string line;

    getline(usersTxt, line);

    int size;

    stringstream ss;  
    ss << line;  
    ss >> size;

    if(size > 0) {
      while (!usersTxt.eof()) {
        getline(usersTxt, line);
        string id = line;
        getline(usersTxt, line);
        string name = line;
        getline(usersTxt, line);
        string email = line;
        getline(usersTxt, line);
        string password = line;
        create_user(email, password, name);
      }
    }

    usersTxt.close();
  }  
}

void System::loadServers() {
  ifstream serversTxt;
  
  serversTxt.open("servidores.txt", ios::out | ios::app);

  if (serversTxt.is_open()) {
    string line;

    getline(serversTxt, line);

    int size, userOwnerId, totalParticipants, participantId, totalChannels;

    stringstream ss;  
    ss << line;  
    ss >> size;

    if(size > 0) {
      while (!serversTxt.eof()) {
        getline(serversTxt, line);
        string id = line;
        ss << line;  
        ss >> userOwnerId;
        getline(serversTxt, line);
        string serverName = line;
        getline(serversTxt, line);
        string serverDescription = line;
        getline(serversTxt, line);
        string serverInviteCode = line;

        Server server(userOwnerId, serverName);
        server.setDescription(serverDescription);
        server.setInviteCode(serverInviteCode);
        servers.push_back(server);

        getline(serversTxt, line);
        ss << line;  
        ss >> totalParticipants;

        if (totalParticipants > 0) {
          for (int i = 0; i < totalParticipants; i++) {
            getline(serversTxt, line);
            ss << line;  
            ss >> participantId;

            server.addParticipantIDs(participantId);
          }
        }

        getline(serversTxt, line);
        ss << line;  
        ss >> totalChannels;

        if (totalChannels > 0) {
          for (int i = 0; i < totalChannels; i++) {
            
          }
        }
      }
    }

    serversTxt.close();
  }  
}

void System::load() {
  loadUsers();
}