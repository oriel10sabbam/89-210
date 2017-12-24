/*
 * RemotePlayer.h
 *
 *  Created on: Dec 5, 2017
 *      Author: oriel
 */

#ifndef SRC_REMOTEPLAYER_H_
#define SRC_REMOTEPLAYER_H_
#include "Client.h"
#include "Player.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <iterator>
#include <errno.h>
#include <string>
#include <list>
#include <vector>

using namespace std;

/*
 * this class represent the RemotePlayer, this class heir from the Player class
 */
class RemotePlayer: public Player {
public:

  RemotePlayer(bool isWhite, Client& client);

  virtual ~RemotePlayer();
  /*
   * DoAMove - the Player Do A Move, a virtual pure method
   */
  virtual Point doAMove();

  /*
   * isRemote - return true if it's the remote player
   */
  virtual bool isRemote();

private:
  Client client;

  /*
   * splitBySpace - split string by space
   * @ param str- the string to split
   * @ return - the value of split in vector
   *
   */
  vector<int> splitBySpace(string str);

};

#endif /* SRC_REMOTEPLAYER_H_ */
