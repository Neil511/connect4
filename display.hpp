#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <SFML/Graphics.hpp>
#include <string>

class Display {
  sf::RenderWindow window(sf::VideoMode(800, 900), "Connect Four");
  std::vector<std::vector<sf::CircleShape>> board;
public:
  Display();
  void updateBoard(int column, int turn);
  bool isWindowOpen();
};
#endif
