#include "human.hpp"
#include "display.hpp"
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
Human::Human(int playerNumber, Board* board, Display* display): Player(playerNumber, board), display(display) {}

int Human::getMove() {
  sf::RenderWindow* window = display->getWindow();
  int xPos, yPos;
  while(true) {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      // get global mouse position
      sf::Vector2i position = sf::Mouse::getPosition(*window);
      xPos = position.x ;
      yPos = position.y;
      cout << xPos << " " << yPos << endl;
    }
    if(yPos >= 200) {
      if(xPos >= 20 && xPos <= 120) return 1;
      else if(xPos >= 130 && xPos <= 230) return 2;
      else if(xPos >= 240 && xPos <= 340) return 3;
      else if(xPos >= 350 && xPos <= 450) return 4;
      else if(xPos >= 460 && xPos <= 560) return 5;
      else if(xPos >= 570 && xPos <= 670) return 6;
      else if(xPos >= 680 && xPos <= 780) return 7;
    }
  }
}
