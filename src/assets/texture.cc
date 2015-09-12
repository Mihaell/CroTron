#include "assets/texture.h"

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

std::map<std::string, sf::Texture*> Texture::textures_;

bool Texture::Load(const std::string& texture_ID, const std::string& path) {
  sf::Texture* texture = new sf::Texture();
  if (!texture->loadFromFile(path)) {
    delete texture;
    texture = nullptr;
    return false;
  }
  textures_[texture_ID] = texture;
  return true;
}

sf::Texture* Texture::Get(const std::string& texture_ID) {
  return textures_[texture_ID];
}

void Texture::Bind(const std::string& texture_ID) {
  sf::Texture::bind(textures_[texture_ID]);
}
