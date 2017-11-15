/*
 * name :   oriel sabban
 * id   :   201052602
 *
 * Board.h
 *
 *  Created on: Oct 24, 2017
 *      Author: oriel sabban
 */

#ifndef BOARD_H_
#define BOARD_H_
#include <iostream>
#include <string>
using namespace std;

enum Square {
  W, B, N, E
};
//W- white, B- black, N- none, E- symboly a error
// the_board_ is a two-dimensional array with width and height of squares

/*
 * Board- this class represent a Board of the Reversi game
 */
class Board {
public:

  /*
   * constructor of Board
   * @ param row- the num of row of the board
   * @ param col- the num of column of the board
   */
  Board(int row, int col);

  /*
   * Destructor of Board
   */
  ~Board();

  /*
   * InitialBoard- this method initial the board
   */
  void initialBoard();

  /*
   * InitialBoard- this method initial the board
   * @ return row- the num of row of the board
   */
  int getRow() const;

  /*
   * InitialBoard- this method initial the board
   * @ return row- the num of column of the board
   *
   */
  int getCol() const;

  /*
   * getValueAt- return the Square at board[i][j]
   * @ param i- index
   * @ param j- index
   * @return the Square at board[i][j]
   */
  Square getValueAt(int i, int j) const;

  /*
   * checkValueAt- check Value At board[i][j] and return true if it's
   * the square of the given player
   * @ param isWhite- true if it's the white player
   * @ param i- index
   * @ param j- index
   * @ return  true if it's the square of the given player
   */
  bool checkValueAt(bool isWhite, int i, int j) const;

  /*
   * setValueAt- set a Square to board[i][j]
   * @ param i- index
   * @ param j- index
   * @ param square- a square (B, W, N, E)
   */
  void setValueAt(int i, int j, Square square);

  /*
   * setValueAccordingPlayerAt- set a Square to board[i][j] According Player
   * @ param isWhite- true if it's the white
   * @ param i- index
   * @ param j- index
   */
  void setValueAccordingPlayerAt(bool isWhite, int i, int j);

private:

  Square** theBoard;
  int row, col;
};
#endif /* BOARD_H_ */
