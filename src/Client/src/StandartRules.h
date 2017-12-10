/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * StandartRulse.h
 *
 *  Created on: Oct 31, 2017
 *      Author: oriel
 */

#ifndef STANDARTRULES_H_
#define STANDARTRULES_H_

#include "Rules.h"
#include "Player.h"
#include "Point.h"

/*
 * this class represent the StandartRulse, this class heir from the Rules class
 */
class StandartRules: public Rules {
public:

  /*
   * constructor of StandartRulse
   */
  StandartRules();

  /*
   * Destructor of the StandartRulse
   */
  virtual ~StandartRules();

  /*
   * view the Rules class
   */
  bool areThePlayerHasALegalMove(bool isWhite, Board* board) const;

  /*
   * view the Rules class
   */
  bool checkIfIsALegalMove(bool isWhite, Point point, Board* board) const;

  /*
   * view the Rules class
   */
  list<Point> theLegalMovesOfPlayer(bool isWhite, Board* board) const;

};

#endif /* STANDARTRULES_H_ */
