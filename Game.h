/*
 * name :   oriel sabban
 * id   :   201052602
 * Game.h
 *
 *  Created on: Oct 29, 2017
 *      Author: oriel
 */

#ifndef GAME_H_
#define GAME_H_
#include "Player.h"
#include "Board.h"
#include "Rules.h"
#include "Grafic.h"
#include "Point.h"
#include <string.h>
#include <stdio.h>
#include <list>
using namespace std;

/*
 * this class represents a Game that  is responsible for running the game
 */
class Game {
public:

  /*
   * constructor of Game
   * @ param wPlayer- the white player
   * @ param bPlayer- the black player
   * @ param board1 - the board
   * @ param rules1 - the rules of the game
   * @ param grafic1 - the grafic of the game
   */
  Game(Player* wPlayer, Player* bPlayer, Board* board1, Rules* rules1,
      Grafic* grafic1);

  /*
   * Destructor of Game
   */
  virtual ~Game();

  /*
   * startTheGame- start The   reversi Game
   */
  void startTheGame();

private:

  /*
   * updateTheBoard - update The Board at the given point
   * @ param point- the pint that need to be update
   * @ param isWhite- true if is the white player point
   */
  void updateTheBoard(Point* point, bool isWhite);

  /*
   * updateTheColOfBoard- update The column Of Board
   * @ param point- the pint that need to be update
   * @ param isWhite- true if is the white player point
   */
  void updateTheColOfBoard(Point* point, bool isWhite);

  /*
   * updateTheRowOfBoard- update The row Of Board
   * @ param point- the pint that need to be update
   * @ param isWhite- true if is the white player point
   */
  void updateTheRowOfBoard(Point* point, bool isWhite);

  /*
   * updateTheSlantOfBoard- update The slant Of Board
   * @ param point- the pint that need to be update
   * @ param isWhite- true if is the white player point
   */
  void updateTheSlantOfBoard(Point* point, bool isWhite);

  /*
   * checkWhoWins- check Who Win the game
   */
  void checkWhoWins();

  const Player* whitePlayer;
  const Player* blackPlayer;
  Board* board;
  const Rules* rules;
  const Grafic* grafic;
  int remainingMoves;
};

#endif /* GAME_H_ */
