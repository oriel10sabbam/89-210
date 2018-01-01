/*
 * ListGamesC.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#include "ListGamesC.h"
#include <stdio.h>
#include <string>
#include <stdlib.h>
using namespace std;

pthread_mutex_t map_mutexL;

ListGamesC::ListGamesC(map<string, int>* mapGameToClientsocket, Server* server) :
    mapGameToClientsocket(mapGameToClientsocket), server(server) {

}

ListGamesC::~ListGamesC() {
}

void ListGamesC::execute(vector<string> args) {
  string gamesString = getStringOfGames();
  int clientsocket = atoi(args[1].c_str());
  server->sendCharMessage(clientsocket, gamesString);
  server->serverHandleClient(clientsocket);
}

string ListGamesC::getStringOfGames() {
  string gamesString = "";
  map<string, int>::iterator it;
  pthread_mutex_lock (&map_mutexL);
  for (it = mapGameToClientsocket->begin(); it != mapGameToClientsocket->end();
      ++it) {
    gamesString += it->first + " ";
  }
  pthread_mutex_unlock(&map_mutexL);

  return gamesString;
}

