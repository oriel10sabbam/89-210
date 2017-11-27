/*
 * names: oriel sabban, guy zach
 * id's:  201052602, 203953195
 *
 * Game_test.cpp
 *
 *  Created on: Nov 27, 2017
 *      Author: guyzach
 */

#include "../gtest_src/gtest/gtest.h"
#include "../src/StandartRules.h"
#include "../src/ComputerPlayer.h"
#include "../src/Game.h"
#include "../src/Board.h"
#include "../src/Grafic.h"
#include "../src/Point.h"
#include <list>
#define R1 8
#define C1 8
using namespace std;
//Check the method bool playOneTurn(Player* player, Point& point, bool& isTheWhiteMove)
TEST(GameTest,playOneTurn1){
	Point theMoveToCheck=Point(5,3);
	Board theExpectedBoard = Board(R1, C1);
	theExpectedBoard.setValueAt(5,3,W);
	theExpectedBoard.setValueAt(5,4,W);

	Board b3 = Board(R1, C1);
	StandartRules sRules = StandartRules();
	ComputerPlayer cP1 = ComputerPlayer(true, &b3, &sRules);
	ComputerPlayer cP2 = ComputerPlayer(false, &b3, &sRules);
	Grafic* gr;
	Game g = Game(&cP1,&cP2,&b3,&sRules,gr);
	bool isTheWhiteMove=true;

    //bool b=g.playOneTurn(&cP1, theMoveToCheck, isTheWhiteMove);

    for(int i=0;i<R1;i++){
    	for(int j=0;j<C1;j++){
    		EXPECT_EQ(theExpectedBoard.getValueAt(i,j),b3.getValueAt(i,j));
    	}
    }
}
