#include "scene/scene.hpp"
#include "asset.hpp"
#include "ui.hpp"
#include "ui/button.hpp"

#include "subscene/window.hpp"
#include "game.hpp"

SceneField::SceneField() {
    buttonMenu = make_shared<ButtonTexture>(UI::field["button_menu"], Asset::texture->at("menu"), "");
    windowMenu = make_shared<WindowMenu>();
    windowStart = make_shared<WindowStart>();
    windowReward = make_shared<WindowReward>();
}

void SceneField::ready(Game& game) {
    windowStart->ready(game);
}

void SceneField::update(Game& game) {

}

void SceneField::render(Game& game) {
    buttonMenu->render(game);

    if (game.state == "start") {
        windowStart->render(game);
    }

    if (game.menu == true) {
        windowMenu->render(game);
    }
}

void SceneField::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        if (game.menu == false) {
            if (buttonMenu->contains(pos)) {
                game.menu = true;
            }
            if (game.state == "start") {
                windowStart->handleClick(game, pos);
            }
        } else {
            if (buttonMenu->contains(pos)) {
                game.menu = false;
            }
            windowMenu->handleClick(game, pos);
        }
    }
}

void SceneField::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;

    if (game.menu == false) {
        if (scan == Scan::Escape) {
            game.menu = true;
        }
        if (game.state == "start") {
            windowStart->handleKey(game, scan);
        }
    } else {
        windowMenu->handleKey(game, scan);
    }
}

void SceneField::keyUp(Game& game, sf::Keyboard::Scan scan) {
}
