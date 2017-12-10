/*
 * Server.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: oriel
 */

#include "Server.h"
using namespace std;
#define MAX_CONNECTED_CLIENTS 10

Server::Server(int port) :
    port(port), serverSocket(0) {
  cout << "Server" << endl;
}

void Server::start() {
  // Create a socket point
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    throw "Error opening socket";
  }
  // Assign a local address to the socket
  struct sockaddr_in serverAddress;
  bzero((void *) &serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(port);
  if (bind(serverSocket, (struct sockaddr *) &serverAddress,
      sizeof(serverAddress)) == -1) {
    throw "Error on binding";
  }
  // Start listening to incoming connections
  listen(serverSocket, MAX_CONNECTED_CLIENTS);

  // Define the clients socket's structures
  struct sockaddr_in clientAddress1;
  struct sockaddr_in clientAddress2;
  socklen_t clientAddressLen1 = sizeof((struct sockaddr*) &clientAddress1);
  socklen_t clientAddressLen2 = sizeof((struct sockaddr*) &clientAddress2);
  while (true) {
    cout << "Waiting for client1 connections..." << endl;
    // Accept a new client connection
    int clientSocket1 = accept(serverSocket,
        (struct sockaddr *) &clientAddress1, &clientAddressLen1);

    if (clientSocket1 == -1)
      throw "Error on accept clientSocket1";

    cout << "Client1 connected" << endl;

    int clientSocket2 = accept(serverSocket,
        (struct sockaddr *) &clientAddress2, &clientAddressLen2);

    if (clientSocket2 == -1)
      throw "Error on accept clientSocket2";

    cout << "Client2 connected" << endl;

    int n;
    int message = 1;
    n = write(clientSocket1, &message, sizeof(message));
    if (n == -1) {
      throw "Error writing to clientSocket1";
      cout << "Error writing to clientSocket1" << endl;
    }
    cout << "Success writing to clientSocket1" << endl;

    message = 2;
    n = write(clientSocket2, &message, sizeof(message));
    if (n == -1) {
      throw "Error writing to clientSocket2";
      cout << "Error writing to clientSocket2" << endl;
    }
    cout << "Success writing to clientSocket2" << endl;

    startTheGame(clientSocket1, clientSocket2);
    // Close communication with the clients
    close(clientSocket1);
    close(clientSocket2);
  }
}

// start The Game
void Server::startTheGame(int clientSocket1, int clientSocket2) {
  int message;

  do {
    //get two message for X and Y of point from clientSocket1
    for (int i = 0; i < 2; i++) {

      getMessage(clientSocket1, message);
      //if we get -2 it is mean End of game so we do not need
      //to continue get the other message
      if (message == -2) {
        cout << "clientSocket1 end the game \n";
        break;
      }

      if (clientClosed(clientSocket1) || clientClosed(clientSocket2)) {
        // if message == -10 then we know that one of the
        // client Sockets is close, we send -10 to the other socket
        // to tell him that the other socket is closed
        message = -10;
        sendMessage(clientSocket2, message);
        cout << "one of the client Sockets is close \n";
        break;
      }
      sendMessage(clientSocket2, message);
      //if we get -1 it is mean NoMove so we do not need
      //to continue get the other message
      if (message == -1) {
        break;
      }
    }
    // if we get -2 or -10 it is mean End of game (or one of the players is
    // closed) so we need to stop the game
    if ((message == -2) || (message == -10)) {
      break;
    }

    for (int i = 0; i < 2; i++) {

      getMessage(clientSocket2, message);
      if (message == -2) {
        cout << "clientSocket2 end the game \n";
        break;
      }

      if (clientClosed(clientSocket1) || clientClosed(clientSocket2)) {
        // if message == -10 then we know that one of the
        // client Sockets is close
        message = -10;
        sendMessage(clientSocket1, message);
        cout << "one of the client Sockets is close \n";
        break;
      }
      sendMessage(clientSocket1, message);
      if (message == -1) {
        break;
      }
    }
    if ((message == -2) || (message == -10)) {
      break;
    }

  } while (true);
}

void Server::getMessage(int clientSocket, int& message) {
  int n = read(clientSocket, &message, sizeof(message));
  if (n == -1) {
    throw "Error reading message\n";
  }
}
void Server::sendMessage(int clientSocket, int& message) {
  int n = write(clientSocket, &message, sizeof(message));
  if (n == -1) {
    throw "Error writing to socket\n";
  }
}

bool Server::clientClosed(int clientSocket) {
  pollfd poFD;
  poFD.fd = clientSocket;
  poFD.events = POLLIN | POLLHUP | POLLRDNORM;
  poFD.revents = 0;
  if (poll(&poFD, 1, 100) > 0) {
    char buf[32];
    if (recv(clientSocket, buf, sizeof(buf), MSG_PEEK | MSG_DONTWAIT) == 0) {
      return true;
    }
  }
  return false;
}

void Server::stop() {
  close (serverSocket);
}
