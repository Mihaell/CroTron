#include <SFML/Graphics.hpp>

#include "config.h"

int main(int argc, const char* argv[]) {
  sf::RenderWindow window(sf::VideoMode(960, 510), "CroTron");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed)
        window.close();

    window.clear();
    window.display();
  }

  return 0;
}
