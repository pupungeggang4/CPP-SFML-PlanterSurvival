#include "ui/button.hpp"

#include "game.hpp"
#include "asset.hpp"

ButtonSimple::ButtonSimple(std::vector<float>& rect, sf::Color color, sf::String str, unsigned int size) : Button(rect) {
    background = sf::RectangleShape({rect[2], rect[3]});
    background.setPosition({rect[0], rect[1]});
    background.setFillColor(color);

    text.emplace(sf::Text(*Asset::neodgm, str, size));
    text->setFillColor(sf::Color::Black);
    text->setPosition({rect[0] + 20, rect[1] + rect[3] / 2.0f - size * 0.75f});
}

void ButtonSimple::render(Game& game) {
    game.window.draw(background);
    game.window.draw(*text);
}
