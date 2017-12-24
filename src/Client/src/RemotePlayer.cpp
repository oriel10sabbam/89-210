/*
 * RemotePlayer.cpp
 *
 *  Created on: Dec 5, 2017
 *      Author: oriel
 */

#include "RemotePlayer.h"

using namespace std;

RemotePlayer::RemotePlayer(bool isWhite, Client& client) :
    Player(isWhite), client(client) {
}

vector<int> RemotePlayer::splitBySpace(string str) {

  std::istringstream buf(str);
  std::istream_iterator<std::string> beg(buf), end;

  std::vector < std::string > args(beg, end); // done!

  std::vector<int> argsInt;
  argsInt.clear();

  for (vector<string>::iterator it = args.begin(); it != args.end(); it++) {
    string s = *it;
    argsInt.push_back(atoi(s.c_str()));
    std::cout << '"' << s << '"' << '\n';
  }

  return argsInt;
}

Point RemotePlayer::doAMove() {
  int x, y, len;
  string message = "";
  string yMessage = "";
  try {
    len = client.getMessage();
    int i = 0;
    while (i < len) {
      message = message + client.getCharMessage();
      i++;
    }

    cout << "getting the message" << message << endl;

    if (message.find("NoMove") != std::string::npos) {
      return Point(-10, -10);
    }

    if (message.find("clientClosed") != std::string::npos) {
      throw "error on get message";
    }

    vector<int> args = splitBySpace(message);
    return Point(args[0], args[1]);
    /*
     if (Message.compare("NoMove") == 0) {
     return Point(-10, -10);
     }

     if (xMessage.compare("clientClosed") == 0) {
     throw "error on get message";
     }

     len = client.getMessage();

     i = 0;
     while (i < len) {
     yMessage = yMessage + client.getCharMessage();
     i++;
     }
     cout << "getting the message" << yMessage << endl;
     if (yMessage.compare("NoMove") == 0) {
     return Point(-10, -10);
     }

     if (yMessage.compare("clientClosed") == 0) {
     throw "error on get message";
     }
     x = atoi(xMessage.c_str());
     y = atoi(yMessage.c_str());

     return Point(x, y); */
  } catch (const char * msg) {
    cout << "RemotePlayer Cannot doAMove. Reason: " << msg << endl;
    exit(-1);
  }
}

RemotePlayer::~RemotePlayer() {
}

bool RemotePlayer::isRemote() {
  return true;
}

