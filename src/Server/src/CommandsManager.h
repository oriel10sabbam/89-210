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
 * CommandsManager is the Commands Manager class, it's
 *  hold the all specific commands, and runs the relevant command
 */
class CommandsManager {
public:
  /*
   * consturctor of CommandManager
   * @param commandMap- a map from the name of the command (a string)
   * to a specific command
   */
  CommandsManager(map<string, Command*>& commandsMap);

  /*
   * desturctor of CommandManager
   */
  virtual ~CommandsManager();

  /*
   * executeCommand- execute a specific Command by the name (the key)
   * @param command- the name of the command (the key)
   * @param args- the arguments of the specific command
   */
  void executeCommand(string command, vector<string> args);

  /*
   * deleteItems- delete the Items in CommandsManager
   */
  void deleteItems();

private:
  map<string, Command*>& commandsMap;
};

#endif /* COMMANDSMANAGER_H_ */
