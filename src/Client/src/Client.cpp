/*
 * Client.cpp
 *
 *  Created on: Dec 4, 2017
 *      Author: oriel
 */

#include "Client.h"
#include<iostream>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include <stdio.h>
#include <stdlib.h>

Client::Client(const char * serverIP, int serverPort) :
    serverIP(serverIP), serverPort(serverPort), clientSocket(0) {
}

char Client::getCharMessage() {
  char result;
  int n = read(clientSocket, &result, sizeof(result));
  if ((n == 0) || (n == -1)) {
    cout << "Error at the server ";
    exit(-1);
  }
  return result;
}

void Client::sendCharMessage(string message) {

  int len = message.length();
  int i = 0;
  char m;
  sendMessage(len);
  while (i < len) {
    m = message[i];
    int n = write(clientSocket, &m, sizeof(m));
    if ((n == 0) || (n == -1)) {
      cout << "Error at the server ";
      exit(-1);
    }

    i++;
  }
}

int Client::getMessage() {
  int result;
  int n = read(clientSocket, &result, sizeof(result));
  if ((n == 0) || (n == -1)) {
    cout << "Error at the server ";
    exit(-1);
  }

  return result;

}

void Client::sendMessage(int message) {

  int n = write(clientSocket, &message, sizeof(message));
  if ((n == 0) || (n == -1)) {
    cout << "Error at the server ";
    exit(-1);
  }

}

void Client::connectToServer() {
// Create a socket point
  clientSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (clientSocket == -1) {
    throw "Error opening socket";
  }
// Convert the ip string to a network address
  struct in_addr address;
  if (!inet_aton(serverIP, &address)) {
    throw "Can't parse IP address";
  }
// Get a hostent structure  for the given host address
  struct hostent *server;
  server = gethostbyaddr((const void *) &address, sizeof address, AF_INET);
  if (server == NULL) {
    throw "Host is unreachable";
  }
// Create a structure for the server address
  struct sockaddr_in serverAddress;
  bzero((char *) &address, sizeof(address));
  serverAddress.sin_family = AF_INET;
  memcpy((char*) &serverAddress.sin_addr.s_addr, (char*) server->h_addr,
      server->h_length);
//htons converts values between host and network byte orders
  serverAddress.sin_port = htons(serverPort);
// Establish a connection with the TCP server
  if (connect(clientSocket, (struct sockaddr *) &serverAddress,
      sizeof(serverAddress)) == -1) {
    throw "Error connecting to server";
  }

}

