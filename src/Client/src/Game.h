/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
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
#include "Client.h"
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
   * @ param client1 - the client of the game
   */
  Game(Player* wPlayer, Player* bPlayer, Board* board1, Rules* rules1,
      Grafic* grafic1, Client* client1);

  /*
   * Destructor of Game
   */
  virtual ~Game();

  /*
   * startTheGame- start The reversi Game
   */
  void startTheGame(bool isRemoteGame);

  /*
   * startTheRemoteGame- start The Remote Reversi Game
   */
  void startTheRemoteGame();

private:

  /*
   * playOneTurn- play one turn of the game
   * @ param player- the player that do the move
   * @ param theLastPoint- the Last Point (the last move)
   * @ param isTheWhiteMove- true if is The White Move
   */
  bool playOneTurn(Player* player, Point& theLastPoint, bool& isTheWhiteMove);

  /*
   * playOneRemoteTurn- play One Turn of the Remote game
   * @ param player- the player that do the move
   * @ param theLastPoint- the Last Point (the last move)
   * @ param isTheWhiteMove- true if is The White Move
   */
  bool playOneRemoteTurn(Player* player, Point& theLastPoint,
      bool& isTheWhiteMove);

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
  Client* client;
};

#endif /* GAME_H_ */
