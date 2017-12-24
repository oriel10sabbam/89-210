/*
 * Server.h
 *
 *  Created on: Nov 29, 2017
 *      Author: oriel
 */
#include <string>
#include <list>
#include <vector>

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
#include "CommandsManager.h"
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

  list<string> getListOfGames();

  /*
   *  getCharMessage- get Message from a clientSocket
   *  @ param clientSocket- the Socket of a client
   *  @ param message- the message to get from the socket
   */
  void getCharMessage(int clientSocket, string message);

  /*
   *  sendCharMessage- send Message to a clientSocket
   *  @ param clientSocket- the Socket of a client
   *  @ param message- the message to send the socket
   */
  void sendCharMessage(int clientSocket, string message);

  /*
   *  startNewGame- start a New Game
   *  @ param newGame- the new Game
   */
  void startNewGame(string newGame);

  /*
   *  joinGame- join to Game
   *  @ param game- the game to join
   */
  void joinGame(string game);

  /*
   *  closeGame- close a Game
   *  @ param game- the Game to close
   */
  void closeGame(string game);

  /*
   *  setCommandManager- set Command Manager
   *  @ param commandsManagerToSet- the commands Manager
   */
  void setCommandManager(CommandsManager* commandsManagerToSet);

  /*
   * splitBySpace- split a string by space
   *  @ param str- the string to split
   *  @ param clientsocket- the client socket fp.
   *  @ return vector of args
   *
   */
  vector<string> splitBySpace(string str, int clientsocket);

private:

  int port;
  int serverSocket;
  list<string> listOfGames;
  CommandsManager* commandsManager;

  /*
   *  startTheGame- start to get and sent the messages (the messages are
   *  two int values that represent a position on the board.)
   *  @ param clientSocket1- the Socket of client1
   *  @ param clientSocket2- the Socket of client2
   */
  void startTheGame(int clientSocket1, int clientSocket2);

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
   *  clientClosed- check if the client Closed
   *  @ param clientSocket- the Socket of a client
   *  @ return true if the client Closed
   */
  bool clientClosed(int clientSocket);

};

#endif /* SERVER_H_ */

