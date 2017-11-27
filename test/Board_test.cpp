/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * Board_test.cpp
 *
 *  Created on: Nov 22, 2017
 *      Author: oriel
 */

#include "../gtest_src/gtest/gtest.h"
#include "../src/Board.h"
#define R1 8
#define C1 8
#define R2 2
#define C2 2
Board b3 = Board(3, 3);

// Check Out Of Range of initiation of Board
TEST(BoardTest, CheckOutOfRangeIntial) {
  EXPECT_THROW(b3 = Board(-2, -2), std::range_error);
  EXPECT_THROW(b3 = Board(0, 0), std::range_error);
  EXPECT_THROW(b3 = Board(1, 1), std::range_error);
}

Board b1 = Board(R1, C1);
Board b2 = Board(R2, C2);

// Check set value to Out Of Range of Board
TEST(BoardTest, CheckOutOfRangeSet) {
  EXPECT_THROW(b2.setValueAt(-2, 0, W), std::range_error);
  EXPECT_THROW(b2.setValueAt(0, -2, W), std::range_error);
  EXPECT_THROW(b2.setValueAt(R2, 0, W), std::range_error);
  EXPECT_THROW(b2.setValueAt(0, C2, W), std::range_error);
}

//Check the method int countSquaresOfPlayer(bool isWhite)
TEST(BoardTest, CountSquaresOfPlayer) {
  b2.initialBoard();
  EXPECT_EQ(b2.countSquaresOfPlayer(true), 2) << "the initial of b2 is wrong";
  EXPECT_EQ(b2.countSquaresOfPlayer(false), 2) << "the initial of b2 is wrong";
}

TEST(BoardTest, CountSquaresAfterSetElement) {
  b1.initialBoard();
  b1.setValueAt(0, 0, W);
  EXPECT_EQ(b1.countSquaresOfPlayer(true), 3) << "the countSquaresOfPlayer"
  " is wrong";
  b1.setValueAt(0, 0, B);
  EXPECT_EQ(b1.countSquaresOfPlayer(false), 3) << "the countSquaresOfPlayer"
  " is wrong";

}

//Check the method Square getValueAt(int i, int j)
TEST(BoardTest, getValueAtExistsValue) {
  b1.initialBoard();
  EXPECT_EQ(b1.getValueAt(R1 / 2, C1 / 2), W);
  EXPECT_EQ(b1.getValueAt(R1 / 2, C1 / 2), W);
  EXPECT_EQ(b1.getValueAt(R1 / 2 - 1, C1 / 2), B);
  EXPECT_EQ(b1.getValueAt(R1 / 2, C1 / 2 - 1), B);

}

TEST(BoardTest, getValueAtNonExistsValue) {
  EXPECT_EQ(b1.getValueAt(0, 0), N);

}

TEST(BoardTest, getValueAtOutOfRange) {
  EXPECT_EQ(b1.getValueAt(-1, 0), E);
  EXPECT_EQ(b1.getValueAt(0, C1), E);

}

//Check the method bool checkValueAt(bool isWhite, int i, int j)
TEST(BoardTest, checkValueAtExistsValue) {
  b1.initialBoard();
  EXPECT_TRUE(b1.checkValueAt(true, R1 / 2, C1 / 2));
  EXPECT_TRUE(b1.checkValueAt(false, R1 / 2 -1, C1 / 2));

}

TEST(BoardTest, checkValueAtNonExistsValue) {
  b1.initialBoard();
  EXPECT_FALSE(b1.checkValueAt(true, 0, 0));
}

TEST(BoardTest, checkValueAtOutOfRange) {
  b1.initialBoard();
  EXPECT_FALSE(b1.checkValueAt(true, -1, 0));
  EXPECT_FALSE(b1.checkValueAt(true, 0, C1));
}
//TODO need to add stress tests
