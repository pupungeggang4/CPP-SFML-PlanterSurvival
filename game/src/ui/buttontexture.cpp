#include "ui/button.hpp"

#include "game.hpp"
#include "asset.hpp"

ButtonTexture::ButtonTexture(std::vector<float>& rect, const sptr<sf::Texture>& texture, sf::String str, unsigned int size) : Button(rect) {
    this->texture = texture;
    sprite.emplace(sf::Sprite(*texture));
    sprite->setPosition({rect[0], rect[1]});
    sf::Vector2u texSize = this->texture->getSize();
    sprite->setScale({rect[2] / (float)texSize.x, rect[3] / (float)texSize.y});

    text.emplace(sf::Text(*Asset::neodgm, str, size));
    text->setFillColor(sf::Color::Black);
    text->setPosition({rect[0] + 20, rect[1] + rect[3] / 2.0f - size * 0.75f});
}

void ButtonTexture::render(Game& game) {
    game.window.draw(*sprite);
    game.window.draw(*text);
}
