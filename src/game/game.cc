#include "game/game.h"

#include <algorithm>
#include <iostream>

#include "core/camera.h"
#include "core/time_manager.h"
#include "core/window_manager.h"

Game::Game() {
  player_speed_ = 50.0;

  play_area_img_.create(AREA_WIDTH, AREA_HEIGHT, sf::Color::Black);
  player_pos_ = {500, 500};
  player_heading_ = 0;

  sf::RectangleShape wall;
  wall.setSize({AREA_WIDTH + AREA_WALL_WIDTH * 2, AREA_WALL_WIDTH});
  wall.setFillColor(sf::Color::Green);

  wall.setPosition({-AREA_WALL_WIDTH, -AREA_WALL_WIDTH});
  walls_.push_back(wall);

  wall.setPosition({-AREA_WALL_WIDTH, AREA_HEIGHT});
  walls_.push_back(wall);

  wall.setSize({AREA_WALL_WIDTH, AREA_HEIGHT + AREA_WALL_WIDTH * 2});

  wall.setPosition({-AREA_WALL_WIDTH, -AREA_WALL_WIDTH});
  walls_.push_back(wall);

  wall.setPosition({AREA_WIDTH, -AREA_WALL_WIDTH});
  walls_.push_back(wall);

  play_area_img_.setPixel(50, 50, sf::Color::Cyan);

  alive_ = true;

  // TESTIRANJE CAMERE
  camera_ = new Camera();
  sf::View view = sf::View(sf::FloatRect(-10, -10, 760, 760));
  view.setViewport(sf::FloatRect(0.33, 0.25, 0.33, 0.5));
  camera_->PushView(view);
}

Game::~Game() {

}

void Game::Draw() {
  //WindowManager::SetViewport({AREA_WIDTH / 2.0, AREA_HEIGHT / 2.0}, {16.0 * 80, 9.0 * 80});
  camera_->Apply();
  DrawPlayAreaWalls();
//  play_area_tex_.loadFromImage(play_area_img_);
//  sf::Sprite sprite;
//  sprite.setTexture(play_area_tex_);
//  sprite.setPosition(0, 0);
//  WindowManager::Draw(sprite);
}

sf::Vector2f min(sf::Vector2f v1, sf::Vector2f v2) {
  if (v1.x != v2.x)
    if (v1.x < v2.x) return v1;
    else return v2;
  if (v1.y < v2.y) return v1;
  else return v2;
}

void Game::Update() {
  float k = TimeManager::GetDelta().asSeconds();

  player_speed_ += (200.0 - player_speed_) * k * 0.5;

  if (!alive_) return;
  float vx[4] = {LINE_THICKNESS / 2.0, 0, LINE_THICKNESS / 2.0, 0}, vy[4] = {0, LINE_THICKNESS / 2.0, 0, LINE_THICKNESS / 2.0};
  vx[2] *= -1;
  vy[3] *= -1;

  int last_heading = player_heading_;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && player_heading_ != 1) player_heading_ = 3;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && player_heading_ != 0) player_heading_ = 2;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && player_heading_ != 3) player_heading_ = 1;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D) && player_heading_ != 2) player_heading_ = 0;
  if (player_heading_ != last_heading) player_speed_ *= 0.9;

  player_pos_ += sf::Vector2f(vx[player_heading_], vy[player_heading_]);
  sf::Vector2f new_player_pos = player_pos_ + sf::Vector2f(k * vx[player_heading_] * player_speed_, k * vy[player_heading_] * player_speed_);
  new_player_pos += sf::Vector2f(vx[player_heading_], vy[player_heading_]);

  sf::RectangleShape wall(sf::Vector2f(std::abs(player_pos_.x - new_player_pos.x), std::abs(player_pos_.y - new_player_pos.y)));
  wall.setPosition((sf::Vector2f)min(player_pos_, new_player_pos));
  wall.setFillColor(sf::Color::Red);

  if (wall.getSize().x == 0) {
    wall.setSize(sf::Vector2f(LINE_THICKNESS, wall.getSize().y));
    wall.move(LINE_THICKNESS * -1 / 2.0, 0.0);
  }
  if (wall.getSize().y == 0) {
    wall.setSize(sf::Vector2f(wall.getSize().x, LINE_THICKNESS));
    wall.move(0.0, LINE_THICKNESS * -1 / 2.0);
  }

  for (auto it: walls_) {
    if (wall.getGlobalBounds().intersects(it.getGlobalBounds())) {
      printf("BOOM!!!\n");
      alive_ = false;
      break;
    }
  }

//  std::cout << wall.getPosition().x << " " << wall.getPosition().y << std::endl;
//  std::cout << wall.getSize().x << " " << wall.getSize().y << std::endl;
  std::cout << player_speed_ << std::endl;
  walls_.push_back(wall);

  player_pos_ += sf::Vector2f(k * vx[player_heading_] * player_speed_, k * vy[player_heading_] * player_speed_);
}

void Game::DrawPlayAreaWalls() {
  for (auto it: walls_) {
    WindowManager::Draw(it);
  }
}
