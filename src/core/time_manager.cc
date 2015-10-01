#include "core/time_manager.h"

sf::Clock TimeManager::clock_;
sf::Time TimeManager::current_delta_;

sf::Time TimeManager::GetDelta() {
  current_delta_ = clock_.getElapsedTime();
  return current_delta_;
}

void TimeManager::Restart() {
  clock_.restart();
}
