/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * Player.h
 *
 *  Created on: Oct 30, 2017
 *      Author: oriel
 */

#ifndef PLAYER_H_
#define PLAYER_H_
#include "Point.h"
using namespace std;

/*
 * this class represent a Player, an An Abstract class
 */
class Player {
public:

  /*
   * constructor of Player
   * @ param isWhite- true if it's the white player
   */
  Player(bool isWhite);

  /*
   * Destructor of Player
   */
  virtual ~Player();

  /*
   * DoAMove - the Player Do A Move, a virtual pure method
   */
  virtual Point doAMove() = 0;

  /*
   * isWhite - returm true if it's the white player
   */
  bool isWhite();

protected:
  bool isWhitePlayer;
};

#endif /* PLAYER_H_ */
