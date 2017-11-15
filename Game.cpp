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

void Game::updateTheColOfBoard(Point* point, bool isWhite) {
  //update the upper col
  if (board->checkValueAt(!isWhite, point->getX() + 1, point->getY())) {

    for (int i = point->getX() + 2; i < board->getRow(); i++) {
      if (board->checkValueAt(!isWhite, i, point->getY())) {
        continue;
      }
      if (board->checkValueAt(isWhite, i, point->getY())) {
        for (int k = i - 1; k >= point->getX(); k--) {
          board->setValueAccordingPlayerAt(isWhite, k, point->getY());
        }
      }
      break;
    }
  }

  //update the under col

  if (board->checkValueAt(!isWhite, point->getX() - 1, point->getY())) {
    for (int i = point->getX() - 2; i >= 0; i--) {
      if (board->checkValueAt(!isWhite, i, point->getY())) {
        continue;
      }
      if (board->checkValueAt(isWhite, i, point->getY())) {
        for (int k = i + 1; k <= point->getX(); k++) {
          board->setValueAccordingPlayerAt(isWhite, k, point->getY());
        }
      }
      break;
    }
  }
}

void Game::updateTheRowOfBoard(Point* point, bool isWhite) {
  //update the upper row
  if (board->checkValueAt(!isWhite, point->getX(), point->getY() + 1)) {
    for (int j = point->getY() + 2; j < board->getCol(); j++) {
      if (board->checkValueAt(!isWhite, point->getX(), j)) {
        continue;
      }
      if (board->checkValueAt(isWhite, point->getX(), j)) {
        for (int k = j - 1; k >= point->getY(); k--) {
          board->setValueAccordingPlayerAt(isWhite, point->getX(), k);
        }
      }
      break;
    }
  }

//update the under row
  if (board->checkValueAt(!isWhite, point->getX(), point->getY() - 1)) {
    for (int j = point->getY() - 2; j >= 0; j--) {
      if (board->checkValueAt(!isWhite, point->getX(), j)) {
        continue;
      }
      if (board->checkValueAt(isWhite, point->getX(), j)) {
        for (int k = j + 1; k <= point->getY(); k++) {
          board->setValueAccordingPlayerAt(isWhite, point->getX(), k);
        }
      }
      break;
    }
  }
}

void Game::updateTheSlantOfBoard(Point* point, bool isWhite) {
  //update the slant - upper row upper col
  if (board->checkValueAt(!isWhite, point->getX() + 1, point->getY() + 1)) {
    int i = point->getX() + 2;
    int j = point->getY() + 2;
    while ((i < board->getRow()) && (j < board->getCol())) {
      if (board->checkValueAt(!isWhite, i, j)) {
        i++;
        j++;
        continue;
      }
      if (board->checkValueAt(isWhite, i, j)) {
        int k = i - 1;
        int l = j - 1;
        while (k >= point->getX()) {
          board->setValueAccordingPlayerAt(isWhite, k, l);
          k--;
          l--;
        }
      }
      break;
    }
  }

  //update the slant - under row upper col
  if (board->checkValueAt(!isWhite, point->getX() - 1, point->getY() + 1)) {
    int i = point->getX() - 2;
    int j = point->getY() + 2;
    while ((i >= 0) && (j < board->getCol())) {
      if (board->checkValueAt(!isWhite, i, j)) {
        i--;
        j++;
        continue;
      }
      if (board->checkValueAt(isWhite, i, j)) {
        int k = i + 1;
        int l = j - 1;
        while (k <= point->getX()) {
          board->setValueAccordingPlayerAt(isWhite, k, l);
          k++;
          l--;
        }
      }
      break;
    }
  }

  //update the slant - uper row under col
  if (board->checkValueAt(!isWhite, point->getX() + 1, point->getY() - 1)) {
    int i = point->getX() + 2;
    int j = point->getY() - 2;
    while ((i < board->getRow()) && (j >= 0)) {
      if (board->checkValueAt(!isWhite, i, j)) {
        i++;
        j--;
        continue;
      }
      if (board->checkValueAt(isWhite, i, j)) {
        int k = i - 1;
        int l = j + 1;
        while (k >= point->getX()) {
          board->setValueAccordingPlayerAt(isWhite, k, l);
          k--;
          l++;
        }
      }
      break;
    }
  }

  //update the slant - under row under col
  if (board->checkValueAt(!isWhite, point->getX() - 1, point->getY() - 1)) {
    int i = point->getX() - 2;
    int j = point->getY() - 2;
    while ((i >= 0) && (j >= 0)) {
      if (board->checkValueAt(!isWhite, i, j)) {
        i--;
        j--;
        continue;
      }
      if (board->checkValueAt(isWhite, i, j)) {
        int k = i + 1;
        int l = j + 1;
        while (k <= point->getX()) {
          board->setValueAccordingPlayerAt(isWhite, k, l);
          k++;
          l++;
        }
      }
      break;
    }
  }
}
void Game::updateTheBoard(Point* point, bool isWhite) {
  updateTheColOfBoard(point, isWhite);
  updateTheRowOfBoard(point, isWhite);
  updateTheSlantOfBoard(point, isWhite);
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
            updateTheBoard(point, true);
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
            updateTheBoard(point, false);
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

