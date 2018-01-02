/*
 * StartGameC.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#include "StartGameC.h"

using namespace std;

pthread_mutex_t map_mutexS;

StartGameC::StartGameC(map<string, int>* mapGameToClientsocket, Server* server) :
    mapGameToClientsocket(mapGameToClientsocket), server(server) {

}

StartGameC::~StartGameC() {
}
void StartGameC::execute(vector<string> args) {

  pair<string, int> pairGame;
  int clientsocket = atoi(args[2].c_str());
  pairGame.first = args[1];
  pairGame.second = clientsocket;
  int result = setNeweGame(pairGame);
  if (result == 1) {
    server->sendMessage(clientsocket, result);
  } else {
    server->sendMessage(clientsocket, result);
    server->serverHandleClient(clientsocket);
  }
}
int StartGameC::setNeweGame(pair<string, int> pairGameSocket) {
  pthread_mutex_lock (&map_mutexS);
  map<string, int>::iterator it = mapGameToClientsocket->find(
      pairGameSocket.first);
  pthread_mutex_unlock(&map_mutexS);

  if (it == mapGameToClientsocket->end()) {

    pthread_mutex_lock(&map_mutexS);
    (mapGameToClientsocket)->insert(pairGameSocket);
    pthread_mutex_unlock(&map_mutexS);
    return 1;
  } else {
    return -1;
  }
}
