#include "human.hpp"
#include "display.hpp"
#include <SFML/Window.hpp>
#include <iostream>
using namespace std;
Human::Human(int playerNumber, Board* board, Display* display): Player(playerNumber, board), display(display) {}

int Human::getMove() {
  // TODO
  sf::RenderWindow* window = display->getWindow();
  if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
    // get global mouse position
    sf::Vector2i position = sf::Mouse::getPosition(*window);
    cout << position.x << " " << position.y << endl;
  }
}
