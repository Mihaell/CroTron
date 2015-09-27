#ifndef CROTRON_GAME_GAME_H_
#define CROTRON_GAME_GAME_H_

#include <vector>

#include <SFML/Graphics.hpp>

#include "core/camera.h"

class Game {
 public:

  static constexpr int AREA_WIDTH = 700;
  static constexpr int AREA_HEIGHT = 700;
  static constexpr int AREA_WALL_WIDTH = 10;
  static constexpr float LINE_THICKNESS = 3.0;

  Game();
  ~Game();

  void Draw();
  void Update();

 private:

  void DrawPlayAreaWalls();

  sf::Image play_area_img_;
  sf::Vector2f player_pos_;
  std::vector<sf::RectangleShape> walls_;
  sf::Texture play_area_tex_;
  int player_heading_;
  bool alive_;
  float player_speed_;

  Camera* camera_;
};

#endif  // CROTRON_GAME_GAME_H_

