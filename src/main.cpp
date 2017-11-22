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
#include "ComputerPlayer.h"
#define ROW 8
#define COL 8

int main() {
  Board* board = new Board(ROW, COL);
  Rules* rules = new StandartRules();
  Grafic* grafic = new ConsoleGrafic(board);
  TheRival theRival = grafic->printTheMenu();
  Player* whitePlayer;
  if (theRival == C) {
    whitePlayer = new ComputerPlayer(true, board, rules);
  } else {
    whitePlayer = new UserPlayer(true);
  }
  Player* blackPlayer = new UserPlayer(false);
  Game game = Game(whitePlayer, blackPlayer, board, rules, grafic);
  game.startTheGame();
  delete whitePlayer;
  delete blackPlayer;
  delete board;
  delete rules;
  delete grafic;

  return 0;
}

