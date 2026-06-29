#include "includes.hpp"

class Scene;

class Game {
    public:
        unsigned int width, height;
        float aspectRatio = 16.0f / 9.0f;
        sf::RenderWindow window;
        sf::View viewUI, viewCamera;
        std::unordered_map<std::string, sptr<Scene>> scenes = {};
        sptr<Scene> scene;
        std::string state;
        bool menu = false;

        Game();
        ~Game();
        void run();
        void loop();
        void changeSceneTo(std::string);
};
