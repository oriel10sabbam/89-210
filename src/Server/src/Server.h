/*
 * Server.h
 *
 *  Created on: Nov 29, 2017
 *      Author: oriel
 */

#ifndef SERVER_H_
#define SERVER_H_
#include<netinet/in.h>
#include<arpa/inet.h>
#include<netdb.h>

#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <iostream>
#include <stdio.h>
#include <poll.h>

#include <string>
#include <list>
#include <vector>
#include <map>
#include <algorithm>

#include<pthread.h>
#include<cstdlib>
#include "CommandsManager.h"
#include "GameManager.h"
using namespace std;

/*
 *  this class represent the Server.
 */
class Server {
  friend class ListGames;
public:

  /*
   *  constructor of Server
   *  @ param port- the port number to listening to clients
   */
  Server(int port);

  /*
   * start- start to listening and serving clients
   */
  void start();

  /*
   * stop- stop to listening and serving clients
   */
  void stop();

  /*
   *  sendCharMessage- send Message to a clientSocket
   *  @ param clientSocket- the Socket of a client
   *  @ param message- the message to send the socket
   */
  void sendCharMessage(int clientSocket, string message);

  /*
   *  setCommandManager- set Command Manager
   *  @ param commandsManagerToSet- the commands Manager
   */
  void setCommandManager(CommandsManager* commandsManagerToSet);

  /*
   * splitBySpace- split a string by space
   *  @ param str- the string to split
   *  @ param clientsocket- the client socket fp.
   *  @ param otherClientsocket- the other client socket fp.
   *  @ return vector of args
   *
   */
  vector<string> splitBySpace(string str, int clientsocket,
      int otherClientsocket = 0);

  /*
   * serverAcceptClient- the server Accept Client method
   *  @ param tArgs- the the arguments to accept new client
   */
  void serverAcceptClient(void * tArgs);

  /*
   * serverHandleClient- handle one Client
   *  @ param clientsocket- the client socket
   */
  void serverHandleClient(int clientsocket);

  /*
   *  getMessage- get Message from a clientSocket
   *  @ param clientSocket- the Socket of a client
   *  @ param message- the message to get from the socket
   */
  void getMessage(int clientSocket, int& message);

  /*
   *  sendMessege- send Message to a clientSocket
   *  @ param clientSocket- the Socket of a client
   *  @ param message- the message to send the socket
   */
  void sendMessage(int clientSocket, int& message);

  /*
   * closeClient- close the clientsockets and exit the thread
   *  @ param clientSocket1- the clientSocket to close
   *  @ param clientSocket2- the clientSocket to close
   */
  void closeClients(int clientSocket1, int clientSocket2);

  /*
   * getCommandsManager- return pointer to CommandsManager
   */
  CommandsManager* getCommandsManager();

private:

  /*
   * waitForExit- wait For the string 'exit' from the user
   */
  void waitForExit();

  int port;
  int serverSocket;
  vector<pthread_t> vectorOfThread;
  vector<int> vectorOfSocket;
  CommandsManager* commandsManager;

};

#endif /* SERVER_H_ */

