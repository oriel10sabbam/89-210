/*
 * StartGameC.h
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#ifndef STARTGAMEC_H_
#define STARTGAMEC_H_
#include "Command.h"
#include "Server.h"
using namespace std;

/*
 * StartGameC is the 'start a new game' command,
 *  this class heir from the command class
 */
class StartGameC: public Command {
public:
  /*
   * constructor of StartGameC
   * @ param server- the server of the game
   */
  StartGameC(map<string, int>* mapGameToClientsocket, Server* server);

  /*
   * desturctor of StartGameC
   */
  virtual ~StartGameC();

  /*
   * execute- the execute of this command
   * @param args- the arguments of this command
   */
  virtual void execute(vector<string> args);
private:

  int setNeweGame(pair<string, int> pairGameSocket);
  map<string, int>* mapGameToClientsocket;
  Server* server;
};

#endif /* STARTGAMEC_H_ */
