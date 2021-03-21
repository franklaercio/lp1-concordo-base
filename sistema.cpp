#include "sistema.h"
#include <iostream>
#include <sstream>
#include <algorithm>

using namespace std;

/* COMANDOS */
string Sistema::quit() {
  return "Saindo...";
}

string Sistema::create_user (const string email, const string senha, const string nome) {
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

string Sistema::login(const string email, const string senha) {
  if(email == "" && senha == "") {
    return "Something went wrong, check the reported values!";
  }

  for(auto &user : users) {
    if(user.getEmail() == email && user.getPassword() == senha) {
      usuarioLogadoId = user.getId();

      return "Welcome " + user.getName() + "!";
    }
  }

  return "Check your email and password!";
}

string Sistema::disconnect() {
  if(usuarioLogadoId == 0) {
    return "Are you sure there is someone here?";
  }

  for(auto &user : users) {
    if(user.getId() == usuarioLogadoId) {
      usuarioLogadoId = user.getId();

      return "Disconnecting " + user.getName() + "..." + "You say good bye. I say hello!";
    }
  }

  return "Something went wrong!";
}

string Sistema::create_server(const string nome) {
  return "create_server NÃO IMPLEMENTADO";
}

string Sistema::set_server_desc(const string nome, const string descricao) {
  return "set_server_desc NÃO IMPLEMENTADO";
}

string Sistema::set_server_invite_code(const string nome, const string codigo) {
  return "set_server_invite_code NÃO IMPLEMENTADO";
}

string Sistema::list_servers() {
  return "list_servers NÃO IMPLEMENTADO";
}

string Sistema::remove_server(const string nome) {
  return "remove_server NÃO IMPLEMENTADO";
}

string Sistema::enter_server(const string nome, const string codigo) {
  return "enter_server NÃO IMPLEMENTADO";
}

string Sistema::leave_server() {
  return "leave_server NÃO IMPLEMENTADO";
}

string Sistema::list_participants() {
  return "list_participants NÃO IMPLEMENTADO";
}

string Sistema::list_channels() {
  return "list_channels NÃO IMPLEMENTADO";
}

string Sistema::create_channel(const string nome, const string tipo) {
  return "create_channel NÃO IMPLEMENTADO";
}

string Sistema::enter_channel(const string nome) {
  return "enter_channel NÃO IMPLEMENTADO";
}

string Sistema::leave_channel() {
  return "leave_channel NÃO IMPLEMENTADO";
}

string Sistema::send_message(const string mensagem) {
  return "send_message NÃO IMPLEMENTADO";
}

string Sistema::list_messages() {
  return "list_messages NÃO IMPLEMENTADO";
}




/* IMPLEMENTAR MÉTODOS PARA OS COMANDOS RESTANTES */