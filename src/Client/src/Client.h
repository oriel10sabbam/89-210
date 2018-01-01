/*
 * Cliect.h
 *
 *  Created on: Dec 4, 2017
 *      Author: oriel
 */

#ifndef CLIENT_H_
#define CLIENT_H_
#include <string>
#include <string.h>
using namespace std;
/*
 * this class represent the Client, the goal of this class
 * is to Communicate with the server
 */

class Client {
public:
  /*
   *  constructor of Client
   * @ param serverIP- the server IP
   * @ param serverPort- serverPort
   */
  Client(const char * serverIP, int serverPort);

  /*
   * connectToServer- this method connect to the server
   */
  void connectToServer();

  /*
   * getCharMessage- return a Char Message
   */
  char getCharMessage();

  void sendCharMessage(string message/*[]*/);
  /*
   * getMessage- get Message from the server
   * return- the int message
   */
  int getMessage();

  /*
   * sendMessage- send Message to the server
   */
  void sendMessage(int Message);

private:
  const char * serverIP;
  int serverPort;
  int clientSocket;
};

#endif /* CLIENT_H_ */
