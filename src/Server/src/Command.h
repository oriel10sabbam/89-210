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
#include<pthread.h>

using namespace std;
/*
 * Command is the abstract class of the all specific commands
 */
class Command {
public:
  /*
   * constructor of Command
   */
  Command();
  /*
   * execute- the method that the all specific commands will do
   * @param args- the arguments of the command
   */
  virtual void execute(vector<string> args) = 0;

  /*
   * desturctor of Command
   */
  virtual ~Command() {
  }

};

#endif /* COMMAND_H_ */
