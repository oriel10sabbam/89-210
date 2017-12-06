/*
 * Server.h
 *
 *  Created on: Nov 29, 2017
 *      Author: oriel
 */

#ifndef SERVER_SERVER_H_
#define SERVER_SERVER_H_
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#define MAX 256

using namespace std;

class Server {
public:

  Server(int port);
  void start();
  void stop();

private:

  int port;
  int serverSocket;
  // the socket's file descriptor
  void startTheGame(int clientSocket1, int clientSocket2);
  void getMessage(int clientSocket, int& message);
  void sendMessege(int clientSocket, int& message);
};

#endif /* SERVER_SERVER_H_ */

