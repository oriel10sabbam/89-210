/*
 * mainServer.cpp
 *
 *  Created on: Dec 3, 2017
 *      Author: oriel
 */

#ifndef SERVER_MAINSERVER_CPP_
#define SERVER_MAINSERVER_CPP_
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include "Server.h"
#include <stdlib.h>
using namespace std;
int main() {
  Server server(10008);
  try {
    server.start();
  } catch (const char * msg) {
    cout << "Cannot start server. Reason: " << msg << endl;
    exit(-1);
  }
}

#endif /* SERVER_MAINSERVER_CPP_ */
