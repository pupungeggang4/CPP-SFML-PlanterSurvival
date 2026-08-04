#include "entity/player.hpp"
#include "asset.hpp"
#include "game.hpp"

Player::Player() {
    sprite.emplace(*Asset::texture->at("player"));
}

void Player::update(Game& game) {
    if (game.keyPressed["left"]) {
        rect.position.x -= speed * game.dt;
    }
    if (game.keyPressed["right"]) {
        rect.position.x += speed * game.dt;
    }
    if (game.keyPressed["up"]) {
        rect.position.y -= speed * game.dt;
    }
    if (game.keyPressed["down"]) {
        rect.position.y += speed * game.dt;
    }
}

void Player::render(Game& game) {
    sprite->setPosition(rect.position - rect.size / 2.0f);
    game.window.draw(*sprite);
}
