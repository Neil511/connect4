#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "player.hpp"
class Display;
class Human: public Player {
  Display* display;
public:
  Human(int playerNumber, Board* board, Display* display);
  int getMove();
};

#endif
