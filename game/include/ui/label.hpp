#include "includes.hpp"

class Game;
class Label {
    public:
        std::optional<sf::Text> text;
        Label(std::vector<float>, sf::String, unsigned int size = 32);
        void render(Game&);
};
