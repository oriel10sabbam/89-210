/*
 * JoinGameC.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#include "JoinGameC.h"

using namespace std;

JoinGameC::JoinGameC(Server* server) :
    server(server) {

}

JoinGameC::~JoinGameC() {
}

void JoinGameC::execute(vector<string> args) {
  //server->joinGame(args[0]);
}

