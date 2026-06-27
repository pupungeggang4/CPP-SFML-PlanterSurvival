#include "includes.hpp"

class Asset {
    public:
        static sptr<sf::Font> neodgm;
        static sptr<std::unordered_map<std::string, sptr<sf::Texture>>> texture;
        static void loadAsset();
        static void dispose();
};
