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
 *
 */
class CloseGameC: public Command {
public:
  CloseGameC(Server* server);
  virtual ~CloseGameC();
  virtual void execute(vector<string> args);
private:
  Server* server;
};

#endif /* CLOSEGAMEC_H_ */
