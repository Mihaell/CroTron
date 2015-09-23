#include "game/game.h"

#include <iostream>

#include "core/window_manager.h"

Game::Game() {
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
}

Game::~Game() {

}

void Game::Draw() {
  WindowManager::SetViewport({AREA_WIDTH / 2.0, AREA_HEIGHT / 2.0}, {16.0 * 80, 9.0 * 80});
  DrawPlayAreaWalls();
  play_area_tex_.loadFromImage(play_area_img_);
  sf::Sprite sprite;
  sprite.setTexture(play_area_tex_);
  sprite.setPosition(0, 0);
  WindowManager::Draw(sprite);
}

void Game::Update() {
  if (!alive_) return;
  float vx[4] = {1, 0, -1, 0}, vy[4] = {0, 1, 0, -1};

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) player_heading_ = 3;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) player_heading_ = 2;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) player_heading_ = 1;
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) player_heading_ = 0;

  sf::Vector2i new_player_pos = player_pos_ + sf::Vector2i(5 * vx[player_heading_], 5 * vy[player_heading_]);
  if (new_player_pos.x <= 0 || new_player_pos.y <= 0 || new_player_pos.x >= AREA_WIDTH || new_player_pos.y >= AREA_HEIGHT) {
    printf("BOOM!!!\n");
    alive_ = false;
    return;
  }

  for (int i = 0; i < 5; i++) {
    play_area_img_.setPixel(player_pos_.x + i * vx[player_heading_] + 0, player_pos_.y + i * vy[player_heading_] + 0, sf::Color::Red);
    play_area_img_.setPixel(player_pos_.x + i * vx[player_heading_] + 1, player_pos_.y + i * vy[player_heading_] + 0, sf::Color::Red);
    play_area_img_.setPixel(player_pos_.x + i * vx[player_heading_] - 1, player_pos_.y + i * vy[player_heading_] + 0, sf::Color::Red);
    play_area_img_.setPixel(player_pos_.x + i * vx[player_heading_] + 0, player_pos_.y + i * vy[player_heading_] + 1, sf::Color::Red);
    play_area_img_.setPixel(player_pos_.x + i * vx[player_heading_] + 0, player_pos_.y + i * vy[player_heading_] - 1, sf::Color::Red);
  }

  player_pos_ += {5 * vx[player_heading_], 5 * vy[player_heading_]};
  if (player_pos_.x <= 0 || player_pos_.y <= 0 || player_pos_.x >= AREA_WIDTH || player_pos_.y >= AREA_HEIGHT) {
    printf("BOOM!!!\n");
    alive_ = false;
  }


  std::cout << player_pos_.x << " " << player_pos_.y << std::endl;
}

void Game::DrawPlayAreaWalls() {
  for (auto it: walls_) {
    WindowManager::Draw(it);
  }
}
