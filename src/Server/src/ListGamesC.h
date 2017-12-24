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
 *
 */
class ListGamesC: public Command {
public:
  ListGamesC(Server* server);
  virtual ~ListGamesC();
  virtual void execute(vector<string> args);
private:
  Server* server;

};
#endif /* LISTGAMESC_H_ */
