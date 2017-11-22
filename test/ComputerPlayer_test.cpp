/*
 * ComputerPlayer_test.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: oriel
 */

#include "gtest/gtest.h"
#include "ComputerPlayer.h"
#include "Point.h"
#include <list>
#define R1 8
#define C1 8
#define R2 2
#define C2 2
using namespace std;

Board b1 = Board(R1, C1);
StandartRules sRules = StandartRules();
ComputerPlayer cP1 = ComputerPlayer(true, *b1, *sRules);

bool checkIfPointInList(Point p, list<Point> listOfPoints) {
  return (find(listOfPoints.begin(), listOfPoints.end(), p)
      != listOfPoints.end());
}

//Check the method Point doAMove();
//Check when the computer player has 1 option
TEST(ComputerPlayerTest, doAMove1Option) {
  b1.initialBoard();
  b1.setValueAt(4, 4, B);
  b1.setValueAt(4, 3, W);
  b1.setValueAt(5, 3, W);
  Point p = cP1.doAMove();
  list<Point> listOfPoints;
  listOfPoints.clear();
  listOfPoints.push_back(Point(3, 5));
  EXPECT_TRUE(checkIfPointInList(p, listOfPoints));
}

//Check when the computer player has 2 option
TEST(ComputerPlayerTest, doAMove2Options) {
  b1.initialBoard();
  b1.setValueAt(2, 3, B);
  b1.setValueAt(3, 3, B);
  Point p = cP1.doAMove();
  list<Point> listOfPoints;
  listOfPoints.clear();
  listOfPoints.push_back(Point(2, 2));
  listOfPoints.push_back(Point(4, 2));
  EXPECT_TRUE(checkIfPointInList(p, listOfPoints));
}

//Check when the computer player has Non option
TEST(ComputerPlayerTest, doAMoveNonOptions) {
  b1.initialBoard();
  b1.setValueAt(4, 4, B);
  b1.setValueAt(3, 3, B);
  Point p = cP1.doAMove();
  list<Point> listOfPoints;
  listOfPoints.clear();
  listOfPoints.push_back(Point(-1, -1));
  EXPECT_TRUE(checkIfPointInList(p, listOfPoints));
}

//Check when the computer player has Non option
TEST(ComputerPlayerTest, doAMoveNonOptions2) {
  b1.initialBoard();
  b1.setValueAt(4, 4, N);
  b1.setValueAt(3, 3, N);
  b1.setValueAt(3, 4, N);
  b1.setValueAt(4, 3, N);
  Point p = cP1.doAMove();
  list<Point> listOfPoints;
  listOfPoints.clear();
  listOfPoints.push_back(Point(-1, -1));
  EXPECT_TRUE(checkIfPointInList(p, listOfPoints));
}
