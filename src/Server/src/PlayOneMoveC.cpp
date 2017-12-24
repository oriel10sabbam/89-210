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
//  char oneMoveChar[MAX];
  string oneMoveString = args[1] + " " + args[2];
//  sprintf(oneMoveChar, "%s", oneMoveString.c_str());
  server->sendCharMessage(atoi(args[3].c_str()), oneMoveString);

}
