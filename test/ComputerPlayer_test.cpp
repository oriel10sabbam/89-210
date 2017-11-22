/*
 * ComputerPlayer_test.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: oriel
 */

#include "gtest/gtest.h"
#include "ComputerPlayer.h"
#include "StandartRules.h"
#include "Board.h"
#include "Point.h"
#include <list>
#define R1 8
#define C1 8
using namespace std;

bool checkIfPointInList(Point p, list<Point> listOfPoints) {
  for (list<Point>::iterator it = listOfPoints.begin();
      it != listOfPoints.end(); ++it) {
    if ((p.getX() == it->getX()) && (p.getY() == it->getY())) {
      return true;
    }
  }
  return false;
}
//Check the method Point doAMove();
//Check when the computer player has 1 option
TEST(ComputerPlayerTest, doAMove1Option) {
  Board b3 = Board(R1, C1);
  StandartRules sRules = StandartRules();
  ComputerPlayer cP1 = ComputerPlayer(true, &b3, &sRules);
  b3.setValueAt(4, 4, B);
  b3.setValueAt(4, 3, W);
  b3.setValueAt(5, 3, W);

  Point p = cP1.doAMove();
  list< Point> listOfPoints;
  listOfPoints.clear();
  Point p1 = Point(3, 5);
  listOfPoints.push_back(p1);
  EXPECT_TRUE(checkIfPointInList(p, listOfPoints)) << "the wrong Point is ("
  << p.getX() << "," << p.getY() << ")";

}

//Check when the computer player has 2 option
TEST(ComputerPlayerTest, doAMove2Options) {
  Board b3 = Board(R1, C1);
  StandartRules sRules = StandartRules();
  ComputerPlayer cP1 = ComputerPlayer(true, &b3, &sRules);
  b3.setValueAt(2, 3, B);
  b3.setValueAt(3, 3, B);
  Point p = cP1.doAMove();
  list< Point> listOfPoints;
  listOfPoints.clear();
  Point p1 = Point(2, 2);
  Point p2 = Point(4, 2);
  listOfPoints.push_back(p1);
  listOfPoints.push_back(p2);
  EXPECT_TRUE(checkIfPointInList(p, listOfPoints));
}

//Check when the computer player has Non option
TEST(ComputerPlayerTest, doAMoveNonOptions) {
  Board b3 = Board(R1, C1);
  StandartRules sRules = StandartRules();
  ComputerPlayer cP1 = ComputerPlayer(true, &b3, &sRules);
  b3.initialBoard();
  b3.setValueAt(4, 4, B);
  b3.setValueAt(3, 3, B);
  Point p = cP1.doAMove();
  list< Point> listOfPoints;
  listOfPoints.clear();
  Point p1 = Point(-1, -1);
  listOfPoints.push_back(p1);
  EXPECT_TRUE(checkIfPointInList(p, listOfPoints));
}

//Check when the computer player has Non option
TEST(ComputerPlayerTest, doAMoveNonOptions2) {
  Board b3 = Board(R1, C1);
  StandartRules sRules = StandartRules();
  ComputerPlayer cP1 = ComputerPlayer(true, &b3, &sRules);
  b3.setValueAt(4, 4, N);
  b3.setValueAt(3, 3, N);
  b3.setValueAt(3, 4, N);
  b3.setValueAt(4, 3, N);
  Point p = cP1.doAMove();
  list< Point> listOfPoints;
  listOfPoints.clear();
  Point p1 = Point(-1, -1);
  listOfPoints.push_back(p1);
  EXPECT_TRUE(checkIfPointInList(p, listOfPoints));
}
