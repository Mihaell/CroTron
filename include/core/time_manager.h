#ifndef CROTRON_CORE_TIME_MANAGER_H_
#define CROTRON_CORE_TIME_MANAGER_H_

#include <SFML/System.hpp>

class TimeManager {
 public:
  static sf::Time GetDelta();
  static void Restart();

 private:
   static bool saved_;
   static sf::Clock clock_;
   static sf::Time current_delta_;

};

#endif  // CROTRON_CORE_TIME_MANAGER_H_

