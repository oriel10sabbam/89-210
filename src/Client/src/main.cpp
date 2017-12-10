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
#include<fstream>
#include <string.h>
#include <iostream>

#define ROW 8
#define COL 8

int main() {
  Board* board = new Board(ROW, COL);
  Rules* rules = new StandartRules();
  Grafic* grafic = new ConsoleGrafic(board);
  TheRival theRival = grafic->printTheMenu();
  Player* whitePlayer;
  Player* blackPlayer;

  ifstream inFile;

  try {
    inFile.open("./definition_client.txt");
  } catch (const char * msg) {
    cout << "error open the definition_client.txt" << msg << endl;
    exit(-1);
  }

  int port;
  string ip;

  if (inFile.is_open()) {
    inFile >> port;
    inFile >> ip;
  } else {
    cout << "error open the definition_client.txt" << endl;
    exit(-1);
  }

  Client client(ip.c_str(), port);
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
    int whiteOrBlack;
    try {
      whiteOrBlack = client.connectToServer();
    } catch (const char * msg) {
      cout << "error at connect to server. Reason: " << msg << endl;
      return (-1);
    }

    if (whiteOrBlack == 1) {
      blackPlayer = new UserPlayer(false);
      whitePlayer = new RemotePlayer(true, client);

    } else {
      whitePlayer = new UserPlayer(true);
      blackPlayer = new RemotePlayer(false, client);

    }
  }

  Game game = Game(whitePlayer, blackPlayer, board, rules, grafic, pClient);

  try {
    game.startTheGame(isRemoteGame);
  } catch (const char * msg) {
    cout << "error at play the Reversi Game. Reason: " << msg << endl;
    return (-1);
  }
  delete whitePlayer;
  delete blackPlayer;
  delete board;
  delete rules;
  delete grafic;

  return 0;
}
