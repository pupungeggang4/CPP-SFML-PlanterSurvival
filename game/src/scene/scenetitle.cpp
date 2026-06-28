#include "asset.hpp"
#include "ui.hpp"

#include "ui/label.hpp"

#include "scene/scene.hpp"
#include "game.hpp"

SceneTitle::SceneTitle() {

}

void SceneTitle::ready(Game& game) {
    selected = 0;
    arrow.emplace(*Asset::texture->at("arrow"));
    textTitle = make_shared<Label>(UI::title["text_title"], "Planterguy Survival", 32);
}

void SceneTitle::update(Game& game) {

}

void SceneTitle::render(Game& game) {
    arrow->setPosition({UI::title["arrow"][0], UI::title["arrow"][1] + UI::title["arrow"][5] * selected});
    game.window.draw(*arrow);
    textTitle->render(game);
}

void SceneTitle::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        game.changeSceneTo("field");
    }
}

void SceneTitle::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;
    if (scan == Scan::Down) {
        selected = (selected + 1) % 4;
    }
    if (scan == Scan::Up) {
        selected = (selected + 3) % 4;
    }
    if (scan == Scan::Enter) {
        if (selected == 0) {
            game.changeSceneTo("field");
        } else if (selected == 3) {
            game.window.close();
        }
    }
}

void SceneTitle::keyUp(Game& game, sf::Keyboard::Scan scan) {

}
