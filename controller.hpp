#ifndef __CONTROLLER_H__
#define __CONTROLLER_H__

class Game;
class Display;
class Controller {
  int turn; // first turn is p1 then rotates score1 + score2 % 2
  int score1, score2;
  Game* game;
  Display* display;
public:
  Controller();
};

#endif
