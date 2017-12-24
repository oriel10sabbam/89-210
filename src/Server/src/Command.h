/*
 * Command.h
 *
 *  Created on: Dec 13, 2017
 *      Author: oriel
 */

#ifndef COMMAND_H_
#define COMMAND_H_
#include <string>
#include <vector>

using namespace std;

class Command {
public:
  Command();
  virtual void execute(vector<string> args) = 0;
  virtual ~Command() {
  }

};

#endif /* COMMAND_H_ */
