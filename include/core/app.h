#ifndef CROTRON_CORE_APP_H_
#define CROTRON_CORE_APP_H_

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class App {
 public:

  static sf::RenderWindow window_;

  App();
  ~App();

  void Run();
  void ResetViewport();

 private:

  std::vector<sf::VideoMode> modes_;

};

#endif  // CROTRON_CORE_APP_H_
