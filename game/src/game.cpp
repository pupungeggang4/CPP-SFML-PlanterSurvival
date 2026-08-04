#include "asset.hpp"
#include "game.hpp"
#include "entity/player.hpp"
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
    window = sf::RenderWindow(sf::VideoMode({width, height}), "Planterguy Survival");
    window.setVerticalSyncEnabled(true);
    viewUI = sf::View({640, 360}, {1280, 720});
    viewCamera = sf::View({0, 0}, {1280, 720});
    window.setView(viewUI);
    clock = sf::Clock();
}

void Game::run() {
    player = make_shared<Player>();
    scenes["title"] = make_shared<SceneTitle>();
    scenes["field"] = make_shared<SceneField>();
    scenes["collection"] = make_shared<SceneCollection>();
    scene = scenes["title"];
    scene->ready(*this);
    loop();
}

void Game::loop() {
    using Scan = sf::Keyboard::Scan;
    while (window.isOpen()) {
        delta = clock.restart();
        dt = delta.asSeconds();
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            if (const auto* e = event->getIf<sf::Event::MouseButtonReleased>()) {
                sf::Vector2f pos = {e->position.x * 1280 / (float)width, e->position.y * 720 / (float)height};
                scene->mouseUp(*this, pos, e->button);
            }
            if (const auto* e = event->getIf<sf::Event::KeyPressed>()) {
                if (e->scancode == Scan::Left) {
                    keyPressed["left"] = true;
                }
                if (e->scancode == Scan::Right) {
                    keyPressed["right"] = true;
                }
                if (e->scancode == Scan::Up) {
                    keyPressed["up"] = true;
                }
                if (e->scancode == Scan::Down) {
                    keyPressed["down"] = true;
                }

                scene->keyDown(*this, e->scancode);
            }
            if (const auto* e = event->getIf<sf::Event::KeyReleased>()) {
                if (e->scancode == Scan::Left) {
                    keyPressed["left"] = false;
                }
                if (e->scancode == Scan::Right) {
                    keyPressed["right"] = false;
                }
                if (e->scancode == Scan::Up) {
                    keyPressed["up"] = false;
                }
                if (e->scancode == Scan::Down) {
                    keyPressed["down"] = false;
                }

                scene->keyUp(*this, e->scancode);
            }
        }

        scene->update(*this);
        window.clear(sf::Color::White);
        scene->render(*this);
        window.display();
    }
}

void Game::changeSceneTo(std::string str) {
    try {
        scene = scenes[str];
        scene->ready(*this);
    } catch (int e) {
        window.close();
    }
}

Game::~Game() {
    Asset::dispose();
}
