#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;


// compile as: g++ main.cpp -o main -lsfml-graphics -lsfml-window -lsfml-system
int main() {
  cout << "Hello world!" << endl;

  // Window
  sf::RenderWindow window(sf::VideoMode(800, 900), "Connect Four");

  sf::CircleShape* circles [6][7];
  for(int i = 0; i < 6; i++) {
    for(int j = 0; j < 7; j++) {
      sf::CircleShape* circle = new sf::CircleShape;
      circles[i][j] = circle;
      circle->setRadius(50);
      circle->setPosition(110 * j + 25, 110 * i + 200);
      if((i + j) % 2 == 0) circle->setFillColor(sf::Color::Blue);
      else circle->setFillColor(sf::Color::Red);
    }
  }
  // Font
  sf::Font font;
  font.loadFromFile("arial.ttf");
  // Text
  // Score
  sf::Text score1("1", font);
  score1.setCharacterSize(70);
  score1.setStyle(sf::Text::Bold);
  score1.setColor(sf::Color::Red);
  score1.setPosition(300, 10);

  sf::Text score2("1", font);
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

  while (window.isOpen())
  {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
      // get global mouse position
      sf::Vector2i position = sf::Mouse::getPosition(window);
      cout << position.x << " " << position.y << endl;
    }
      sf::Event event;
      while (window.pollEvent(event)) // TODO: Look at docs
      {
          if (event.type == sf::Event::Closed)
              window.close();
      }

      window.clear();

      // Drawing the shapes onto the display
      for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 7; j++) {
          window.draw(*(circles[i][j]));
        }
      }
      window.draw(score1);
      window.draw(score2);
      window.draw(turn);
      // Displays it
      window.display();
  }

  return 0;
}
