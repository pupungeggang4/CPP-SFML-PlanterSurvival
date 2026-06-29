#include "includes.hpp"

class Game;
class Button {
    public:
        sf::Rect<float> area;

        Button(std::vector<float>&);
        virtual bool contains(sf::Vector2<float>&);
};

class ButtonSimple : public Button {
    public:
        sf::RectangleShape background;
        std::optional<sf::Text> text;

        ButtonSimple(std::vector<float>&, sf::Color, sf::String, unsigned int size = 32);
        void render(Game&);
};
