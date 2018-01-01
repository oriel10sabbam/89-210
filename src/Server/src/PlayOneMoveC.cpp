/*
 * PlayOneMove.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#include "PlayOneMoveC.h"
#include "Server.h"
#include <stdlib.h>

using namespace std;

PlayOneMoveC::PlayOneMoveC(Server* server) :
    server(server) {
}

PlayOneMoveC::~PlayOneMoveC() {

}

void PlayOneMoveC::execute(vector<string> args) {

  string oneMoveString = args[1] + " " + args[2];
  server->sendCharMessage(atoi(args[4].c_str()), oneMoveString);

}
