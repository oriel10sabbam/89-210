/*
 * Server.cpp
 *
 *  Created on: Nov 29, 2017
 *      Author: oriel
 */

#include "Server.h"
#include <iostream>
#include <sstream>
#include <iterator>
#include <errno.h>

pthread_mutex_t vector_thread_mutex;
pthread_mutex_t vector_socket_mutex;

using namespace std;

#define MAX_CONNECTED_CLIENTS 10

struct ArgsThread1 {
  struct sockaddr_in clientAddress;
  socklen_t clientAddressLen;
  Server* server;
};

struct ArgsThread2 {
  int clientsocket;
  Server* server;
};

CommandsManager* Server::getCommandsManager() {
  return commandsManager;
}

void* handleClient(void * tArgs2) {
  struct ArgsThread2 * args = (struct ArgsThread2 *) tArgs2;
  args->server->serverHandleClient(args->clientsocket);
  return NULL;
}

void Server::serverHandleClient(int clientsocket) {

  string message;
  char m;
  int num = 0;

  int n = read(clientsocket, &num, sizeof(num));
  if ((n == 0) || (n == -1)) {
    cout << "Error at read from clientSocket \n";
    pthread_exit (NULL);
  }

  int j = 0;
  message = "";
  while (j < num) {

    int n = read(clientsocket, &m, sizeof(m));
    if ((n == 0) || (n == -1)) {
      cout << "Error at read from clientSocket \n";
      pthread_exit (NULL);
    }
    message = message + m;
    j++;

  }

  vector < string > args = splitBySpace(message, clientsocket);

  commandsManager->executeCommand(args[0], args);
  pthread_mutex_lock (&vector_thread_mutex);

  pthread_t pthreadSelf = pthread_self();

  for (vector<pthread_t>::iterator it = vectorOfThread.begin();
      it != vectorOfThread.end(); ++it) {
    pthread_t pthreadSelfPointer = *it;
    if (pthreadSelfPointer == pthreadSelf) {
      vectorOfThread.erase(it);
      break;
    }
  }
  pthread_mutex_unlock(&vector_thread_mutex);

}

void* acceptClient(void *tArgs) {

  while (true) {
    struct ArgsThread1 * args = (struct ArgsThread1 *) tArgs;
    args->server->serverAcceptClient(tArgs);
  }

}

void Server::serverAcceptClient(void *tArgs) {
  struct ArgsThread1 * args = (struct ArgsThread1 *) tArgs;

  cout << "Waiting for client connections..." << endl;
  int clientSocket = accept(serverSocket,
      (struct sockaddr *) &(args->clientAddress), &(args->clientAddressLen));
  cout << "Client connected" << endl;

  pthread_mutex_lock (&vector_socket_mutex);
  vectorOfSocket.push_back(clientSocket);
  pthread_mutex_unlock(&vector_socket_mutex);

  pthread_t thread;

  ArgsThread2 args2;
  args2.clientsocket = clientSocket;
  args2.server = this;

  int rc2 = pthread_create(&thread, NULL, handleClient, &args2);

  pthread_mutex_lock (&vector_thread_mutex);
  vectorOfThread.insert(vectorOfThread.begin(), thread);
  pthread_mutex_unlock(&vector_thread_mutex);

  if (rc2) {
    cout << "Error: unable to create thread, " << rc2 << endl;
    exit(-1);
  }

}

Server::Server(int port) :
    port(port), serverSocket(0), commandsManager(NULL) {
  vectorOfThread.clear();
  vectorOfSocket.clear();
  cout << "Server" << endl;
}

void Server::start() {
// Create a socket point
  serverSocket = socket(AF_INET, SOCK_STREAM, 0);
  if (serverSocket == -1) {
    throw "Error opening socket";
  }
// Assign a local address to the socket
  struct sockaddr_in serverAddress;
  bzero((void *) &serverAddress, sizeof(serverAddress));
  serverAddress.sin_family = AF_INET;
  serverAddress.sin_addr.s_addr = INADDR_ANY;
  serverAddress.sin_port = htons(port);
  if (bind(serverSocket, (struct sockaddr *) &serverAddress,
      sizeof(serverAddress)) == -1) {
    throw "Error on binding";
  }
// Start listening to incoming connections
  listen(serverSocket, MAX_CONNECTED_CLIENTS);

// Define the clients socket's structures
  ArgsThread1 argsThread;
  argsThread.clientAddressLen =
      sizeof((struct sockaddr*) &(argsThread.clientAddress));
  argsThread.server = this;

  pthread_t threadFirst;
  int rc = pthread_create(&threadFirst, NULL, acceptClient, &argsThread);
  pthread_mutex_lock (&vector_thread_mutex);
  vectorOfThread.push_back(threadFirst);
  pthread_mutex_unlock(&vector_thread_mutex);
  if (rc) {
    cout << "Error: unable to create thread, " << rc << endl;
    exit(-1);
  }

  waitForExit();
}

