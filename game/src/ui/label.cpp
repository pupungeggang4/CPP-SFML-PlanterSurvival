#include "asset.hpp"
#include "ui/label.hpp"

#include "game.hpp"

Label::Label(std::vector<float> pos, sf::String str, unsigned int size) {
    text.emplace(sf::Text(*Asset::neodgm, str, size));
    text->setPosition({pos[0], pos[1]});
    text->setFillColor(sf::Color::Black);
}

void Label::render(Game& game) {
    game.window.draw(*text);
}
