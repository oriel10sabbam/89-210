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

Point RemotePlayer::doAMove() {
  int x, y;
  try {
    x = client.getMessage();
    if (x == -1) {
      return Point(-10, -10);
    }
    y = client.getMessage();
    // if x == -10 or y == -10, it's mean that the player closed the socket
    if ((x == -10) || (y == -10)) {
      throw "error on get message";
    }

    return Point(x, y);
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

