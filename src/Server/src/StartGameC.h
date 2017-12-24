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
 *
 */
class StartGameC: public Command {
public:
  StartGameC(Server* server);
  virtual ~StartGameC();
  virtual void execute(vector<string> args);
private:
  Server* server;
};

#endif /* STARTGAMEC_H_ */
