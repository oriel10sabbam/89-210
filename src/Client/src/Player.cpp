/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * Player.cpp
 *
 *  Created on: Oct 30, 2017
 *      Author: oriel
 */

#include "Player.h"

Player::Player(bool isWhite) {
  isWhitePlayer = isWhite;
}

Player::~Player() {
}

bool Player::isWhite() {
  return isWhitePlayer;
}

bool Player::isRemote() {
  return false;
}

