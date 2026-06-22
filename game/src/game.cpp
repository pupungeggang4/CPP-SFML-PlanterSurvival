#include "asset.hpp"
#include "game.hpp"
#include "scene/scene.hpp"

Game::Game() {
    Asset::loadAsset();
    sf::VideoMode desktop = sf::VideoMode::getDesktopMode();
    if (desktop.size.x / aspectRatio > desktop.size.y) {
        height = (unsigned int)(desktop.size.y * 0.8f);
        width = (unsigned int)(height * aspectRatio);
    } else {
        width = (unsigned int)(desktop.size.x * 0.8f);
        height = (unsigned int)(width / aspectRatio);
    }
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Planter Survival");
    viewUI = sf::View({640, 360}, {1280, 720});
    viewCamera = sf::View({0, 0}, {1280, 720});
    window.setView(viewUI);
}

void Game::run() {
    scenes["title"] = make_shared<SceneTitle>();
    scenes["field"] = make_shared<SceneField>();
    scene = scenes["title"];
    scene->ready(*this);
    loop();
}

void Game::loop() {
    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
        }
        scene->update(*this);
        window.clear(sf::Color::White);
        scene->render(*this);
        window.display();
    }
}

Game::~Game() {
    Asset::dispose();
}
