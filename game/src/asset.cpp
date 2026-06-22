#include "asset.hpp"

sptr<std::unordered_map<std::string, sptr<sf::Texture>>> Asset::texture = make_shared<std::unordered_map<std::string, sptr<sf::Texture>>>();

void Asset::loadAsset() {
    texture->emplace("arrow", make_shared<sf::Texture>("asset/image/arrow.png"));
}

void Asset::dispose() {
    texture.reset();
}

