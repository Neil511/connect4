#ifndef __CPU_H__
#define __CPU_H__

#include "player.hpp"
#include <vector>

class CPU: public Player {
  const int level; // between 1 to 4
public:
  CPU(int playerNumber, std::shared_ptr<Board> board, int level);
  int getMove();
};

#endif
