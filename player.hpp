#ifndef __PLAYER_H__
#define __PLAYER_H__
class Board;
class Player {
protected:
  int playerNumber; // CPU will always be p2
  Board* board;
public:
  Player(int number, Board* board);
  virtual int getMove() = 0; // all players are either human or CPU
};

#endif
