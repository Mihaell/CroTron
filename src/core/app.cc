#include "core/app.h"

#include <algorithm>
#include <iostream>

#include "assets/texture.h"

sf::RenderWindow App::window_;

App::App() {

  int best_BPP = 0;

  modes_ = sf::VideoMode::getFullscreenModes();

  for (auto it: modes_) {
    if (it.bitsPerPixel > best_BPP) best_BPP = it.bitsPerPixel;
  }

  modes_.erase(
      std::remove_if(
          modes_.begin(),
          modes_.end(),
          [best_BPP](sf::VideoMode mode) { return mode.bitsPerPixel != best_BPP; }),
      modes_.end());

  std::cout << "Available resolutions:" << std::endl;
  for (auto it: modes_) {
    std::cout << it.width << " " << it.height << std::endl;
  }

  window_.create(modes_[0], "CroTron");
  ResetViewport();
}

App::~App() {

}


void App::Run() {

  Texture::Load("CROTRON_LOGO", "data/textures/crotron.png");

  sf::Sprite sprite;
  sprite.setTexture(*Texture::Get("CROTRON_LOGO"));
  sprite.setPosition(100, 100);

  while (window_.isOpen()) {
    sf::Event event;
    while (window_.pollEvent(event))
      if (event.type == sf::Event::Closed)
        window_.close();

    window_.clear();
    window_.draw(sprite);
    window_.display();
  }
}


void App::ResetViewport() {

  const float WIDTH_RATIO = 16.0;
  const float HEIGHT_RATIO = 9.0;

  sf::Vector2u sz = window_.getSize();

  float min_ratio = std::min(sz.x / WIDTH_RATIO, sz.y / HEIGHT_RATIO);
  float max_w_pixels = min_ratio * WIDTH_RATIO;
  float max_h_pixels = min_ratio * HEIGHT_RATIO;

  float max_w = max_w_pixels / sz.x;
  float max_h = max_h_pixels / sz.y;

  sf::View view;
  view.setViewport(sf::FloatRect(0.5 - max_w / 2.0, 0.5 - max_h / 2.0,
                                 0.5 + max_w / 2.0, 0.5 + max_h / 2.0));

  std::cout << max_w << " " << max_h << std::endl;
  std::cout << 0.5 - max_w / 2.0 << " " << 0.5 - max_h / 2.0 << " " << 0.5 + max_w / 2.0 << " " << 0.5 + max_h / 2.0 << std::endl;

  window_.setView(view);
}
