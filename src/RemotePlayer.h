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
   * isRemote - returm true if it's the remote player
   */
  virtual bool isRemote();

private:
  Client client;
};

#endif /* SRC_REMOTEPLAYER_H_ */
