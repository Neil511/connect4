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
  
}

void Controller::updateViews(int turn, int move){
  if(move < 1 || move > 7) cout << "Move range error!" << endl;
  std::vector<int> numFilled = board->getNumFilled();
  display->updateBoard(numFilled.at(move - 1) - 1, move - 1, turn);
}

void Controller::makeGame(){
  try {
    display = std::make_shared<Display>();
    board = std::make_shared<Board>();
    p1 = std::make_shared<Human>(1, board, display);
    p2 = std::make_shared<Human>(2, board, display);
    board->printBoard();
    board->printNumFilled();
  }
  catch (...) {
    cout << "Breaking here! Line 40" << endl;
  }
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
      cout << "Inside the isValid in Controlla" << endl;
      board->makeMove(turn, move);
      updateViews(turn, move);
      board->printBoard();
      board->printNumFilled();
    }
  }
  //}
  // TODO
  // handles the majority of controller logic
  // turn handling
  // checking win conditions
  // updating and resetting board
  // updating score
}
