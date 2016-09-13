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

  // Font
  sf::Font arial;
  font = arial;
  font.loadFromFile("arial.ttf");
  // Text
  // Score
  sf::Text temp1("1", font);
  score1 = temp1;
  score1.setCharacterSize(70);
  score1.setStyle(sf::Text::Bold);
  score1.setColor(sf::Color::Red);
  score1.setPosition(300, 10);

  sf::Text temp2("2", font);
  score2 = temp2;
  score2.setCharacterSize(70);
  score2.setStyle(sf::Text::Bold);
  score2.setColor(sf::Color::Blue);
  score2.setPosition(400, 10);
  // Turn
  sf::Text turn("Player 1's turn", font);
  turn.setCharacterSize(70);
  turn.setStyle(sf::Text::Bold);
  turn.setColor(sf::Color::Green);
  turn.setPosition(120, 100);
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
    window.draw(score1);
    window.draw(score2);
    window.display();
}

sf::RenderWindow* Display::getWindow() {
  return &window;
}
