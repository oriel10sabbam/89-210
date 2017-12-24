/*
 * CloseGameC.cpp
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#include "CloseGameC.h"

using namespace std;

CloseGameC::CloseGameC(Server* server) :
    server(server) {

}

CloseGameC::~CloseGameC() {
}

void CloseGameC::execute(vector<string> args) {
  //server->closeGame(args[0]);
}
