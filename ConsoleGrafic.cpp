/*
 * name :   oriel sabban
 * id   :   201052602
 * ConsoleGrafic.cpp
 *
 *  Created on: Oct 31, 2017
 *      Author: oriel
 */

#include "ConsoleGrafic.h"

ConsoleGrafic::ConsoleGrafic(Board* board) :
    Grafic(board) {

}

ConsoleGrafic::~ConsoleGrafic() {
}

void ConsoleGrafic::printNotPossibleMoves(bool isWhite) const {
  printTheBoard();
  if (isWhite) {
    printAMessage("No possible moves."
        " play passes back to the black player.\n");
  } else {
    printAMessage("No possible moves."
        " play passes back to the white player.\n");
  }
}

void ConsoleGrafic::printAnErrorInputNotANum() const {
  printAMessage("please insert only numbers not other characters\n");

}

void ConsoleGrafic::printAnErrorInputNotLegal(Point* point) const {
  char message[256];
  sprintf(message,
      "the point (%d,%d) is not legal, please enter a legal point\n",
      point->getX() + 1, point->getY() + 1);
  printAMessage(message);

}

void ConsoleGrafic::printTheNewMove(const bool isWhite,
    list<Point*> listOfPoints) const {
  printTheBoard();
  if (isWhite) {
    printAMessage("O: It's your move\n");
  } else {
    printAMessage("X: It's your move\n");
  }
  printTheLegalMoves(listOfPoints);

}

void ConsoleGrafic::printTheWiner(bool theWinerIsWhite,
    bool theWinerIsBlack) const {
  cout << "\n\n\n\n\n\n\n\n";
  printTheBoard();
  if (theWinerIsWhite && theWinerIsBlack) {
    cout << "\n\n Draw! \n the two players got the same number"
        " of discs, congratulations!!!";
  } else if (theWinerIsWhite) {
    cout << "White wins! \n congratulations!!!\n";
  } else if (theWinerIsBlack) {
    cout << "Black wins! \n congratulations!!!\n";
  }
}

void ConsoleGrafic::printTheLegalMoves(list<Point*> listOfPoints) const {
  cout << "the possible moves: ";
  for (list<Point*>::iterator it = listOfPoints.begin();
      it != listOfPoints.end(); ++it) {
    cout << "(" << (*it)->getX() + 1 << "," << (*it)->getY() + 1 << ") ";
    delete (*it);
  }
  cout << "\n\n please enter your move row col: "
      "(With a space between the row and the col)\n";
}
void ConsoleGrafic::printAMessage(string message) const {
  cout << message;
}
void ConsoleGrafic::printTheBoard() const {
  printAMessage("\n\n current board:\n\n");
  int row = board->getRow();
  int col = board->getCol();
  for (int i = 0; i <= row; i++) {
    if (i == 0) {
      cout << " |";
      for (int j = 0; j < col; j++) {
        cout << " " << j + 1 << " |";
      }
      cout << endl;
      cout << "--";
      for (int j = 0; j < col; j++) {
        cout << "----";
      }
      cout << endl;
      continue;
    }
    for (int j = 0; j <= col; j++) {
      if (!j) {
        cout << i << "|";
        continue;
      }
      switch (board->getValueAt(i - 1, j - 1)) {
      case N:
        cout << "   |";
        break;
      case W:
        cout << " o |";
        break;
      case B:
        cout << " x |";
        break;
      case E:
        break;
      }
    }
    cout << endl;
    cout << "--";
    for (int j = 0; j < col; j++) {
      cout << "----";
    }
    cout << endl;
  }

}
