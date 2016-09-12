#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

class Board;
class Display;
class Player;
class Controller {
  int turn; // first turn is p1 then rotates score1 + score2 % 2
  int score1, score2;
  Board* board; // this should be a shared ptr
  Display* display; // this one should be unique ptr
  Player* p1, * p2;
public:
  Controller();
  void makeDisplay();
  void updateViews(int turn, int move);
  void makeGame();
  void playGame();
};

#endif
