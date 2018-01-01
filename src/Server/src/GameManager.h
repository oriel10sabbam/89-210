/*
 * GameManager.h
 *
 *  Created on: Dec 27, 2017
 *      Author: oriel
 */

#ifndef GAMEMANAGER_H_
#define GAMEMANAGER_H_
#include "CommandsManager.h"

#include <unistd.h>
#include <vector>
#include <string>
#include <iostream>
#include <stdio.h>
#include<pthread.h>
#include<cstdlib>

#include <iostream>
#include <sstream>
#include <iterator>

using namespace std;

/*
 * GameManager- this class is the Game Manager of the remote game
 */
class GameManager {
public:
  /*
   * constructor of GameManager
   * @ param commandsManager- a commands Manager
   */
  GameManager(CommandsManager* commandsManager);

  /*
   * destructor of GameManager
   */
  virtual ~GameManager();

  /*
   * startGame- start a game between two clients
   * @param clientsocket1 - the socket of client1
   * @param clientsocket2 - the socket of client2
   */
  void startGame(int clientsocket1, int clientsocket2);

  /*
   * doOneTurn- do One Turn of the game
   * @param clientSocket1 - the socket that we read from
   * @param clientSocket2 - the socket that we send the move
   */
  void doOneTurn(int clientSocket1, int clientSocket2);

private:
  CommandsManager* commandsManager;

  /*
   * splitBySpace- split a string by space
   *  @ param str- the string to split
   *  @ param clientsocket- the client socket fp.
   *  @ return vector of args
   *
   */
  vector<string> splitBySpace(string str, int clientsocket,
      int otherClientsocket = 0);

};

#endif /* GAMEMANAGER_H_ */
