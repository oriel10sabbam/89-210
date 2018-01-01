/*
 * CommandsManager.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: oriel
 */

#include "CommandsManager.h"

using namespace std;

CommandsManager::CommandsManager(map<string, Command*>& commandsMap) :
    commandsMap(commandsMap) {
}

CommandsManager::~CommandsManager() {
  map<string, Command *>::iterator it;
  for (it = commandsMap.begin(); it != commandsMap.end(); ++it) {
    delete it->second;
  }
}

void CommandsManager::executeCommand(string command, vector<string> args) {

  Command * commandObj = commandsMap[command];
  commandObj->execute(args);
}

void CommandsManager::deleteItems() {
  map<string, Command *>::iterator it;
  for (it = commandsMap.begin(); it != commandsMap.end(); ++it) {
    delete it->second;
  }

}

