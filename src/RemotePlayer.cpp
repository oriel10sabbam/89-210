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
  int x = client.getMessage();
  if (x == -1) {
    return Point(-10, -10);
  }
  int y = client.getMessage();
  return Point(x, y);
}

RemotePlayer::~RemotePlayer() {
}

bool RemotePlayer::isRemote() {
  return true;
}

