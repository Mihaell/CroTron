#include "core/app.h"

#include <algorithm>
#include <iostream>

#include "assets/texture.h"
#include "core/window_manager.h"
#include "interface/widget.h"

App::App() {
  WindowManager::InitWindow();
}

App::~App() {
}


void App::Run() {
  Texture::Load("CROTRON_LOGO", "data/textures/crotron.png");

  sf::Sprite sprite;
  sprite.setTexture(*Texture::Get("CROTRON_LOGO"));
  sprite.setPosition(100, 100);

  Widget* widget = new Widget(sf::Vector2f(50, 50), sf::Vector2f(200, 200));

  bool running = true;

  while (running) {
    sf::Event event;
    while (WindowManager::PollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        WindowManager::CloseWindow();
        running = false;
      }
    }
    // sljedeca linija je privremena da se testira window viewport
    WindowManager::Clear(sf::Color(40, 40, 40));
    sf::RectangleShape shape(sf::Vector2f(1280, 720));
    shape.setFillColor(sf::Color::Black);

    WindowManager::Draw(shape);
    WindowManager::Draw(sprite);
    widget->Draw();
    WindowManager::Display();
  }
}

