/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * StandartRulse.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: oriel
 */

#include "StandartRules.h"

StandartRules::StandartRules() {
}

StandartRules::~StandartRules() {
}

list<Point> StandartRules::theLegalMovesOfPlayer(bool isWhite,
    Board* board) const {
  list < Point > listOfPoints;
  listOfPoints.clear();
  int row = board->getRow();
  int col = board->getCol();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      Point point = Point(i, j);
      if (checkIfIsALegalMove(isWhite, point, board)) {
        listOfPoints.push_back(point);
      } else {
      }
    }
  }
  return listOfPoints;
}

bool StandartRules::areThePlayerHasALegalMove(bool isWhite,
    Board* board) const {
  int row = board->getRow();
  int col = board->getCol();
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      Point p = Point(i, j);
      if (checkIfIsALegalMove(isWhite, p, board)) {
        return true;
      }
    }
  }
  return false;
}

bool StandartRules::checkIfIsALegalMove(bool isWhite, Point point,
    Board* board) const {
  int row = board->getRow();
  int col = board->getCol();
  if (board->getValueAt(point.getX(), point.getY()) != N) {
    return false;
  }
//check for uper col
  if (board->checkValueAt(!isWhite, point.getX() + 1, point.getY())) {

    for (int i = point.getX() + 2; i < row; i++) {
      if (board->checkValueAt(!isWhite, i, point.getY())) {
        continue;
      }
      if (board->checkValueAt(isWhite, i, point.getY())) {
        return true;
      }
      break;
    }
  }

//check for under col
  if (board->checkValueAt(!isWhite, point.getX() - 1, point.getY())) {
    for (int i = point.getX() - 2; i >= 0; i--) {
      if (board->checkValueAt(!isWhite, i, point.getY())) {
        continue;
      }
      if (board->checkValueAt(isWhite, i, point.getY())) {
        return true;
      }
      break;
    }
  }

//check for uper row
  if (board->checkValueAt(!isWhite, point.getX(), point.getY() + 1)) {
    for (int j = point.getY() + 2; j < col; j++) {
      if (board->checkValueAt(!isWhite, point.getX(), j)) {
        continue;
      }
      if ((board->checkValueAt(isWhite, point.getX(), j))) {
        return true;
      }
      break;
    }
  }

//check for under row
  if (board->checkValueAt(!isWhite, point.getX(), point.getY() - 1)) {
    for (int j = point.getY() - 2; j >= 0; j--) {
      if (board->checkValueAt(!isWhite, point.getX(), j)) {
        continue;
      }
      if (board->checkValueAt(isWhite, point.getX(), j)) {
        return true;
      }
      break;
    }
  }
/////////////////////////////////////// slant /////////////////////////////////

//check for slant - uper row uper col
  if (board->checkValueAt(!isWhite, point.getX() + 1, point.getY() + 1)) {
    int i = point.getX() + 2;
    int j = point.getY() + 2;
    while ((i < row) && (j < col)) {
      if (board->checkValueAt(!isWhite, i, j)) {
        i++;
        j++;
        continue;
      }
      if (board->checkValueAt(isWhite, i, j)) {
        return true;
      }
      break;
    }
  }

//check for slant - under row uper col
  if (board->checkValueAt(!isWhite, point.getX() - 1, point.getY() + 1)) {
    int i = point.getX() - 2;
    int j = point.getY() + 2;
    while ((i >= 0) && (j < col)) {
      if (board->checkValueAt(!isWhite, i, j)) {
        i--;
        j++;
        continue;
      }
      if (board->checkValueAt(isWhite, i, j)) {
        return true;
      }
      break;
    }
  }

//check for slant - uper row under col
  if (board->checkValueAt(!isWhite, point.getX() + 1, point.getY() - 1)) {
    int i = point.getX() + 2;
    int j = point.getY() - 2;
    while ((i < row) && (j >= 0)) {
      if (board->checkValueAt(!isWhite, i, j)) {
        i++;
        j--;
        continue;
      }
      if (board->checkValueAt(isWhite, i, j)) {
        return true;
      }
      break;
    }
  }

//check for slant - under row under col
  if (board->checkValueAt(!isWhite, point.getX() - 1, point.getY() - 1)) {
    int i = point.getX() - 2;
    int j = point.getY() - 2;
    while ((i >= 0) && (j >= 0)) {
      if (board->checkValueAt(!isWhite, i, j)) {
        i--;
        j--;
        continue;
      }
      if (board->checkValueAt(isWhite, i, j)) {
        return true;
      }
      break;
    }
  }

  return false;

}

