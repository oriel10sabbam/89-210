/*
 * StartGameC.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#include "StartGameC.h"

using namespace std;

StartGameC::StartGameC(Server* server) :
    server(server) {

}

StartGameC::~StartGameC() {
}

void StartGameC::execute(vector<string> args) {
  //server->startNewGame(args[0]);
}

