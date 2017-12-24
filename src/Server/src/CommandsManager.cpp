/*
 * CommandsManager.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: oriel
 */

#include "CommandsManager.h"

using namespace std;

CommandsManager::CommandsManager(map<string, Command*> commandsMap) :
    commandsMap(commandsMap) {
}

CommandsManager::~CommandsManager() {
}

void CommandsManager::executeCommand(string command, vector<string> args) {

  Command * commandObj = commandsMap[command];
  commandObj->execute(args);
}

