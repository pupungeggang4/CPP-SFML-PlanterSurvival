#include "includes.hpp"

class Game;
class Scene {
    public:
        Scene();
        virtual void ready(Game& game);
        virtual void update(Game& game);
        virtual void render(Game& game);
        virtual void mouseDown(Game& game);
        virtual void mouseMove(Game& game);
        virtual void mouseUp(Game& game);
        virtual void keyDown(Game& game);
        virtual void keyUp(Game& game);
};

class SceneTitle : public Scene {
    public:
        std::optional<sf::Sprite> test;
        SceneTitle();
        void ready(Game& game) override;
        void update(Game& game) override;
        void render(Game& game) override;
};

class SceneField : public Scene {
    public:
        SceneField();
        void ready(Game& game) override;
        void update(Game& game) override;
        void render(Game& game) override;
};
