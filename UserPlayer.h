/*
 * name :   oriel sabban
 * id   :   201052602
 * UserPlayer.h
 *
 *  Created on: Oct 30, 2017
 *      Author: oriel
 */

#ifndef USERPLAYER_H_
#define USERPLAYER_H_

#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * this class represent the UserPlayer, this class heir from the Player class
 */
class UserPlayer: public Player {
public:

  /*
   * constructor of UserPlayer
   * @ param isWhite- true if it's the white player
   */
  UserPlayer(bool isWhite);

  /*
   * Destructor of UserPlayer
   */
  virtual ~UserPlayer();

  /*
   * view the Player class
   */
  Point* doAMove() const;

private:

  /*
   * isDigit - return true if the string id digit
   * @ param s- a string
   * @ return true if the string id digit
   */
  bool isDigit(string s) const;

};

#endif /* USERPLAYER_H_ */
