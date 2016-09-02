#include "controller.hpp"
#include <cstdlib>
using namespace std;

Controller::Controller(): turn(1), score1(0), score2(0), board(nullptr), display(nullptr){}

void Controller::makeDisplay(){
  if(display) {
    // TODO
    // Create window and draw basics
  }
  // If it doesn't already exist
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
