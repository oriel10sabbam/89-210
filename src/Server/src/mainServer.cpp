/*
 * mainServer.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: oriel
 */

#ifndef SERVER_MAINSERVER_CPP_
#define SERVER_MAINSERVER_CPP_
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include<fstream>
#include <stdio.h>
#include <stdlib.h>

#include "Server.h"
#include "Command.h"
#include "CloseGameC.h"
#include "JoinGameC.h"
#include "ListGamesC.h"
#include "PlayOneMoveC.h"
#include "StartGameC.h"
using namespace std;

int main() {
  ifstream inFile;

  try {
    inFile.open("./definition_server.txt");
  } catch (const char * msg) {
    cout << "error open the definition_server.txt" << msg << endl;
    exit(-1);
  }

  int port;
  if (inFile.is_open()) {
    inFile >> port;
  } else {
    cout << "error open the definition_server.txt" << endl;
    exit(-1);
  }

  Server server(port);
  map<string, Command*> commandsMap;

  commandsMap["start"] = new StartGameC(&server);
  commandsMap["list_games"] = new ListGamesC(&server);
  commandsMap["join"] = new JoinGameC(&server);
  commandsMap["play"] = new PlayOneMoveC(&server);
  commandsMap["close"] = new CloseGameC(&server);

  CommandsManager commandsManager(commandsMap);

  server.setCommandManager(&commandsManager);

  try {
    server.start();
  } catch (const char * msg) {
    cout << "Cannot start server. Reason: " << msg << endl;
    exit(-1);
  }
}

#endif /* SERVER_MAINSERVER_CPP_ */
