/*
 * Server.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: oriel
 */

#include "Server.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <errno.h>
using namespace std;

#define MAX_CONNECTED_CLIENTS 10
const long int MAX = 2;

Server::Server(int port) :
    port(port), serverSocket(0), commandsManager(NULL) {
  listOfGames.clear();
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
//    char message[MAX];
//    sprintf(message, "%d", 1);
    n = write(clientSocket1, &message, sizeof(message));
    if (n == -1) {
      throw "Error writing to clientSocket1";
      cout << "Error writing to clientSocket1" << endl;
    }
    cout << "Success writing to clientSocket1" << endl;

//    sprintf(message, "%d", 2);
    message = 2;
    n = write(clientSocket2, &message, sizeof(message));
    if (n == -1) {
      throw "Error writing to clientSocket2";
      cout << "Error writing to clientSocket2" << endl;
    }
    cout << "Success writing to clientSocket2" << endl;

    /*   n = read(clientSocket1, &message, sizeof(message));
     if (n == -1) {
     throw strcat("Error read to socket\n", strerror(errno));
     }
     cout << "read from clientSocket1 the message: " << message << endl;

     cout << "Success writing to clientSocket2. size:"
     << sizeof(message) / sizeof(message[0]) << endl;
     n = write(clientSocket2, &message, sizeof(message) / sizeof(message[0]));
     if (n == -1) {
     throw strcat("Error writing to socket\n", strerror(errno));
     }

     cout << "Success read to clientSocket2. size:"
     << sizeof(message) / sizeof(message[0]) << endl;
     n = read(clientSocket2, &message, sizeof(message) / sizeof(message[0]));
     if (n == -1) {
     throw strcat("Error read to socket\n", strerror(errno));
     }
     cout << "read from clientSocket2 the message: " << message << endl;

     cout << "Success writing to clientSocket1. size:"
     << sizeof(message) / sizeof(message[0]) << endl;
     n = write(clientSocket1, &message, sizeof(message) / sizeof(message[0]));
     if (n == -1) {
     throw strcat("Error writing to socket\n", strerror(errno));
     }
     */

    startTheGame(clientSocket1, clientSocket2);
    // Close communication with the clients
    close(clientSocket1);
    close(clientSocket2);
  }
}

