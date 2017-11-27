/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * UserPlayer.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: oriel
 */

#include "UserPlayer.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cctype>

using namespace std;

UserPlayer::UserPlayer(bool isWhite) :
    Player(isWhite) {
}

UserPlayer::~UserPlayer() {
}

Point UserPlayer::doAMove() {
  int numOfRow = -1;
  int numOfCol = -1;
  Point point;
  string r, c;
  cin >> r >> c;
  if (isDigit(r) && isDigit(c)) {
    numOfRow = atoi(r.c_str()) - 1;
    numOfCol = atoi(c.c_str()) - 1;
    point = Point(numOfRow, numOfCol);
  } else {
    point = Point(-1, -1);
  }
  return point;
}

bool UserPlayer::isDigit(string s) {
  bool isDig = true;
  for (unsigned i = 0; i < s.size(); i++) {
    if (!isdigit(s.at(i))) {
      isDig = false;
      break;
    }
  }
  return isDig;
}
