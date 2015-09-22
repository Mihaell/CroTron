#include "states/game_state.h"

#include "assets/texture.h"
#include "core/window_manager.h"

GameState::GameState() {
  Texture::Load("CROTRON_LOGO", "data/textures/crotron.png");

  sprite.setTexture(*Texture::Get("CROTRON_LOGO"));
  sprite.setPosition(100, 100);
  widget = new Widget(sf::Vector2f(50, 50), sf::Vector2f(200, 200));

  state_name_ = "GameState";
}

GameState::~GameState() {

}

void GameState::Draw() {
  WindowManager::Draw(sprite);
  widget->Draw();
}

void GameState::Update() {

}
