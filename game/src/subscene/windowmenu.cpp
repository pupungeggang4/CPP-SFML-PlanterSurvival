#include "subscene/window.hpp"
#include "asset.hpp"
#include "ui.hpp"
#include "ui/label.hpp"
#include "ui/button.hpp"

#include "game.hpp"

WindowMenu::WindowMenu() {
    background = sf::RectangleShape({UI::menu["rect"][2], UI::menu["rect"][3]});
    background.setPosition({UI::menu["rect"][0], UI::menu["rect"][1]});
    background.setFillColor(sf::Color::Cyan);
    textTitle = make_shared<Label>(UI::menu["text_title"], "Paused");
    buttonResume = make_shared<ButtonSimple>(UI::menu["button_resume"], sf::Color::Yellow, "Resume");
    buttonSurrender = make_shared<ButtonSimple>(UI::menu["button_surrender"], sf::Color::Cyan, "Surrender");
    buttonQuit = make_shared<ButtonSimple>(UI::menu["button_quit"], sf::Color::Yellow, "Quit Game");
    arrow.emplace(*Asset::texture->at("arrow"));
}

void WindowMenu::ready(Game& game) {
    selected = 0;
}

void WindowMenu::render(Game& game) {
    game.window.draw(background);
    textTitle->render(game);
    buttonResume->render(game);
    buttonSurrender->render(game);
    buttonQuit->render(game);

    arrow->setPosition({UI::menu["arrow"][0], UI::menu["arrow"][1] + UI::menu["arrow"][5] * selected});
    game.window.draw(*arrow);
}

void WindowMenu::handleClick(Game& game, sf::Vector2f pos) {
    if (buttonResume->contains(pos)) {
        game.menu = false;
    } else if (buttonQuit->contains(pos)) {
        game.window.close();
    }
}

void WindowMenu::handleKey(Game& game, sf::Keyboard::Scan scan) {
    using Scan = sf::Keyboard::Scan;

    if (scan == Scan::Up || scan == Scan::W) {
        selected = (selected + 2) % 3;
    }
    if (scan == Scan::Down || scan == Scan::S) {
        selected = (selected + 1) % 3;
    }
    if (scan == Scan::Enter) {
        if (selected == 0) {
            game.menu = false;
        } else if (selected == 3) {
            game.window.close();
        }
    }

}
