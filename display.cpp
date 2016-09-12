#include "display.hpp"
#include <iostream>
using namespace std;
Display::Display(): window(sf::VideoMode(800, 900), "Connect Four") {
  for (int i = 0; i < 6; ++i) {
    std::vector<sf::CircleShape> row;
    for (int j = 0; j < 7; ++j) {
      sf::CircleShape circle;
      circle.setRadius(50);
      circle.setPosition(110 * j + 20, 110 * i + 200);
      circle.setFillColor(sf::Color::Green);
      row.emplace_back(circle);
    }
    board.emplace_back(row);
  }
}

bool Display::isWindowOpen(){
  return window.isOpen();
}

void Display::updateBoard(int row, int column, int turn) {
  cout << "Turn: " << turn << endl;
  sf::CircleShape& circle = board.at(5 - row).at(column);
  if(turn == 1) circle.setFillColor(sf::Color::Red);
  else circle.setFillColor(sf::Color::Red);
}

void Display::render() {
    window.clear();
    for(int i = 0; i < 6; ++i) {
      for(int j = 0; j < 7; ++j) {
        window.draw(board.at(i).at(j));
      }
    }
    window.display();
}

sf::RenderWindow* Display::getWindow() {
  return &window;
}
