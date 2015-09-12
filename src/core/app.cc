#include "core/app.h"

App::App() {

  window.create(sf::VideoMode(960, 510), "CroTron");

}

void App::Run() {

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed)
        window.close();

    window.clear();
    window.display();
  }

}
