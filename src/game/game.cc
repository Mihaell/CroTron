#include "game/game.h"

#include <iostream>

#include "core/window_manager.h"

Game::Game() {
  play_area_img_.create(AREA_WIDTH, AREA_HEIGHT, sf::Color::Black);
  player_pos_ = {500, 500};
  player_heading_ = 0;
}

Game::~Game() {

}

void Game::Draw() {
  play_area_tex_.loadFromImage(play_area_img_);
  sf::Sprite sprite;
  sprite.setTexture(play_area_tex_);
  sprite.setPosition(0, 0);
  WindowManager::Draw(sprite);
}

void Game::Update() {
  if (player_heading_ == 0) {
    for (int i = 0; i < 5; i++) {
      play_area_img_.setPixel(player_pos_.x + i, player_pos_.y, sf::Color::Red);
    }
    player_pos_ += {5, 0};
  }
}
