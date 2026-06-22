#include "game.hpp"

Game::Game() {
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    if (desktop.size.x / aspectRatio > desktop.size.y ) {
        height = (unsigned int)(desktop.size.y * 0.8f);
        width = (unsigned int)(height * aspectRatio);
    } else {
        width = (unsigned int)(desktop.size.x * 0.8f);
        height = (unsigned int)(width / aspectRatio);
    }
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Planter Survival");
}

void Game::run() {
    loop();
}

void Game::loop() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        window.clear();
        window.display();
    }
}
