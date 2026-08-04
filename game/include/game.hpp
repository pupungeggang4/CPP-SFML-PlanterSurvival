#include "includes.hpp"

class Scene;
class Player;

class Game {
    public:
        unsigned int width, height;
        float aspectRatio = 16.0f / 9.0f;
        sf::RenderWindow window;
        sf::View viewUI, viewCamera;
        sf::Clock clock; sf::Time delta; float dt;

        std::unordered_map<std::string, sptr<Scene>> scenes = {};
        sptr<Scene> scene;
        std::string state = "";
        bool menu = false;
        std::unordered_map<std::string, bool> keyPressed = {
            {"left", false}, {"right", false}, {"up", false}, {"down", false}
        };

        sptr<Player> player;

        Game();
        ~Game();
        void run();
        void loop();
        void changeSceneTo(std::string);
};
