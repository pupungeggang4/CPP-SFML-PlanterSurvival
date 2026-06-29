#include "scene/scene.hpp"
#include "subscene/window.hpp"
#include "game.hpp"

SceneField::SceneField() {
    windowMenu = make_shared<WindowMenu>();
}

void SceneField::ready(Game& game) {

}

void SceneField::update(Game& game) {

}

void SceneField::render(Game& game) {
    if (game.menu == true) {
        windowMenu->render(game);
    }
}

void SceneField::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {

}

void SceneField::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;

    if (game.menu == false) {
        if (scan == Scan::Escape) {
            game.menu = true;
        }
    } else {
        windowMenu->handleKey(game, scan);
    }
}

void SceneField::keyUp(Game& game, sf::Keyboard::Scan scan) {
}
