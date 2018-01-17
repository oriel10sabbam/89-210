/*
 * CloseGameC.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#include "CloseGameC.h"
#include <stdio.h>
#include<pthread.h>
#include<cstdlib>

using namespace std;

CloseGameC::CloseGameC(Server* server) :
    server(server) {
}

CloseGameC::~CloseGameC() {
}

void CloseGameC::execute(vector<string> args) {
  int clientsocketFirst = atoi(args[1].c_str());
  int clientsocketSecond = atoi(args[2].c_str());
  server->closeClients(clientsocketFirst, clientsocketSecond);
}
