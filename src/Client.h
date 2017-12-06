/*
 * Cliect.h
 *
 *  Created on: Dec 4, 2017
 *      Author: oriel
 */

#ifndef CLIENT_H_
#define CLIENT_H_
class Client {
public:
  Client(const char * serverIP, int serverPort);
  int connectToServer();
  int getMessage();
  void sendMessage(int Message);

private:
  const char * serverIP;
  int serverPort;
  int clientSocket;
};

#endif /* CLIENT_H_ */
