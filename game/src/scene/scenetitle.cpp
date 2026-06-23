#include "asset.hpp"
#include "scene/scene.hpp"
#include "game.hpp"

SceneTitle::SceneTitle() {

}

void SceneTitle::ready(Game& game) {
    test.emplace(*Asset::texture->at("arrow"));
}

void SceneTitle::update(Game& game) {

}

void SceneTitle::render(Game& game) {
    game.window.draw(*test);
}

void SceneTitle::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        game.changeSceneTo("field");
    }
}

void SceneTitle::keyDown(Game& game, sf::Keyboard::Scan scan) {

}

void SceneTitle::keyUp(Game& game, sf::Keyboard::Scan scan) {

}
