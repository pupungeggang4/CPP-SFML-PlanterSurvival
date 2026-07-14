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
    textTitle = make_shared<Label>(UI::start["text_title"], "Select start");
    for (int i = 0; i < 3; i++) {
        std::vector<float> rect = {
            UI::start["buttons"][0] + UI::start["buttons"][4] * i, UI::start["buttons"][1],
            UI::start["buttons"][2], UI::start["buttons"][3],
        };
        buttons[i] = make_shared<ButtonSimple>(rect, sf::Color::Cyan, "");
    }
    selectFrame.emplace(sf::Sprite(*Asset::texture->at("select_frame")));
    selectFrame->setScale({2.0f, 2.0f});
    buttonStart = make_shared<ButtonSimple>(UI::start["button_ok"], sf::Color::Cyan, "Start");
}

void WindowStart::ready(Game& game) {
    selected = -1;
}

void WindowStart::render(Game& game) {
    game.window.draw(background);
    textTitle->render(game);
    for (int i = 0; i < 3; i++) {
        buttons[i]->render(game);
    }
    if (selected != -1) {
        selectFrame->setPosition({UI::start["buttons"][0] + UI::start["buttons"][4] * selected, UI::start["buttons"][1]});
        game.window.draw(*selectFrame);
    }
    buttonStart->render(game);
}

void WindowStart::handleClick(Game& game, sf::Vector2f pos) {
    for (int i = 0; i < 3; i++) {
        if (buttons[i]->contains(pos)) {
            selected = i;
        }
    }

    if (buttonStart->contains(pos)) {
        if (selected != -1) {
            game.state = "";
        }
    }
}

void WindowStart::handleKey(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;
    if (scan == Scan::Left || scan == Scan::Up) {
        selected = (selected + 2) % 3;
    } else if (scan == Scan::Right || scan == Scan::Down) {
        selected = (selected + 1) % 3;
    } else if (scan == Scan::Enter) {
        if (selected != -1) {
            game.state = "";
        }
    }
}
