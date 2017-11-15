/*
 * ComputerPlayer.h
 *
 *  Created on: Nov 15, 2017
 *      Author: oriel
 */

#ifndef COMPUTERPLAYER_H_
#define COMPUTERPLAYER_H_

#include "Rules.h"
#include "Board.h"
#include "Player.h"
#include <iostream>
#include <string>

using namespace std;

/*
 * this class represent the ComputerPlayer, this class heir from the Player class
 */
class ComputerPlayer: public Player {
public:

  /*
   * constructor of ComputerPlayer
   * @ param isWhite- true if it's the white player
   */
  ComputerPlayer(bool isWhite, Board* board, Rules* rules);

  /*
   * Destructor of ComputerPlayer
   */
  virtual ~ComputerPlayer();

  /*
   * DoAMove - the Player Do A Move, a virtual pure method
   */
  virtual Point* doAMove();

private:
  Board* board;
  Board* tempBoard;
  Rules* rules;

};

#endif /* COMPUTERPLAYER_H_ */
