#include "core/app.h"

#include <algorithm>
#include <iostream>

#include "assets/texture.h"

App::App() {

  int bestBPP = 0;

  modes_ = sf::VideoMode::getFullscreenModes();

  for (auto it: modes_) {
    if (it.bitsPerPixel > bestBPP) bestBPP = it.bitsPerPixel;
  }

  modes_.erase(
      std::remove_if(
          modes_.begin(),
          modes_.end(),
          [bestBPP](sf::VideoMode mode) { return mode.bitsPerPixel != bestBPP; }),
      modes_.end());

  for (auto it: modes_) {
    std::cout << it.width << " " << it.height << std::endl;
  }

  window.create(modes_[0], "CroTron");
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
