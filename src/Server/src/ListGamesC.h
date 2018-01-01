/*
 * ListGamesC.h
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#ifndef LISTGAMESC_H_
#define LISTGAMESC_H_
#include "Command.h"
#include "Server.h"

using namespace std;

/*
 * ListGamesC is the 'return list of games' command,
 *  this class heir from the command class
 */
class ListGamesC: public Command {
public:
  /*
   * constructor of ListGamesC
   * @ param server- the server of the game
   */
  ListGamesC(map<string, int>* mapGameToClientsocket, Server* server);

  /*
   * desturctor of ListGamesC
   */
  virtual ~ListGamesC();

  /*
   * execute- the execute of this command
   * @param args- the arguments of this command
   */
  virtual void execute(vector<string> args);
private:
  /*
   * getStringOfGames - return string list of games
   */
  string getStringOfGames();

  map<string, int>* mapGameToClientsocket;
  Server* server;

};
#endif /* LISTGAMESC_H_ */
