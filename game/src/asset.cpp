#include "asset.hpp"

sptr<sf::Font> Asset::neodgm;
sptr<std::unordered_map<std::string, sptr<sf::Texture>>> Asset::texture = make_shared<std::unordered_map<std::string, sptr<sf::Texture>>>();

void Asset::loadAsset() {
    neodgm = make_shared<sf::Font>("asset/font/neodgm.ttf");
    texture->emplace("arrow", make_shared<sf::Texture>("asset/image/arrow.png"));
    texture->emplace("menu", make_shared<sf::Texture>("asset/image/menu.png"));
}

void Asset::dispose() {
    neodgm.reset();
    texture.reset();
}

