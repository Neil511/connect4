#include "controller.hpp"
#include "display.hpp"
#include "board.hpp"
#include "player.hpp"
#include <cstdlib>
using namespace std;

Controller::Controller() {
  turn = 1;
  score1 = 0;
  score2 = 0;
  board = nullptr;
  display = nullptr;
  p1 = nullptr;
  p2 = nullptr;
}

void Controller::makeDisplay(){
  // if(display) {
  //   // TODO
  //   // Don't know what this is for, new games?
  // }
  // If it doesn't already exist
  display = new Display();
}

void Controller::updateViews(){
  // TODO
  // Shouldn't this accept some parameters?
}

void Controller::makeGame(){
  // TODO
  // Call makeDisplay in this function?
  makeDisplay();
  board = new Board();
}

void Controller::playGame(){
  // while(!board->checkWin()) {
    // while game is  going on do game logic
    // render stuff here
    display->render();
  //}
  // TODO
  // handles the majority of controller logic
  // turn handling
  // checking win conditions
  // updating and resetting board
  // updating score
}
