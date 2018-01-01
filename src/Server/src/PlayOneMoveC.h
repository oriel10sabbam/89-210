/*
 * PlayOneMove.h
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#ifndef PLAYONEMOVEC_H_
#define PLAYONEMOVEC_H_
#include "Command.h"
#include "Server.h"
using namespace std;

/*
 * PlayOneMoveC is the 'play one move' command,
 *  this class heir from the command class
 */
class PlayOneMoveC: public Command {
public:

  /*
   * constructor of PlayOneMoveC
   * @ param server- the server of the game
   */
  PlayOneMoveC(Server* server);

  /*
   * desturctor of PlayOneMoveC
   */
  virtual ~PlayOneMoveC();

  /*
   * execute- the execute of this command
   * @param args- the arguments of this command
   */
  virtual void execute(vector<string> args);
private:
  Server* server;

};

#endif /* PLAYONEMOVEC_H_ */
