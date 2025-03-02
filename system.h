#ifndef SYSTEM_H
#define SYSTEM_H
#include <vector>
#include <string>
#include <iostream>

#include "user.h"
#include "server.h"

using namespace std;

class System {
  private:
    vector<Server> servers;
    vector<User> users;
    int loggedUserId = 0, countUsers = 0;
    string serverNameLogged;
    string channelNameLogged;
    void saveUsers();
    void saveServers();
    void loadUsers();
    void loadServers();

  public:
    string quit();
    string create_user (const string email, const string senha, const string nome);
    string login(const string email, const string senha);
    string disconnect();
    string create_server(const string nome);
    string set_server_desc(const string nome, const string descricao);
    string set_server_invite_code(const string nome, const string codigo);
    string list_servers();
    string remove_server(const string nome);
    string enter_server(const string nome, const string codigo);
    string leave_server();
    string list_participants();
    string list_channels();
    string create_channel(const string nome, const string tipo);
    string enter_channel(const string nome);
    string leave_channel();
    string send_message(const string mensagem);
    string list_messages();
    void save();
    void load();
};

#endif