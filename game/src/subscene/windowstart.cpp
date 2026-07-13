#include "subscene/window.hpp"
#include "asset.hpp"
#include "ui.hpp"
#include "ui/label.hpp"
#include "ui/button.hpp"
#include "game.hpp"

WindowStart::WindowStart() {
    background = sf::RectangleShape({UI::start["rect"][2], UI::start["rect"][3]});
    background.setPosition({UI::start["rect"][0], UI::start["rect"][1]});
    background.setFillColor(sf::Color::Yellow);
}

void WindowStart::ready(Game& game) {

}

void WindowStart::render(Game& game) {
    game.window.draw(background);
}

void WindowStart::handleClick(Game& game, sf::Vector2f pos) {

}

void WindowStart::handleKey(Game& game, sf::Keyboard::Scan scan) {

}
