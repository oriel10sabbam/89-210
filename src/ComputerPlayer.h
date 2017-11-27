/*
* names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
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
#include <map>

using namespace std;

/*
 * this class represent the ComputerPlayer, this class heir from the Player class
 */
class ComputerPlayer: public Player {
public:

  /*
   * constructor of ComputerPlayer
   * @ param isWhite- true if it's the white player
   * @ param board- a pointer to board
   * @ param rules- a pointer to rules
   */
  ComputerPlayer(bool isWhite, Board* board, Rules* rules);

  /*
   * Destructor of ComputerPlayer
   */
  virtual ~ComputerPlayer();

  /*
   * DoAMove - the Player Do A Move, a virtual pure method
   */
  virtual Point doAMove();

private:

  /*
   * differenceSquares- return the difference Squares on a board
   *  between the players
   * @ param board- a pointer to board
   */
  int differenceSquares(Board* board);

  /*
   * getTheMinFromMap- return point with the minimum difference between the
   * players from the map
   * @ param mapPointToMax- a map from point to max value
   * @ return- the point with the minimum difference between the
   * players from the map
   */
  Point getTheMinFromMap(map<Point, int> mapPointToMax);

  Board* board;
  Board* tempBoardComputer;
  Board* tempBoardRival;
  Rules* rules;

};

#endif /* COMPUTERPLAYER_H_ */
