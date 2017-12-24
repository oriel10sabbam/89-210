/*
 * CommandsManager.h
 *
 *  Created on: Dec 13, 2017
 *      Author: oriel
 */

#ifndef COMMANDSMANAGER_H_
#define COMMANDSMANAGER_H_
#include <map>
#include "Command.h"
using namespace std;

/*
 *
 */
class CommandsManager {
public:
  CommandsManager(map<string, Command*> commandsMap);
  virtual ~CommandsManager();
  void executeCommand(string command, vector<string> args);
private:
  map<string, Command*> commandsMap;
};

#endif /* COMMANDSMANAGER_H_ */
