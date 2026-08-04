#include "includes.hpp"

class Game;
class Player {
    public:
        std::optional<sf::Sprite> sprite;
        float speed = 320.0f;
        sf::FloatRect rect = {{640, 360}, {80, 80}};
        Player();
        void update(Game&);
        void render(Game&);
};
