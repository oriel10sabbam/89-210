/*
 * CloseGameC.h
 *
 *  Created on: Dec 19, 2017
 *      Author: oriel
 */

#ifndef CLOSEGAMEC_H_
#define CLOSEGAMEC_H_
#include "Command.h"
#include "Server.h"
using namespace std;

/*
 * CloseGameC is the close command, this class heir from the command class
 */
class CloseGameC: public Command {
public:
  /*
   * constructor of CloseGameC
   * @ param server- the server of the game
   */
  CloseGameC(Server* server);

  /*
   * desturctor of CloseGameC
   */
  virtual ~CloseGameC();

  /*
   * execute- the execute of this command
   * @param args- the arguments of this command
   */
  virtual void execute(vector<string> args);
private:
  Server* server;
};

#endif /* CLOSEGAMEC_H_ */
