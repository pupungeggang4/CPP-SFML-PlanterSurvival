#include "includes.hpp"

class Game {
    public:
        unsigned int width, height;
        float aspectRatio = 16.0f / 9.0f;
        sf::RenderWindow window;
        
        Game();
        void run();
        void loop();
};
