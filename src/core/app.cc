#include "core/app.h"

#include <algorithm>
#include <iostream>

#include "core/state_manager.h"
#include "core/time_manager.h"
#include "core/window_manager.h"
#include "states/game_state.h"

App::App() {
  WindowManager::InitWindow();
}

App::~App() {
}

void App::Run() {
  bool running = true;

  StateManager::PushStateToStack(move(std::unique_ptr<StateInterface>(new GameState)));
  TimeManager::Restart();

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

    WindowManager::ResetViewport();
    WindowManager::Draw(shape);

    if (TimeManager::GetDelta().asMilliseconds() > 1.0/60.0) {
      StateManager::UpdateStack();
      TimeManager::Restart();
    }

    StateManager::DrawStack();
    WindowManager::Display();
  }
}

