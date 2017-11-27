/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 * Grafic.h
 *
 *  Created on: Oct 31, 2017
 *      Author: oriel
 */

#ifndef GRAFIC_H_
#define GRAFIC_H_
#include <string>
#include <stdio.h>
#include "Board.h"
#include "Point.h"
#include <list>
#include <stdio.h>

using namespace std;

enum TheRival {
  C, H
};
//C- Computer, H- human
/*
 * this class represents a Grafic, that responsible for the graphics. An Abstract class
 */
class Grafic {
public:

  /*
   * constructor of Grafic
   * @ param board- a pointer to board
   */
  Grafic(Board* board);

  /*
   * Destructor of Grafic
   */
  virtual ~Grafic();

  /*
   * printAMessage- print a message. a virtual pure method
   * @ param message- a dtring message to print
   */
  virtual void printAMessage(string message) const = 0;

  /*
   * printTheBoard- print the board, a virtual pure method
   */
  virtual void printTheBoard() const = 0;

  /*
   * printTheLegalMoves- print the player's legal moves, a virtual pure method
   * @ param listOfPoints- list Of legal Points
   */
  virtual void printTheLegalMoves(list<Point> listOfPoints) const = 0;

  /*
   *  printTheWiner- print The Winer of the game, a virtual pure method
   *  @param theWinerIsWhite- true if the white win
   *  @param theWinerIsBlack- true if the black win
   */
  virtual void printTheWiner(bool theWinerIsWhite,
      bool theWinerIsBlack) const = 0;

  /*
   *  printTheMenu- print the first menu
   *  @return the rival that the user chose
   */
  virtual TheRival printTheMenu() const = 0;

  /*
   * printTheNewMove- print The New Move, a virtual pure method
   * @ param isWhite- true if it's the white's move
   * @ param listOfPoints- list Of legal Points
   */
  virtual void printTheNewMove(const bool isWhite, list<Point> listOfPoints,
      Point& point) const = 0;

  /*
   *printAnErrorInputNotANum- print An Error if the Input is Not A Num, a virtual pure method
   */
  virtual void printAnErrorInputNotANum() const = 0;

  /*
   * printAnErrorInputNotLegal - print An Error if the Input is Not Legal, a virtual pure method
   * @ param point- a point that is not legal
   */
  virtual void printAnErrorInputNotLegal(Point point) const = 0;

  /*
   * printNotPossibleNoves- print to the screen that the player have Not Possible Moves, a virtual pure method
   * @ param isWhite- true if the player is white
   */
  virtual void printNotPossibleMoves(bool isWhite) const = 0;

protected:
  Board* board;

};

#endif /* GRAFIC_H_ */
