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
 *
 */
class PlayOneMoveC: public Command {
public:
  PlayOneMoveC(Server* server);
  virtual ~PlayOneMoveC();
  virtual void execute(vector<string> args);
private:
  Server* server;

};

#endif /* PLAYONEMOVEC_H_ */
