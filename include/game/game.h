#ifndef CROTRON_GAME_GAME_H_
#define CROTRON_GAME_GAME_H_

#include <vector>

#include <SFML/Graphics.hpp>

class Game {
 public:

  static constexpr int AREA_WIDTH = 700;
  static constexpr int AREA_HEIGHT = 700;
  static constexpr int AREA_WALL_WIDTH = 10;

  Game();
  ~Game();

  void Draw();
  void Update();

 private:

  void DrawPlayAreaWalls();

  sf::Image play_area_img_;
  sf::Vector2i player_pos_;
  std::vector<sf::RectangleShape> walls_;
  sf::Texture play_area_tex_;
  int player_heading_;
  bool alive_;

};

#endif  // CROTRON_GAME_GAME_H_

