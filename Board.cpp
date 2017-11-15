/*
 *
 * name :    oriel sabban
 * id   :    201052602
 * Board.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: oriel, zah
 */

#include "Board.h"

Board::Board(int row, int col) :
    row(row), col(col) {
  theBoard = new Square*[row];
  for (int i = 0; i < row; i++) {
    theBoard[i] = new Square[col];
  }
  initialBoard();
}

Board::~Board() {
  for (int i = 0; i < row; i++) {
    delete[] theBoard[i];
  }
  delete[] theBoard;
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

void Board::initialBoard() {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if ((i == j) && ((i == row / 2) || (i == (row / 2) - 1))) {
        theBoard[i][j] = W;
      } else if (((i == (row / 2) - 1) && (j == row / 2))
          || ((i == row / 2) && (j == (row / 2) - 1))) {
        theBoard[i][j] = B;
      } else {
        theBoard[i][j] = N;
      }
    }
  }
}

