/*
 * JoinGameC.h
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#ifndef JOINGAMEC_H_
#define JOINGAMEC_H_
#include "Command.h"
#include "Server.h"
#include "GameManager.h"
#include "CommandsManager.h"
using namespace std;

/*
 * JoinGameC is the 'join to a game' command,
 *  this class heir from the command class
 */
class JoinGameC: public Command {
public:
  /*
   * constructor of JoinGameC
   * @ param server- the server of the game
   */
  JoinGameC(map<string, int>* mapGameToClientsocket, Server* server);

  /*
   * desturctor of CloseGameC
   */
  virtual ~JoinGameC();

  /*
   * execute- the execute of this command
   * @param args- the arguments of this command
   */
  virtual void execute(vector<string> args);
private:

  /*
   *  isGameInMap- return true if  Game In Map
   *  @ param game- the name of game
   */
  bool isGameInMap(string game);

  /*
   *  removeValueFromMap- remove a Value From Map
   *  @ param key- the key of value to remove
   */
  void removeValueFromMap(string key);

  /*
   *  returnSocketFromMap- return the Socket From Map
   *  @ param key- the key of value to remove
   */
  int returnSocketFromMap(string key);

  map<string, int>* mapGameToClientsocket;
  Server* server;

};

#endif /* JOINGAMEC_H_ */
