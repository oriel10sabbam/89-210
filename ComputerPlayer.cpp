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
  tempBoard = new Board(board->getRow(), board->getCol());
}

ComputerPlayer::~ComputerPlayer() {
  delete tempBoard;
}

Point* ComputerPlayer::doAMove() {
  if (rules->areThePlayerHasALegalMove(isWhite())) {
    list<Point*> listOfPointsComputer;
    listOfPointsComputer.clear();
    listOfPointsComputer = rules->theLegalMovesOfPlayer(isWhite());
    for (list<Point*>::iterator it = listOfPointsComputer.begin();
        it != listOfPointsComputer.end(); ++it) {

      delete (*it);
    }
  }
}