void Server::waitForExit() {
  cout << "to exit enter the word 'exit'\n";

  while (true) {
    string str;
    cin >> str;
    if (str.compare("exit") == 0) {
      cout << "exit the server " << endl;

      //close the sockets
      pthread_mutex_lock (&vector_socket_mutex);

      for (vector<int>::iterator it = vectorOfSocket.begin();
          it != vectorOfSocket.end();) {
        close(*it);
        it = vectorOfSocket.erase(it);
      }

      pthread_mutex_unlock(&vector_socket_mutex);

      //end the threads
      pthread_mutex_lock (&vector_thread_mutex);

      for (vector<pthread_t>::iterator it = vectorOfThread.begin();
          it != vectorOfThread.end();) {
        pthread_t threadToClose = (*it);
        it = vectorOfThread.erase(it);
        pthread_cancel(threadToClose);
      }
      pthread_mutex_unlock(&vector_thread_mutex);

      break;
    } else {
      cout << "you write a wrong input, please write only 'exit'"
          " for exit the server \n";

    }
  }

}

vector<string> Server::splitBySpace(string str, int clientsocket,
    int otherClientsocket) {
  istringstream buf(str);
  istream_iterator<string> beg(buf), end;

  vector < string > args(beg, end); // done!

  stringstream stringClientsocket;
  stringClientsocket << clientsocket;

  stringstream stringOtherClientsocket;
  stringOtherClientsocket << otherClientsocket;

  args.push_back(stringClientsocket.str());
  args.push_back(stringOtherClientsocket.str());

  return args;
}

void Server::getMessage(int clientSocket, int& message) {
  int n = read(clientSocket, &message, sizeof(message));
  if ((n == 0) || (n == -1)) {
    cout << "Error at read from clientSocket \n";
    pthread_exit (NULL);
  }
}
void Server::sendMessage(int clientSocket, int& message) {
  int n = write(clientSocket, &message, sizeof(message));
  if ((n == 0) || (n == -1)) {
    cout << "Error at write to clientSocket \n";
    pthread_exit (NULL);
  }
}

void Server::sendCharMessage(int clientSocket, string message) {

  int num = message.length();

  int n = write(clientSocket, &num, sizeof(num));
  if ((n == 0) || (n == -1)) {
    cout << "Error at write to clientSocket \n";
    pthread_exit (NULL);
  }

  int j = 0;
  while (j < num) {

    char m = message[j];
    int n = write(clientSocket, &m, sizeof(m));
    if ((n == 0) || (n == -1)) {
      cout << "Error at write to clientSocket \n";
      pthread_exit (NULL);
    }
    j++;

  }
}

void Server::setCommandManager(CommandsManager* commandsManagerToSet) {
  commandsManager = commandsManagerToSet;
}

void Server::stop() {
  close (serverSocket);
}

void Server::closeClients(int clientSocket1, int clientSocket2) {
//remove the socket of the players that finish the game from the vector
  pthread_mutex_lock (&vector_socket_mutex);
  for (vector<int>::iterator it = vectorOfSocket.begin();
      it != vectorOfSocket.end();) {
    if (*it == clientSocket1) {

      it = vectorOfSocket.erase(it);
    } else if (*it == clientSocket2) {

      it = vectorOfSocket.erase(it);

    } else {
      ++it;
    }
  }
  pthread_mutex_unlock(&vector_socket_mutex);

  //remove the current pthread_t from the vector
  pthread_mutex_lock (&vector_thread_mutex);

  pthread_t pthreadSelf = pthread_self();

  for (vector<pthread_t>::iterator it = vectorOfThread.begin();
      it != vectorOfThread.end(); ++it) {
    pthread_t pthreadSelfPointer = *it;
    if (pthreadSelfPointer == pthreadSelf) {
      vectorOfThread.erase(it);
      break;

    }
  }

  pthread_mutex_unlock(&vector_thread_mutex);

  close(clientSocket1);
  close(clientSocket2);
  pthread_exit (NULL);

}

