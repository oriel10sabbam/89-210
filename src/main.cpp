/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * main.cpp
 *
 *  Created on: Oct 24, 2017
 *      Author: oriel
 */

#include "Board.h"
#include "Game.h"
#include "UserPlayer.h"
#include "ComputerPlayer.h"
#include "RemotePlayer.h"
#include "ConsoleGrafic.h"
#include "StandartRules.h"
#include "Client.h"
#define ROW 4
#define COL 4

int main() {
  Board* board = new Board(ROW, COL);
  Rules* rules = new StandartRules();
  Grafic* grafic = new ConsoleGrafic(board);
  TheRival theRival = grafic->printTheMenu();
  Player* whitePlayer;
  Player* blackPlayer;
  Client client("127.0.0.1"/*"95.86.112.226"*/, 10008);
  Client* pClient = &(client);

  bool isRemoteGame = false;

  if (theRival == C) {
    whitePlayer = new ComputerPlayer(true, board, rules);
    blackPlayer = new UserPlayer(false);

  } else if (theRival == H) {
    whitePlayer = new UserPlayer(true);
    blackPlayer = new UserPlayer(false);

  } else {
    isRemoteGame = true;
    grafic->printAMessage("connected to server \n");
    grafic->printAMessage("waiting for other player to join.. \n");
    int whiteOrBlack = client.connectToServer();

    if (whiteOrBlack == 1) {
      blackPlayer = new UserPlayer(false);
      whitePlayer = new RemotePlayer(true, client);

    } else {
      whitePlayer = new UserPlayer(true);
      blackPlayer = new RemotePlayer(false, client);

    }
  }
  Game game = Game(whitePlayer, blackPlayer, board, rules, grafic, pClient);
  game.startTheGame(isRemoteGame);
  delete whitePlayer;
  delete blackPlayer;
  delete board;
  delete rules;
  delete grafic;

  return 0;
}
