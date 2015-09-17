#include "core/app.h"

#include <algorithm>
#include <iostream>

#include "assets/texture.h"
#include "core/window_manager.h"

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

  bool running = true;

  while (running) {
    sf::Event event;
    while (WindowManager::PollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        WindowManager::CloseWindow();
        running = false;
      }
    }
    WindowManager::Clear();
    WindowManager::Draw(sprite);
    WindowManager::Display();
  }
}

