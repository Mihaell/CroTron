#include "core/window_manager.h"

#include <iostream>

sf::RenderWindow WindowManager::render_window_;
std::vector<sf::VideoMode> WindowManager::modes_;

void WindowManager::InitWindow() {
  GetVideoModes(modes_);

  // TODO: vratiti natrag na modes_, ovo je PRIVREMENO!!!
  render_window_.create(sf::VideoMode(1024, 720), "CroTron");
  render_window_.setVerticalSyncEnabled(true);

  ResetViewport();
}

void WindowManager::CloseWindow() {
  render_window_.close();
}

void WindowManager::GetVideoModes(std::vector<sf::VideoMode> &modes) {
  int best_BPP = 0;

  modes = sf::VideoMode::getFullscreenModes();

  for (auto it: modes) {
    if (it.bitsPerPixel > best_BPP) best_BPP = it.bitsPerPixel;
  }

  modes.erase(
      std::remove_if(
          modes.begin(),
          modes.end(),
          [best_BPP](sf::VideoMode mode) { return mode.bitsPerPixel != best_BPP; }),
      modes.end());

  std::cout << "Available resolutions:" << std::endl;
  for (auto it: modes) {
    std::cout << it.width << " " << it.height << std::endl;
  }

  return;
}

void WindowManager::ResetViewport() {
  sf::Vector2u sz = render_window_.getSize();

  const float win_ratio = sz.x / static_cast<float>(sz.y);
  const float view_ratio = VIEW_WIDTH / VIEW_HEIGHT;

  sf::View view(sf::FloatRect(0, 0, VIEW_WIDTH, VIEW_HEIGHT));

  if (win_ratio < view_ratio) {
    const float h = win_ratio / view_ratio;
    view.setViewport(sf::FloatRect(0, 0.5 - h/2, 1, h));
  } else {
    const float w = view_ratio / win_ratio;
    view.setViewport(sf::FloatRect(0.5 - w/2, 0, w, 1));
  }

  render_window_.setView(view);
}

void WindowManager::Clear(const sf::Color& color) {
  render_window_.clear(color);
}

void WindowManager::Draw(const sf::Drawable &drawable,
                         const sf::RenderStates &states,
                         sf::Shader* shader) {
  render_window_.draw(drawable);
}

void WindowManager::Display() {
  render_window_.display();
}

bool WindowManager::PollEvent(sf::Event &event) {
  return render_window_.pollEvent(event);
}
