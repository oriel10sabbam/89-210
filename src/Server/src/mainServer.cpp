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
#include<fstream>
#include <stdio.h>
#include "Server.h"
#include <stdlib.h>
using namespace std;

int main() {
  ifstream inFile;

  try {
    inFile.open("./definition_server.txt");
  } catch (const char * msg) {
    cout << "error open the definition_server.txt" << msg << endl;
    exit(-1);
  }

  int port;
  if (inFile.is_open()) {
    inFile >> port;
  } else {
    cout << "error open the definition_server.txt" << endl;
    exit(-1);
  }

  Server server(port);
  try {
    server.start();
  } catch (const char * msg) {
    cout << "Cannot start server. Reason: " << msg << endl;
    exit(-1);
  }
}

#endif /* SERVER_MAINSERVER_CPP_ */
