#ifndef __DISPLAY_H__
#define __DISPLAY_H__
#include <SFML/Graphics.hpp>
#include <string>

class Display {
  sf::RenderWindow window;
  std::vector<std::vector<sf::CircleShape>> board;
  sf::Font font;
  sf::Text score1, score2;
public:
  Display();
  void updateBoard(int row, int column, int turn);
  bool isWindowOpen();
  void render();
  sf::RenderWindow* getWindow();
};
#endif
