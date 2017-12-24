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

ListGamesC::ListGamesC(Server* server) :
    server(server) {

}

ListGamesC::~ListGamesC() {
}

void ListGamesC::execute(vector<string> args) {
  string gamesString;
//  char gamesChar[MAX];
  list < string > listOfGames = server->getListOfGames();
  list<string>::iterator it;
  for (it = listOfGames.begin(); it != listOfGames.end(); ++it) {
    gamesString += (*it);
  }
//  sprintf(gamesChar, "%s", gamesString.c_str());
  // server->sendCharMessage(atoi(args[0].c_str()), gamesChar);
}

