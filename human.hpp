#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "player.hpp"
class Display;
class Human: public Player {
  std::shared_ptr<Display> display;
public:
  Human(int playerNumber, std::shared_ptr<Board> board, std::shared_ptr<Display> display);
  int getMove();
};

#endif
