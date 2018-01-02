/*
 * JoinGameC.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#include "JoinGameC.h"
#include <map>

using namespace std;
pthread_mutex_t map_mutexJ;

JoinGameC::JoinGameC(map<string, int>* mapGameToClientsocket, Server* server) :
    mapGameToClientsocket(mapGameToClientsocket), server(server) {

}

JoinGameC::~JoinGameC() {
}
void JoinGameC::execute(vector<string> args) {

  string nameOfThefGame = args[1];
  bool theGameExists = isGameInMap(nameOfThefGame);
  int clientsocket2 = atoi(args[2].c_str());

  int message;
  if (theGameExists) {
    message = 1;

    server->sendMessage(clientsocket2, message);

    int clientsocket1 = returnSocketFromMap(nameOfThefGame);

    removeValueFromMap(nameOfThefGame);

    CommandsManager* commandsManager = server->getCommandsManager();

    GameManager gameManager(commandsManager);
    gameManager.startGame(clientsocket1, clientsocket2);

  } else {
    message = -1;
    server->sendMessage(clientsocket2, message);
    server->serverHandleClient(clientsocket2);
  }
}
int JoinGameC::returnSocketFromMap(string key) {

  pthread_mutex_lock (&map_mutexJ);
  int clientsocket = mapGameToClientsocket->operator [](key);
  pthread_mutex_unlock(&map_mutexJ);
  return clientsocket;
}
void JoinGameC::removeValueFromMap(string key) {
  pthread_mutex_lock (&map_mutexJ);
  mapGameToClientsocket->erase(key);
  pthread_mutex_unlock(&map_mutexJ);
}
bool JoinGameC::isGameInMap(string game) {
  pthread_mutex_lock (&map_mutexJ);
  map<string, int>::iterator it = mapGameToClientsocket->find(game);
  if (it != mapGameToClientsocket->end()) {
    pthread_mutex_unlock(&map_mutexJ);
    return true;
  }
  pthread_mutex_unlock(&map_mutexJ);
  return false;
}

