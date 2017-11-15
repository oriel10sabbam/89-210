/*
 * name :   oriel sabban
 * id   :   201052602
 * ConsoleGrafic.h
 *
 *  Created on: Oct 31, 2017
 *      Author: oriel
 */

#ifndef CONSOLEGRAFIC_H_
#define CONSOLEGRAFIC_H_

#include "Grafic.h"

/*
 * this class represents a Console Grafic, that responsible for the
 * graphics at the Consul, this class heir from the Grafic class
 */
class ConsoleGrafic: public Grafic {
public:
  /*
   * constructor of ConsolGrafic
   * @ param board- a pointer to board
   */
  ConsoleGrafic(Board* board);

  /*
   * Destructor of ConsolGrafic
   *
   */
  virtual ~ConsoleGrafic();

  /*
   * printAMessage- print a message
   * @ param message- a dtring message to print
   */
  void printAMessage(string message) const;

  /*
   * printTheBoard- print the board
   */
  void printTheBoard() const;

  /* const
   * printTheLegalMoves- print the player's legal moves
   * @ param listOfPoints- list Of legal Points
   */
  void printTheLegalMoves(list<Point*> listOfPoints) const;

  /*
   *  printTheWiner- print The Winer of the game
   *  @param theWinerIsWhite- true if the white win
   *  @param theWinerIsBlack- true if the black win
   */
  void printTheWiner(bool theWinerIsWhite, bool theWinerIsBlack) const;

  /*
   * printTheNewMove- print The New Move
   * @ param isWhite- true if it's the white's move
   * @ param listOfPoints- list Of legal Points
   */
  void printTheNewMove(const bool isWhite, list<Point*> listOfPoints) const;

  /*
   *printAnErrorInputNotANum- print An Error if the Input is Not A Num
   */
  void printAnErrorInputNotANum() const;

  /*
   * printAnErrorInputNotLegal - print An Error if the Input is Not Legal
   * @ param point- a point that is not legal
   */
  void printAnErrorInputNotLegal(Point* point) const;

  /*
   * printNotPossibleNoves- print to the screen that the player have Not Possible Moves
   * @ param isWhite- true if the player is white
   */
  void printNotPossibleMoves(bool isWhite) const;

};

#endif /* CONSOLEGRAFIC_H_ */
