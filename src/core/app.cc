#include "core/app.h"

#include <algorithm>
#include <iostream>

#include "core/state_manager.h"
#include "core/window_manager.h"
#include "states/game_state.h"

App::App() {
  WindowManager::InitWindow();
}

App::~App() {
}


void App::Run() {
  bool running = true;

  StateManager state_manager;
  state_manager.PushStateToStack(move(std::unique_ptr<StateInterface>(new GameState)));

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
    StateManager::DrawStack();
    WindowManager::Display();
  }
}

