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
using namespace std;

/*
 *
 */
class JoinGameC: public Command {
public:
  JoinGameC(Server* server);
  virtual ~JoinGameC();
  virtual void execute(vector<string> args);
private:
  Server* server;

};

#endif /* JOINGAMEC_H_ */
