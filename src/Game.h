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
   * playOneTurn- play one turn of the game
   * @ param player- the player that do the move
   */
  bool playOneTurn(Player* player, Point& theLastPoint, bool& isTheWhiteMove);

  /*
   * checkWhoWins- check Who Win the game
   */
  void checkWhoWins();

  Player* whitePlayer;
  Player* blackPlayer;
  Board* board;
  const Rules* rules;
  const Grafic* grafic;
  int remainingMoves;
};

#endif /* GAME_H_ */
