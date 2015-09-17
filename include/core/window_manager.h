#ifndef CROTRON_CORE_WINDOW_MANAGER_HPP
#define CROTRON_CORE_WINDOW_MANAGER_HPP

#include <vector>

#include <SFML/Graphics.hpp>

class WindowManager {
 public:
  static void InitWindow();
  static void CloseWindow();
  static void GetVideoModes(std::vector<sf::VideoMode> &modes);
  static void ResetViewport();
  static bool PollEvent(sf::Event &event);

  static void Clear();

  /// Draws SFML drawable
  static void Draw(const sf::Drawable &drawable,
                   const sf::RenderStates& states = sf::BlendAlpha,
                   sf::Shader* shader = nullptr);

  static void Display();

 private:
  static sf::RenderWindow render_window_;
  static std::vector<sf::VideoMode> modes_;
};

#endif  // CROTRON_CORE_WINDOW_MANAGER_HPP
