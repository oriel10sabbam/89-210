/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * ComputerPlayer.cpp
 *
 *  Created on: Nov 15, 2017
 *      Author: oriel
 */

#include "ComputerPlayer.h"

using namespace std;

ComputerPlayer::ComputerPlayer(bool isWhite, Board* board, Rules* rules) :
    Player(isWhite), board(board), rules(rules) {
  tempBoardComputer = new Board(board->getRow(), board->getCol());
  tempBoardRival = new Board(board->getRow(), board->getCol());
}

ComputerPlayer::~ComputerPlayer() {
  delete tempBoardComputer;
  delete tempBoardRival;
}

int ComputerPlayer::differenceSquares(Board* board) {
  int counterSquaresWhite = board->countSquaresOfPlayer(true);
  int counterSquaresBlack = board->countSquaresOfPlayer(false);
  int difference;
  if (isWhite()) {
    difference = counterSquaresBlack - counterSquaresWhite;
  } else {
    difference = counterSquaresWhite - counterSquaresBlack;
  }
  return difference;
}

Point ComputerPlayer::getTheMinFromMap(map<Point, int> mapPointToMax) {
  int theMinSquaresRival = 999999;
  bool theFirst = true;
  Point pointMin;
  for (map<Point, int>::iterator it = mapPointToMax.begin();
      it != mapPointToMax.end(); ++it) {
    if (it->second < theMinSquaresRival) {
      theMinSquaresRival = it->second;
      if (!theFirst) {
        theFirst = false;
      }
      pointMin = it->first;
    }
  }
  return pointMin;

}

Point ComputerPlayer::doAMove() {
  list < Point > listOfPointsComputer = rules->theLegalMovesOfPlayer(isWhite(),
      board);
  map<Point, int> mapPointToMax;
  for (list<Point>::iterator it = listOfPointsComputer.begin();
      it != listOfPointsComputer.end(); ++it) {

    tempBoardComputer->initialWithAnotherBoard(board);
    tempBoardComputer->updateTheBoard(*it, isWhite());
    list < Point > listOfPointsRival = rules->theLegalMovesOfPlayer(!isWhite(),
        tempBoardComputer);
    int difference;
    if (!listOfPointsRival.empty()) {
      int theMaxSquaresRival = -999999;
      for (list<Point>::iterator it2 = listOfPointsRival.begin();
          it2 != listOfPointsRival.end(); ++it2) {

        tempBoardRival->initialWithAnotherBoard(tempBoardComputer);
        tempBoardRival->updateTheBoard(*it2, !isWhite());
        difference = differenceSquares(tempBoardRival);
        if (difference > theMaxSquaresRival) {
          theMaxSquaresRival = difference;
        }
      }
      mapPointToMax[*it] = theMaxSquaresRival;
    } else {
      difference = -999999;
      mapPointToMax[*it] = difference;
    }
  }
  return getTheMinFromMap(mapPointToMax);

}

