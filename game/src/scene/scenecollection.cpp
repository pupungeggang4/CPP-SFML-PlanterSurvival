#include "asset.hpp"
#include "ui.hpp"

#include "ui/label.hpp"
#include "ui/button.hpp"

#include "scene/scene.hpp"
#include "game.hpp"

SceneCollection::SceneCollection() {
    textTitle = make_shared<Label>(UI::collection["text_title"], "Collection");
    buttonBack = make_shared<ButtonSimple>(UI::collection["button_back"], sf::Color::Cyan, "");
}

void SceneCollection::ready(Game& game) {
}

void SceneCollection::update(Game& game) {
}

void SceneCollection::render(Game& game) {
    textTitle->render(game);
    buttonBack->render(game);
}

void SceneCollection::mouseUp(Game& game, sf::Vector2f pos, sf::Mouse::Button button) {
    if (button == sf::Mouse::Button::Left) {
        if (buttonBack->contains(pos)) {
            game.changeSceneTo("title");
        }
    }
}

void SceneCollection::keyDown(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;
    if (scan == Scan::Escape) {
        game.changeSceneTo("title");
    }
}

void SceneCollection::keyUp(Game& game, sf::Keyboard::Scan scan) {

}
