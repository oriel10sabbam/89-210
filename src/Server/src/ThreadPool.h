/*
 * ThreadPool.h
 *
 *  Created on: Jan 16, 2018
 *      Author: oriel
 */

#ifndef THREADPOOL_H_
#define THREADPOOL_H_

#include"Task.cpp"
#include<queue>
#include<pthread.h>
using namespace std;
/*
 *  this class represent the ThreadPool.
 */

class ThreadPool {
public:
  /*
   * the constructor of ThreadPool
   * @param threadsNum- the num of threads that use
   */
  ThreadPool(int threadsNum);

  /*
   * addTask- add Task to the queue.
   * @param task- a task to add
   */
  void addTask(Task* task);

  /*
   * terminate- terminate the ThreadPool
   */
  void terminate();

  /*
   * the destructor of ThreadPool
   */
  virtual ~ThreadPool();
private:

  queue<Task*> tasksQueue;
  pthread_t* threads;
  bool stopped;
  pthread_mutex_t lock;
  /*
   * executeTasks- execute the Tasks
   */
  void executeTasks();

  /*
   * execute- the func that the threads execute.
   */
  static void* execute(void* arg);
};

#endif /* THREADPOOL_H_ */
