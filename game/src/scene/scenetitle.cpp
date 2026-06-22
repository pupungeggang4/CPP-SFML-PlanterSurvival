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
