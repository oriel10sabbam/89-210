/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 * Game.cpp
 *
 *  Created on: Oct 29, 2017
 *      Author: oriel
 */

#include "Game.h"
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <unistd.h>
const long int MAX = 256;

Game::~Game() {

}

Game::Game(Player* wPlayer, Player* bPlayer, Board* board1, Rules* rules1,
    Grafic* grafic1, Client* client1) {
  whitePlayer = wPlayer;
  blackPlayer = bPlayer;
  board = board1;
  rules = rules1;
  grafic = grafic1;
  client = client1;
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

bool Game::playOneRemoteTurn(Player* player, Point& point,
    bool& isTheWhiteMove) {

  if (!player->isRemote()) {

    if (rules->areThePlayerHasALegalMove(player->isWhite(), board)) {

      list < Point > listOfPoints = rules->theLegalMovesOfPlayer(
          player->isWhite(), board);
      grafic->printTheNewMove(player->isWhite(), listOfPoints, point);
      listOfPoints.clear();
      point = player->doAMove();
      if (point.getX() != -1) {
        if (rules->checkIfIsALegalMove(player->isWhite(), point, board)) {
          board->updateTheBoard(point, player->isWhite());
          // sending to the remote player the move
          try {
            std::stringstream xMessage;
            std::stringstream yMessage;
            xMessage << point.getX();
            yMessage << point.getY();

            string MessageS = "play " + xMessage.str() + " " + yMessage.str();

            client->sendCharMessage(MessageS);
          } catch (const char * msg) {
            cout << "error send Message. Reason: " << msg << endl;
            exit(-1);
          }

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

      try {
        client->sendCharMessage("play NoMove NoMove");
      } catch (const char * msg) {
        cout << "error send Message. Reason: " << msg << endl;
        exit(-1);
      }

      isTheWhiteMove = !player->isWhite();
      return true;
    } else {
      // send -2 that means end of game
      try {
//        client->sendMessage(-2);
        client->sendCharMessage("close");
        return false;
      } catch (const char * msg) {
        cout << "error send Message. Reason: " << msg << endl;
        exit(-1);
      }
    }
  } else {
    if ((!rules->areThePlayerHasALegalMove(player->isWhite(), board))
        && (!rules->areThePlayerHasALegalMove(!player->isWhite(), board))) {
//      sleep(2);
      return false;
    }
    Point newPoint = Point(-20, -20);
    grafic->printRemoteScreen();
    newPoint = player->doAMove();
    // if newPoint.getX() == -10 that means not possible move for the
    // remote player
    if (newPoint.getX() != -10) {
      point = newPoint;
      board->updateTheBoard(point, player->isWhite());
      remainingMoves--;
      isTheWhiteMove = !player->isWhite();
      return true;
    } else {
      grafic->printNotPossibleMoves(player->isWhite());
      isTheWhiteMove = !player->isWhite();
      return true;
    }

  }
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

void Game::startTheGame(bool isRemoteGame) {
  bool isTheWhiteMove = false;
  Point point = Point(-1, -1);
  bool weNeedToContinue = true;
  while (weNeedToContinue) {

    if (isTheWhiteMove && !isRemoteGame) {
      weNeedToContinue = playOneTurn(whitePlayer, point, isTheWhiteMove);

    } else if (isTheWhiteMove && isRemoteGame) {
      weNeedToContinue = playOneRemoteTurn(whitePlayer, point, isTheWhiteMove);

    } else if (!isTheWhiteMove && !isRemoteGame) {
      weNeedToContinue = playOneTurn(blackPlayer, point, isTheWhiteMove);

    } else if (!isTheWhiteMove && isRemoteGame) {
      weNeedToContinue = playOneRemoteTurn(blackPlayer, point, isTheWhiteMove);
    }
  }
  checkWhoWins();
}

