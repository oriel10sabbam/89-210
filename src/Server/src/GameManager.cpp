/*
 * GameManager.cpp
 *
 *  Created on: Dec 27, 2017
 *      Author: oriel
 */

#include "GameManager.h"
using namespace std;

GameManager::GameManager(CommandsManager* commandsManager) :
    commandsManager(commandsManager) {
}
GameManager::~GameManager() {
}
void GameManager::startGame(int clientSocket1, int clientSocket2) {

  int n;
  int firstMessage = 1;

  n = write(clientSocket1, &firstMessage, sizeof(firstMessage));
  if ((n == 0) || (n == -1)) {
    cout << "Error at write to clientSocket1 \n";
    pthread_exit (NULL);
  }
  firstMessage = 2;
  n = write(clientSocket2, &firstMessage, sizeof(firstMessage));
  if ((n == 0) || (n == -1)) {
    cout << "Error at write to clientSocket2 \n";
    pthread_exit (NULL);
  }

  int oneOrTwo = 1;
  do {
    if (oneOrTwo == 1) {
      doOneTurn(clientSocket1, clientSocket2);
    } else {
      doOneTurn(clientSocket2, clientSocket1);
    }
    oneOrTwo = 3 - oneOrTwo;

  } while (true);

}

void GameManager::doOneTurn(int clientSocket1, int clientSocket2) {
  int num;
  string message = "";
  char c;
  vector < string > args;

  int n = read(clientSocket1, &num, sizeof(num));
  if ((n == 0) || (n == -1)) {
    cout << "Error at read from clientSocket1 \n";
    pthread_exit (NULL);
  }

  int j = 0;
  message = "";
  while (j < num) {
    int n = read(clientSocket1, &c, sizeof(c));
    if ((n == 0) || (n == -1)) {
      cout << "Error at read from clientSocket1 \n";
      pthread_exit (NULL);
    }
    message = message + c;
    j++;

  }

  args = splitBySpace(message, clientSocket1, clientSocket2);
  commandsManager->executeCommand(args[0], args);
}
vector<string> GameManager::splitBySpace(string str, int clientsocket,
    int otherClientsocket) {
  istringstream buf(str);
  istream_iterator<string> beg(buf), end;

  vector < string > args(beg, end);
  stringstream numS;
  numS << clientsocket;

  stringstream numOther;
  numOther << otherClientsocket;

  args.push_back(numS.str());
  args.push_back(numOther.str());

  return args;
}
