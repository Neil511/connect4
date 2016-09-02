#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

class Display;
class Board;
class Controller {
  int turn; // first turn is p1 then rotates score1 + score2 % 2
  int score1, score2;
  Board* board; // this should be a shared ptr
  Display* display; // this one should be unique ptr
public:
  Controller();
  void makeDisplay();
  void updateViews();
  void makeGame();
  void playGame();
};

#endif
