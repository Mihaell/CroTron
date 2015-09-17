#include "core/window_manager.h"

#include <iostream>

sf::RenderWindow WindowManager::render_window_;
std::vector<sf::VideoMode> WindowManager::modes_;

void WindowManager::InitWindow() {
  GetVideoModes(modes_);

  render_window_.create(modes_[0], "CroTrone");

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
  const float WIDTH_RATIO = 16.0;
  const float HEIGHT_RATIO = 9.0;

  sf::Vector2u sz = render_window_.getSize();

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

  render_window_.setView(view);
}

void WindowManager::Clear() {
  render_window_.clear();
}

void WindowManager::DrawSFMLDrawable(const sf::Drawable& drawable) {
  render_window_.draw(drawable);
}

void WindowManager::Display() {
  render_window_.display();
}

bool WindowManager::PollEvent(sf::Event &event) {
  return render_window_.pollEvent(event);
}
