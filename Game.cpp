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
  int counterWhite = 0;
  int counterBlack = 0;
  bool theWhiteWins = false;
  bool theBlackWins = false;
  for (int i = 0; i < board->getRow(); i++) {
    for (int j = 0; j < board->getCol(); j++) {
      switch (board->getValueAt(i, j)) {
      case B:
        counterBlack++;
        break;
      case W:
        counterWhite++;
        break;
      case N:
      case E:
        break;
      }
    }
  }
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

void Game::startTheGame() {
  bool isTheWhiteMove = false;
  while (remainingMoves) {
    if (isTheWhiteMove) {
      if (rules->areThePlayerHasALegalMove(true)) {

        list<Point*> listOfPoints = rules->theLegalMovesOfPlayer(true);
        grafic->printTheNewMove(true, listOfPoints);
        listOfPoints.clear();
        Point* point = whitePlayer->doAMove();
        if (point->getX() != -1) {
          if (rules->checkIfIsALegalMove(true, point)) {
            board->updateTheBoard(point, true);
            remainingMoves++;
            isTheWhiteMove = false;
          } else {
            grafic->printAnErrorInputNotLegal(point);
            delete point;
            continue;
          }
        } else {
          grafic->printAnErrorInputNotANum();
          delete point;
          continue;
        }
        delete point;
      } else if (rules->areThePlayerHasALegalMove(false)) {
        grafic->printNotPossibleMoves(true);
        isTheWhiteMove = false;
        continue;
      } else {
        break;
      }
    } else {
      if (rules->areThePlayerHasALegalMove(false)) {

        list<Point*> listOfPoints = rules->theLegalMovesOfPlayer(false);
        grafic->printTheNewMove(false, listOfPoints);
        listOfPoints.clear();
        Point* point = blackPlayer->doAMove();
        if (point->getX() != -1) {
          if (rules->checkIfIsALegalMove(false, point)) {
            board->updateTheBoard(point, false);
            remainingMoves++;
            isTheWhiteMove = true;
          } else {
            grafic->printAnErrorInputNotLegal(point);
            delete point;
            continue;
          }
        } else {
          grafic->printAnErrorInputNotANum();
          delete point;
          continue;
        }
        delete point;
      } else if (rules->areThePlayerHasALegalMove(true)) {
        grafic->printNotPossibleMoves(false);
        isTheWhiteMove = true;
        continue;
      } else {
        break;

      }

    }
  }
  checkWhoWins();
}

