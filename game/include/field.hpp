#include "includes.hpp"

class Player;
class Unit;

class Field {
    public:
        sptr<Player> player;
        std::vector<sptr<Unit>> units;
        Field();
};
