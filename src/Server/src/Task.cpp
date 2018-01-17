/*
 * Task.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: oriel
 */

/*
 *  this class represent a Task.
 */

class Task {
public:

  /*
   * the constructor of Task
   * @param (*func)- a pointer to function.
   * @param arg- the agruments to the function
   */
  Task(void * (*func)(void * arg), void * arg) :
      func(func), arg(arg) {
  }

  /*
   * execute - execute the function
   */
  void execute() {
    func(arg);
  }

  /*
   * the destructor of Task
   */
  virtual ~Task() {
  }

private:
  void* (*func)(void * arg);
  void * arg;
};
