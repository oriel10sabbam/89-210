/*
* names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * Rules.h
 *
 *  Created on: Oct 31, 2017
 *      Author: oriel
 */

#ifndef RULES_H_
#define RULES_H_
#include "Board.h"
#include "Point.h"
#include <list>
using namespace std;

/*
 * this class represents the rules of the game, an Abstract class
 */
class Rules {
public:

  /*
   * constructor of Rules
   */
  Rules();

  /*
   * Destructor of the Rules
   */
  virtual ~Rules();

  /*
   * areThePlayerHasALegalMove - check and return true if The Player Has
   * A Legal Move, a virtual pure method
   * @ param isWhite- true if is the white player
   * @ param board- a pointer to board
   * @ return true if is a legal move to the player
   */
  virtual bool areThePlayerHasALegalMove(bool isWhite, Board* board) const = 0;

  /*
   * checkIfIsALegalMove - check and return true if the point Is
   * A Legal Move, a virtual pure method
   * @ param row- the num of row
   * @ param col- the num of column
   * @ param point- the point that need to check
   * @ return true if is a legal move to the player
   */
  virtual bool checkIfIsALegalMove(bool isWhite, Point point,
      Board* board) const = 0;

  /*
   * theLegalMovesOfPlayer - return the Legal Moves Of Player
   * a virtual pure method
   * @ param isWhite- true if is the white player
   * @ return list of the legal Points
   */
  virtual list<Point> theLegalMovesOfPlayer(bool isWhite,
      Board* board) const = 0;
};

#endif /* RULES_H_ */
