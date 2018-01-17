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

vector<int> RemotePlayer::splitBySpace(string st) {

  std::istringstream buf(st);
  std::istream_iterator<std::string> beg(buf), end;

  std::vector < std::string > args(beg, end); // done!

  std::vector<int> argsInt;
  argsInt.clear();

  for (vector<string>::iterator it = args.begin(); it != args.end(); it++) {
    string s = *it;
    argsInt.push_back(atoi(s.c_str()));
  }

  return argsInt;
}

Point RemotePlayer::doAMove() {
  int len;
  string message = "";
  string yMessage = "";
  try {
    len = client.getMessage();
    int i = 0;
    while (i < len) {
      message = message + client.getCharMessage();
      i++;
    }

    if (message.find("NoMove") != std::string::npos) {
      return Point(-10, -10);
    }

    if (message.find("clientClosed") != std::string::npos) {
      throw "error on get message";
    }

    vector<int> args = splitBySpace(message);
    return Point(args[0], args[1]);

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

