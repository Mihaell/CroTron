#ifndef CROTRON_ASSETS_TEXTURE_H_
#define CROTRON_ASSETS_TEXTURE_H_

#include <map>
#include <string>

#include <SFML/Graphics.hpp>

class Texture {
 public:
  static bool Load(const std::string& texture_ID, const std::string& path);

  static sf::Texture* Get(const std::string& texture_ID);

  static void Bind(const std::string& texture_ID);

 private:
  static std::map<std::string, sf::Texture*> textures_;
};

#endif  // CROTRON_ASSETS_TEXTURE_H_
