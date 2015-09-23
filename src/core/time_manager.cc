#include "core/time_manager.h"

sf::Clock TimeManager::clock_;
sf::Time TimeManager::current_delta_;
bool TimeManager::saved_ = false;

sf::Time TimeManager::GetDelta() {
  if (!saved_) {
    current_delta_ = clock_.getElapsedTime();
    saved_ = true;
  }
  return current_delta_;
}

void TimeManager::Restart() {
  clock_.restart();
  saved_ = false;
}
