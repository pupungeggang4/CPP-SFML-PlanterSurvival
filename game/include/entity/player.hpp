#include "includes.hpp"

class Game;
class Flower;
class Item;
class Equipment;
class Card;

class Player {
    public:
        std::optional<sf::Sprite> sprite;
        float speed = 320.0f;
        sf::FloatRect rect = {{0, 0}, {80, 80}};

        std::vector<sptr<Flower>> flowers;
        std::vector<sptr<Item>> items;
        std::vector<sptr<Equipment>> equipments;

        std::vector<sptr<Card>> hand, deck;

        Player();
        void createPlayer(int);

        void update(Game&);
        void render(Game&);
};
