#include "executor.h"
#include <istream>
#include <ostream>
#include <iostream>
#include <sstream>
#include <queue>

using namespace std;

/** Function responsible for reading a line to the end
 * 
 * @param istringstream
 * @return string
 */
string restoDe(istringstream &ss) {
  string resto;
  getline(ss, resto, '\0'); // ler o resto da linha
  if (resto != "" && (resto[0] == ' ' || resto[0] == '\t')) {
    resto = resto.substr(1); // o primeiro caractere é um espaço, descartar
  }
  return resto;
}

/** Builder that receives the reference for the system
 * 
 * @param System
 * @return Executor
 */
Executor::Executor(System &system) {
  this->exit = false;
  this->system = &system;
}

/** Function responsible for starting to read the command
 * 
 * @param istream
 * @param ostream
 * @return
 */
void Executor::start(istream &inputStream, ostream &outputStream) {
  string line, output;
  this->exit = false;
  while (! this->exit)
  {
    if (std::getline(inputStream, line)) {
      output = processLine(line);
      outputStream << output << endl;
    }
  }
}

/** Method responsible for processing the command
 * 
 * @param string
 * @return string
 */
string Executor::processLine(string line) {
  istringstream buf(line);
  string commandName;
  buf >> commandName;

  if (commandName.empty()) {
    return "Invalid command <empty>";
  }

  if (commandName == "quit" ) {
    this->exit = true;
    return system->quit();
  }

  else if (commandName == "create-user") {
    string email, password, name;
    buf >> email;
    buf >> password;
    name = restoDe(buf);
    return system->create_user(email, password, name);
  }

  else if (commandName == "login") {
    string email, password;
    buf >> email;
    buf >> password;
    return system->login(email, password);
  }

  else if (commandName == "disconnect") {
    return system->disconnect();
  }

  else if (commandName == "create-server") {
    string name;
    buf >> name;
    return system->create_server(name);
  }

  else if (commandName == "set-server-desc") {
    string name, description;
    buf >> name;
    description = restoDe(buf);;
    return system->set_server_desc(name, description);
  }

  else if (commandName == "set-server-invite-code") {
    string name, code;
    buf >> name;
    buf >> code;
    return system->set_server_invite_code(name, code);
  }

  else if (commandName == "list-servers") {
    return system->list_servers();
  }

  else if (commandName == "remove-server") {
    string name;
    buf >> name;
    return system->remove_server(name);
  }

  else if (commandName == "enter-server") {
    string name, code;
    buf >> name;
    buf >> code;
    return system->enter_server(name, code);
  }

  else if (commandName == "leave-server") {
    return system->leave_server();
  }

  else if (commandName == "list-participants") {
    return system->list_participants();
  }

  else if (commandName == "list-channels") {
    return system->list_channels();
  }

  else if (commandName == "create-channel") {
    string name, type;
    buf >> name;
    buf >> type;
    return system->create_channel(name, type);
  }

  else if (commandName == "enter-channel") {
    string name;
    buf >> name;
    return system->enter_channel(name);
  }

  else if (commandName == "leave-channel") {
    return system->leave_channel();
  }
  
  else if (commandName == "send-message") {
    string message;
    message = restoDe(buf);
    return system->send_message(message);
  }
  
  else if (commandName == "list-messages") {
    return system->list_messages();
  }

  else {
    return "Command not recognized [" + commandName + "]";
  }
}