// start The Game
void Server::startTheGame(int clientSocket1, int clientSocket2) {
  //int message;
  string message; //[MAX] = "";
  char m;
  int num = 0;

  do {

    int n = read(clientSocket1, &num, sizeof(num));
    if (n == -1) {
      throw "Error writing to socket\n";
    }

    int j = 0;
    message = "";
    while (j < num) {

      int n = read(clientSocket1, &m, sizeof(m));
      if (n == -1) {
        throw "Error writing to socket\n";
      }
      message = message + m;
      j++;

    }

    vector < string > args = splitBySpace(message, clientSocket2);
    commandsManager->executeCommand(args[0], args);

    n = read(clientSocket2, &num, sizeof(num));
    if (n == -1) {
      throw "Error writing to socket\n";
    }

    j = 0;
    message = "";
    while (j < num) {

      int n = read(clientSocket2, &m, sizeof(m));
      if (n == -1) {
        throw "Error writing to socket\n";
      }
      message = message + m;
      j++;

    }

    args = splitBySpace(message, clientSocket1);
    commandsManager->executeCommand(args[0], args);

    /*
     //get two message for X and Y of point from clientSocket1
     for (int i = 0; i < 2; i++) {

     int n = read(clientSocket1, &num, sizeof(num));
     if (n == -1) {
     throw "Error writing to socket\n";
     }

     int j = 0;
     message = "";
     while (j < num) {

     int n = read(clientSocket1, &m, sizeof(m));
     if (n == -1) {
     throw "Error writing to socket\n";
     }
     message = message + m;
     j++;

     }

     cout << "read from clientSocket1 the message: " << message
     << " END OF MESSAGE" << endl;

     if (message.compare("End") == 0) {
     break;
     }

     //if we get "End" it is mean End of game so we do not need
     //to continue get the other message

     if (clientClosed(clientSocket1) || clientClosed(clientSocket2)) {
     // if message == "clientClosed" then we know that one of the
     // client Sockets is close, we send -10 to the other socket
     // to tell him that the other socket is closed
     message = "clientClosed";
     n = write(clientSocket2, &message, MAX);
     if (n == -1) {
     throw "Error writing to socket\n";
     }

     cout << "one of the client Sockets is close \n";
     break;
     }

     n = write(clientSocket2, &num, sizeof(num));
     if (n == -1) {
     throw "Error writing to socket\n";
     }

     j = 0;
     while (j < num) {

     m = message[j];
     int n = write(clientSocket2, &m, sizeof(m));
     if (n == -1) {
     throw "Error writing to socket\n";
     }
     j++;

     }

     cout << "write to clientSocket2 the message: " << message
     << " END OF MESSAGE" << endl;

     if (message.compare("NoMove") == 0) {
     break;
     }

     }

     if ((message.compare("clientClosed") == 0)
     || (message.compare("End") == 0)) {
     break;
     }

     for (int i = 0; i < 2; i++) {

     int n = read(clientSocket2, &num, sizeof(num));
     if (n == -1) {
     throw "Error writing to socket\n";
     }

     int j = 0;
     message = "";
     while (j < num) {

     int n = read(clientSocket2, &m, sizeof(m));
     if (n == -1) {
     throw "Error writing to socket\n";
     }
     message = message + m;
     j++;

     }

     cout << "read from clientSocket2 the message: " << message
     << " END OF MESSAGE" << endl;

     if (message.compare("End") == 0) {
     break;
     }

     //if we get "End" it is mean End of game so we do not need
     //to continue get the other message

     if (clientClosed(clientSocket1) || clientClosed(clientSocket2)) {
     // if message == "clientClosed" then we know that one of the
     // client Sockets is close, we send -10 to the other socket
     // to tell him that the other socket is closed

     n = write(clientSocket1, &message, MAX);
     if (n == -1) {
     throw "Error writing to socket\n";
     }

     cout << "one of the client Sockets is close \n";
     break;
     }

     n = write(clientSocket1, &num, sizeof(num));
     if (n == -1) {
     throw "Error writing to socket\n";
     }

     j = 0;
     while (j < num) {

     m = message[j];
     int n = write(clientSocket1, &m, sizeof(m));
     if (n == -1) {
     throw "Error writing to socket\n";
     }
     j++;

     }

     cout << "write to clientSocket1 the message: " << message
     << " END OF MESSAGE" << endl;

     if (message.compare("NoMove") == 0) {
     break;
     }

     /*




     int n = read(clientSocket2, &message, MAX);
     if (n == -1) {
     throw "Error writing to socket\n";
     }

     cout << "read from clientSocket2 the message: " << message << endl;


     if (clientClosed(clientSocket1) || clientClosed(clientSocket2)) {
     // if message == "clientClosed" then we know that one of the
     // client Sockets is close, we send -10 to the other socket
     // to tell him that the other socket is closed

     n = read(clientSocket1, &message, MAX);
     if (n == -1) {
     throw "Error writing to socket\n";
     }

     cout << "one of the client Sockets is close \n";
     break;
     }

     n = write(clientSocket1, &message, MAX);
     if (n == -1) {
     throw "Error writing to socket\n";
     }



     if (strcmp(message, "NoMove") == 0) {
     break;
     }
     }
     if ((message.compare("clientClosed") == 0)
     || (message.compare("End") == 0)) {
     break;
     }
     */
  } while (true);
}

vector<string> Server::splitBySpace(string str, int clientsocket) {
//  vector < string > args;
//  args.clear();

  std::istringstream buf(str);
  std::istream_iterator<std::string> beg(buf), end;

  std::vector < std::string > args(beg, end); // done!

  std::stringstream numS;
  numS << clientsocket;

  args.push_back(numS.str());

  for (vector<string>::iterator it = args.begin(); it != args.end(); it++) {
    std::cout << '"' << *it << '"' << '\n';
  }

  return args;
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

list<string> Server::getListOfGames() {
  return listOfGames;
}

void Server::getCharMessage(int clientSocket, string message) {

  int n = read(clientSocket, &message, sizeof(message));
  if (n == -1) {
    throw "Error writing to socket\n";
  }
}

void Server::sendCharMessage(int clientSocket, string message) {

  int num = message.length();

  int n = write(clientSocket, &num, sizeof(num));
  if (n == -1) {
    throw "Error writing to socket\n";
  }

  int j = 0;
  while (j < num) {

    char m = message[j];
    int n = write(clientSocket, &m, sizeof(m));
    if (n == -1) {
      throw "Error writing to socket\n";
    }
    j++;

  }

  cout << "write to clientSocket the message: " << message << " END OF MESSAGE"
      << endl;
}

void Server::setCommandManager(CommandsManager* commandsManagerToSet) {
  commandsManager = commandsManagerToSet;
}

void Server::stop() {
  close (serverSocket);
}
