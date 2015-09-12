#include "core/app.h"

#include <SFML/Graphics.hpp>

#include "assets/texture.h"

App::App() {
  window.create(sf::VideoMode(960, 510), "CroTron");
}

void App::Run() {
  Texture::Load("CROTRON_LOGO", "data/textures/crotron.png");

  sf::Sprite sprite;
  sprite.setTexture(*Texture::Get("CROTRON_LOGO"));
  sprite.setPosition(100, 100);

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed)
        window.close();

    window.clear();
    window.draw(sprite);
    window.display();
  }
}
