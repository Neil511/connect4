#include "controller.hpp"
#include "display.hpp"
#include "board.hpp"
#include "player.hpp"
#include "human.hpp"
#include <cstdlib>
#include <iostream>
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
  display = std::make_shared<Display>();
}

void Controller::updateViews(int turn, int move){
  if(move < 1 || move > 6) cout << "Move range error!" << endl;
  std::vector<int> numFilled = board->getNumFilled();
  display->updateBoard(numFilled.at(move - 1), move, turn);
}

void Controller::makeGame(){
  // TODO
  // Call makeDisplay in this function?
  makeDisplay();
  board = std::make_shared<Board>();
  p1 = std::make_shared<Human>(1, board, display);
  p2 = std::make_shared<Human>(2, board, display);
}

void Controller::playGame(){
  // while(!board->checkWin()) {
    // while game is  going on do game logic
    // render stuff here
  sf::Event event;
  sf::RenderWindow* window = display->getWindow();
  while(display->isWindowOpen()) {

    while (window->pollEvent(event)) {
      // std::cout << "triggered!" << std::endl;
      if(event.type == sf::Event::Closed) {
        std::cout << "triggered inside!" << std::endl;
        window->close();
      }
    }

    display->render();
    int move = p1->getMove();
    cout << move << endl;
    if(board->isValid(move)) {
      board->makeMove(turn, move);
      updateViews(turn, move);
    }
  }
    // cout << move << endl;
    // board->makeMove(1, move);
    // updateViews();
  //}
  // TODO
  // handles the majority of controller logic
  // turn handling
  // checking win conditions
  // updating and resetting board
  // updating score
}
