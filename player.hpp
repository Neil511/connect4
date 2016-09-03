#ifndef __PLAYER_H__
#define __PLAYER_H__
class Board;
class Player {
  int playerNumber;
  Board* board;
public:
  Player(int number, Board* board);
  virtual int getMove() = 0; // all players are either human or CPU
};

#endif
