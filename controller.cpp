#include "controller.hpp"
#include <cstdlib>
using namespace std;

Controller::Controller(): turn(1), score1(0), score2(0), game(NULL), display(NULL){}

Controller::~Controller(){
  if(game) {
    delete game;
    game = NULL;
  }
  delete display;
  display = NULL;
}

void Controller::makeDisplay(){
  if(display) {
    // TODO
  }
}

void Controller::updateViews(){
  // TODO
}

void Controller::makeGame(){
  // TODO
}

void Controller::playGame(){
  // TODO
  // handles the majority of controller logic
  // turn handling
  // checking win conditions
  // updating and resetting board
  // updating score
}
