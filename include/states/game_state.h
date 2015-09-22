#ifndef CROTRON_STATES_GAME_STATE_H_
#define CROTRON_STATES_GAME_STATE_H_

#include <SFML/Graphics.hpp>

#include "interface/widget.h"
#include "states/state_interface.h"

class GameState : public StateInterface {
 public:
  GameState();
  ~GameState();

  void Draw();
  void Update();

 private:

  sf::Sprite sprite;
  Widget* widget;

};

#endif  // CROTRON_STATES_GAME_STATE_H_

