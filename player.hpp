#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <memory>
class Board;
class Player {
protected:
  int playerNumber; // CPU will always be p2
  std::shared_ptr<Board> board;
public:
  Player(int number, std::shared_ptr<Board> board);
  virtual int getMove() = 0; // all players are either human or CPU
};

#endif
