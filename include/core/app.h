#ifndef CROTRON_CORE_APP_H_
#define CROTRON_CORE_APP_H_

#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class App {
 public:


  App();
  ~App();

  void Run();

 private:

  std::vector<sf::VideoMode> modes_;

};

#endif  // CROTRON_CORE_APP_H_
