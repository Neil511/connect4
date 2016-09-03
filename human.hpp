#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "player.hpp"
class Human: public Player {
public:
  Human(int playerNumber, Board* board);
  int getMove();
};

#endif
