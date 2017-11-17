/*
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
    // cout << "\n for the Computer point (" << (*it)->getX() + 1 << ","
    //   << (*it)->getY() + 1 << "): \n";

    tempBoardComputer->initialWithAnotherBoard(board);
    tempBoardComputer->updateTheBoard(*it, isWhite());
    list < Point > listOfPointsRival = rules->theLegalMovesOfPlayer(!isWhite(),
        tempBoardComputer);
    int difference;
    if (!listOfPointsRival.empty()) {
      int theMaxSquaresRival = -999999;
      //cout << "\n       the points of the Rivla: \n";
      for (list<Point>::iterator it2 = listOfPointsRival.begin();
          it2 != listOfPointsRival.end(); ++it2) {

        //cout << "\n       (" << (*it2)->getX() + 1 << "," << (*it2)->getY() + 1
        //    << "), ";
        tempBoardRival->initialWithAnotherBoard(tempBoardComputer);
        tempBoardRival->updateTheBoard(*it2, !isWhite());
        difference = differenceSquares(tempBoardRival);
        //cout << "\n       the difference of the Rivla: " << difference << endl;
        if (difference > theMaxSquaresRival) {
          theMaxSquaresRival = difference;
        }
      }
      mapPointToMax[*it] = theMaxSquaresRival;
      // cout << "\n       the Max of the Rivla: " << theMaxSquaresRival << endl;
    } else {
      difference = differenceSquares(tempBoardComputer);
      // cout << "\n       the Max of the Rivla: " << difference << endl;
      mapPointToMax[*it] = difference;
    }
  }
  return getTheMinFromMap(mapPointToMax);

}

