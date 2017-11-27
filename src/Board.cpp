/*
 *
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * Board.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: oriel, gay zach
 */

#include "Board.h"

Board::Board(int row, int col) :
    row(row), col(col) {
  if ((row < 2) || (col < 2)) {
    throw std::range_error("range error, you try to create"
        " a Board with row or col smaller than 2");
  }
  theBoard = new Square*[row];
  for (int i = 0; i < row; i++) {
    theBoard[i] = new Square[col];
  }
  initialBoard();
}

Board::Board(Board* board) {
  row = board->row;
  col = board->col;
  theBoard = new Square*[row];
  for (int i = 0; i < row; i++) {
    theBoard[i] = new Square[col];
  }
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      theBoard[i][j] = board->getValueAt(i, j);
    }
  }
}

Board::~Board() {
  for (int i = 0; i < row; i++) {
    delete[] theBoard[i];
  }
  delete[] theBoard;
}

void Board::updateTheBoard(Point& point, bool isWhite) {
  updateTheColOfBoard(point, isWhite);
  updateTheRowOfBoard(point, isWhite);
  updateTheSlantOfBoard(point, isWhite);
}

void Board::updateTheColOfBoard(Point& point, bool isWhite) {
  //update the upper col
  if (checkValueAt(!isWhite, point.getX() + 1, point.getY())) {

    for (int i = point.getX() + 2; i < getRow(); i++) {
      if (checkValueAt(!isWhite, i, point.getY())) {
        continue;
      }
      if (checkValueAt(isWhite, i, point.getY())) {
        for (int k = i - 1; k >= point.getX(); k--) {
          setValueAccordingPlayerAt(isWhite, k, point.getY());
        }
      }
      break;
    }
  }

  //update the under col

  if (checkValueAt(!isWhite, point.getX() - 1, point.getY())) {
    for (int i = point.getX() - 2; i >= 0; i--) {
      if (checkValueAt(!isWhite, i, point.getY())) {
        continue;
      }
      if (checkValueAt(isWhite, i, point.getY())) {
        for (int k = i + 1; k <= point.getX(); k++) {
          setValueAccordingPlayerAt(isWhite, k, point.getY());
        }
      }
      break;
    }
  }

}

void Board::updateTheRowOfBoard(Point& point, bool isWhite) {
  //update the upper row
  if (checkValueAt(!isWhite, point.getX(), point.getY() + 1)) {
    for (int j = point.getY() + 2; j < getCol(); j++) {
      if (checkValueAt(!isWhite, point.getX(), j)) {
        continue;
      }
      if (checkValueAt(isWhite, point.getX(), j)) {
        for (int k = j - 1; k >= point.getY(); k--) {
          setValueAccordingPlayerAt(isWhite, point.getX(), k);
        }
      }
      break;
    }
  }

//update the under row
  if (checkValueAt(!isWhite, point.getX(), point.getY() - 1)) {
    for (int j = point.getY() - 2; j >= 0; j--) {
      if (checkValueAt(!isWhite, point.getX(), j)) {
        continue;
      }
      if (checkValueAt(isWhite, point.getX(), j)) {
        for (int k = j + 1; k <= point.getY(); k++) {
          setValueAccordingPlayerAt(isWhite, point.getX(), k);
        }
      }
      break;
    }
  }

}

void Board::updateTheSlantOfBoard(Point& point, bool isWhite) {
  //update the slant - upper row upper col
  if (checkValueAt(!isWhite, point.getX() + 1, point.getY() + 1)) {
    int i = point.getX() + 2;
    int j = point.getY() + 2;
    while ((i < getRow()) && (j < getCol())) {
      if (checkValueAt(!isWhite, i, j)) {
        i++;
        j++;
        continue;
      }
      if (checkValueAt(isWhite, i, j)) {
        int k = i - 1;
        int l = j - 1;
        while (k >= point.getX()) {
          setValueAccordingPlayerAt(isWhite, k, l);
          k--;
          l--;
        }
      }
      break;
    }
  }

  //update the slant - under row upper col
  if (checkValueAt(!isWhite, point.getX() - 1, point.getY() + 1)) {
    int i = point.getX() - 2;
    int j = point.getY() + 2;
    while ((i >= 0) && (j < getCol())) {
      if (checkValueAt(!isWhite, i, j)) {
        i--;
        j++;
        continue;
      }
      if (checkValueAt(isWhite, i, j)) {
        int k = i + 1;
        int l = j - 1;
        while (k <= point.getX()) {
          setValueAccordingPlayerAt(isWhite, k, l);
          k++;
          l--;
        }
      }
      break;
    }
  }

  //update the slant - uper row under col
  if (checkValueAt(!isWhite, point.getX() + 1, point.getY() - 1)) {
    int i = point.getX() + 2;
    int j = point.getY() - 2;
    while ((i < getRow()) && (j >= 0)) {
      if (checkValueAt(!isWhite, i, j)) {
        i++;
        j--;
        continue;
      }
      if (checkValueAt(isWhite, i, j)) {
        int k = i - 1;
        int l = j + 1;
        while (k >= point.getX()) {
          setValueAccordingPlayerAt(isWhite, k, l);
          k--;
          l++;
        }
      }
      break;
    }
  }

  //update the slant - under row under col
  if (checkValueAt(!isWhite, point.getX() - 1, point.getY() - 1)) {
    int i = point.getX() - 2;
    int j = point.getY() - 2;
    while ((i >= 0) && (j >= 0)) {
      if (checkValueAt(!isWhite, i, j)) {
        i--;
        j--;
        continue;
      }
      if (checkValueAt(isWhite, i, j)) {
        int k = i + 1;
        int l = j + 1;
        while (k <= point.getX()) {
          setValueAccordingPlayerAt(isWhite, k, l);
          k++;
          l++;
        }
      }
      break;
    }
  }

}

int Board::getRow() const {
  return row;
}

int Board::getCol() const {
  return col;
}

void Board::setValueAccordingPlayerAt(bool isWhite, int i, int j) {
  if (isWhite) {
    setValueAt(i, j, W);
  } else {
    setValueAt(i, j, B);
  }
}

void Board::setValueAt(int i, int j, Square square) {
  if ((i < 0) || (i >= row) || (j < 0) || (j >= col)) {
    throw std::range_error("range error, you try to get to value"
        " that it's out of the range of Board");
  }
  theBoard[i][j] = square;
}

Square Board::getValueAt(int i, int j) const {
  if ((i < 0) || (i >= row) || (j < 0) || (j >= col)) {
    return E;
  }
  return theBoard[i][j];
}

bool Board::checkValueAt(bool isWhite, int i, int j) const {
  if (isWhite) {
    return (getValueAt(i, j) == W);
  } else {
    return (getValueAt(i, j) == B);
  }
}

void Board::initialWithAnotherBoard(Board* board) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      theBoard[i][j] = board->getValueAt(i, j);
    }
  }
}

void Board::initialBoard() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if ((i == j) && ((i == row / 2) || (i == (row / 2) - 1))) {
        theBoard[i][j] = W;
      } else if (((i == (row / 2) - 1) && (j == col / 2))
          || ((i == row / 2) && (j == (col / 2) - 1))) {
        theBoard[i][j] = B;
      } else {
        theBoard[i][j] = N;
      }
    }
  }
}

int Board::countSquaresOfPlayer(bool isWhite) {
  int theNumOfSquares = 0;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if ((isWhite && (theBoard[i][j] == W))
          || (!isWhite && theBoard[i][j] == B)) {
        theNumOfSquares++;
      }
    }
  }
  return theNumOfSquares;
}
