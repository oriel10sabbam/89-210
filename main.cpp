/*
 * name :    oriel sabban
 * id   :    201052602
 *
 * main.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: oriel
 */

#include "Board.h"
#include "Game.h"
#include "UserPlayer.h"
#include "ConsoleGrafic.h"
#include "StandartRules.h"

int main() {
  Player* whitePlayer = new UserPlayer(true);
  Player* blackPlayer = new UserPlayer(false);
  Board* board = new Board(8, 8);
  Rules* rules = new StandartRules(board);
  Grafic* grafic = new ConsoleGrafic(board);
  Game game = Game(whitePlayer, blackPlayer, board, rules, grafic);
  game.startTheGame();
  delete whitePlayer;
  delete blackPlayer;
  delete board;
  delete rules;
  delete grafic;

  return 0;
}

