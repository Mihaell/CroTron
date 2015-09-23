#ifndef CROTRON_GAME_GAME_H_
#define CROTRON_GAME_GAME_H_

#include <SFML/Graphics.hpp>

class Game {
 public:

  static constexpr int AREA_WIDTH = 1000;
  static constexpr int AREA_HEIGHT = 1000;

  Game();
  ~Game();

  void Draw();
  void Update();

 private:

  sf::Image play_area_img_;
  sf::Vector2i player_pos_;
  sf::Texture play_area_tex_;
  int player_heading_;

};

#endif  // CROTRON_GAME_GAME_H_

