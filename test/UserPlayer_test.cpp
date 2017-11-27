/*
 * UserPlayer_test.cpp
 *
 *  Created on: Nov 26, 2017
 *      Author: guyzach
 */


#include "gtest/gtest.h"
#include "UserPlayer.h"
#include "Point.h"
#define R1 8
#define C1 8
using namespace std;

//Check the method Point isDigit();
TEST(UserPlayerTest, isDigitChack) {
	UserPlayer uP = UserPlayer();
	string str1="1234567890";
	string str2="`~!@#$%^&*()_+[]\{}|'/;.,?:>< ";
	string str3="abcdefghijklmnopqrstuvwxyz";
	string str4="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	string str5="123456789x";
	string str6="x234567890";
	string str7="12345x7890";
	string str8="-7";
	uP.isDigit(str1);
	EXPECT_TRUE(uP.isDigit(str1));
	uP.isDigit(str2);
	EXPECT_FALSE(uP.isDigit(str2));
	uP.isDigit(str3);
	EXPECT_FALSE(uP.isDigit(str3));
	uP.isDigit(str4);
	EXPECT_FALSE(uP.isDigit(str4));
	uP.isDigit(str5);
	EXPECT_FALSE(uP.isDigit(str5));
	uP.isDigit(str6);
	EXPECT_FALSE(uP.isDigit(str6));
	uP.isDigit(str7);
	EXPECT_FALSE(uP.isDigit(str7));
	uP.isDigit(str8);
	EXPECT_FALSE(uP.isDigit(str8));
}
