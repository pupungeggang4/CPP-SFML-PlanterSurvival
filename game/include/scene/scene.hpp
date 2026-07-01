#include "includes.hpp"

class Game;
class Label;
class ButtonSimple;
class WindowMenu;

class Scene {
    public:
        Scene();
        virtual void ready(Game&);
        virtual void update(Game&);
        virtual void render(Game&);
        virtual void mouseDown(Game&, sf::Vector2f, sf::Mouse::Button);
        virtual void mouseMove(Game&, sf::Vector2f);
        virtual void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button);
        virtual void keyDown(Game&, sf::Keyboard::Scan);
        virtual void keyUp(Game&, sf::Keyboard::Scan);
};

class SceneTitle : public Scene {
    public:
        int selected = 0;
        std::optional<sf::Sprite> arrow;
        sptr<Label> textTitle;
        sptr<ButtonSimple> buttonStart, buttonErase, buttonCollection, buttonQuit;

        SceneTitle();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void keyUp(Game&, sf::Keyboard::Scan) override;
};

class SceneField : public Scene {
    public:
        sptr<ButtonSimple> buttonMenu;
        sptr<WindowMenu> windowMenu;
        SceneField();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void keyUp(Game&, sf::Keyboard::Scan) override;
};

class SceneCollection : public Scene {
    public:
        SceneCollection();
        void ready(Game&) override;
        void update(Game&) override;
        void render(Game&) override;
        void mouseUp(Game&, sf::Vector2f, sf::Mouse::Button) override;
        void keyDown(Game&, sf::Keyboard::Scan) override;
        void keyUp(Game&, sf::Keyboard::Scan) override;
};

