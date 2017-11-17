/*
 * name :   oriel sabban
 * id   :   201052602
 * Game.cpp
 *
 *  Created on: Oct 29, 2017
 *      Author: oriel
 */

#include "Game.h"

Game::~Game() {

}

Game::Game(Player* wPlayer, Player* bPlayer, Board* board1, Rules* rules1,
    Grafic* grafic1) {
  whitePlayer = wPlayer;
  blackPlayer = bPlayer;
  board = board1;
  rules = rules1;
  grafic = grafic1;
  remainingMoves = (board->getRow() * board->getCol()) - 4;
}

void Game::checkWhoWins() {
  int counterWhite = board->countSquaresOfPlayer(true);
  int counterBlack = board->countSquaresOfPlayer(false);
  bool theWhiteWins = false;
  bool theBlackWins = false;
  if (counterWhite > counterBlack) {
    theWhiteWins = true;
  } else if ((counterWhite < counterBlack)) {
    theBlackWins = true;
  } else {
    theWhiteWins = true;
    theBlackWins = true;
  }

  grafic->printTheWiner(theWhiteWins, theBlackWins);
}

bool Game::playOneTurn(Player* player, Point& point, bool& isTheWhiteMove) {
  if (rules->areThePlayerHasALegalMove(player->isWhite(), board)) {

    list < Point > listOfPoints = rules->theLegalMovesOfPlayer(
        player->isWhite(), board);
    grafic->printTheNewMove(player->isWhite(), listOfPoints, point);
    listOfPoints.clear();
    point = player->doAMove();
    if (point.getX() != -1) {
      if (rules->checkIfIsALegalMove(player->isWhite(), point, board)) {
        board->updateTheBoard(point, player->isWhite());
        remainingMoves--;
        isTheWhiteMove = !player->isWhite();
      } else {
        grafic->printAnErrorInputNotLegal(point);
        point = Point(-1, -1);
      }
    } else {
      grafic->printAnErrorInputNotANum();
      point = Point(-1, -1);
    }
    return true;
  } else if (rules->areThePlayerHasALegalMove(!player->isWhite(), board)) {
    grafic->printNotPossibleMoves(player->isWhite());
    isTheWhiteMove = !player->isWhite();
    return true;
  } else {
    return false;
  }

}

void Game::startTheGame() {
  bool isTheWhiteMove = false;
  Point point = Point(-1, -1);
  bool weNeedToContinue = true;
  while (remainingMoves && weNeedToContinue) {
    if (isTheWhiteMove) {
      weNeedToContinue = playOneTurn(whitePlayer, point, isTheWhiteMove);
    } else {
      weNeedToContinue = playOneTurn(blackPlayer, point, isTheWhiteMove);
    }
  }
  checkWhoWins();
}

