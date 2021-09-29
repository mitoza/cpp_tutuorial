// main.cpp
// SFML tutorial: https://www.sfml-dev.org/tutorials/2.5/
// Source: https://habr.com/ru/post/248153/
#include <iostream>

#include <SFML/Graphics.hpp>

const sf::Color white = sf::Color(255,255,255,255);
const sf::Color red = sf::Color(255,0,0,255);

int main(int argc, char** argv) {

  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Default);

  sf::CircleShape shape(100.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
  {
      sf::Event event;
      while (window.pollEvent(event))
      {
          if (event.type == sf::Event::Closed)
              window.close();
      }
      window.clear();
      window.draw(shape);
      //window.draw(image);
      window.display();
  }

  return 0;
}
