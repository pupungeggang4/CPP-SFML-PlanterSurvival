#include "includes.hpp"

class Label;
class ButtonSimple;
class Game;

class Window {
    public:
        Window();
        virtual void ready(Game&);
        virtual void render(Game&);
        virtual void handleClick(Game&, sf::Vector2f);
        virtual void handleKey(Game&, sf::Keyboard::Scan);
};

class WindowMenu : public Window {
    public:
        int selected = 0;
        sf::RectangleShape background;
        sptr<Label> textTitle;
        sptr<ButtonSimple> buttonResume, buttonSurrender, buttonQuit;
        std::optional<sf::Sprite> arrow;

        WindowMenu();
        void ready(Game&) override;
        void render(Game&) override;
        void handleClick(Game&, sf::Vector2f) override;
        void handleKey(Game&, sf::Keyboard::Scan) override;
};
