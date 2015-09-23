#ifndef CROTRON_CORE_WINDOW_MANAGER_HPP
#define CROTRON_CORE_WINDOW_MANAGER_HPP

#include <vector>

#include <SFML/Graphics.hpp>

class WindowManager {
 public:
  static constexpr float VIEW_WIDTH  = 1280;
  static constexpr float VIEW_HEIGHT = 720;

  static void InitWindow();
  static void CloseWindow();
  static void GetVideoModes(std::vector<sf::VideoMode> &modes);
  static void ResetViewport();
  static void SetViewport(sf::Vector2f center, sf::Vector2f sz);
  static bool PollEvent(sf::Event &event);

  static void Clear(const sf::Color& color = sf::Color::Black);

  /// Draws SFML drawable
  static void Draw(const sf::Drawable &drawable,
                   const sf::RenderStates &states = sf::BlendAlpha,
                   sf::Shader* shader = nullptr);

  static void Display();

 private:

  static sf::View GetView(const float view_width, const float view_height);

  static sf::RenderWindow render_window_;
  static std::vector<sf::VideoMode> modes_;
};

#endif  // CROTRON_CORE_WINDOW_MANAGER_HPP
