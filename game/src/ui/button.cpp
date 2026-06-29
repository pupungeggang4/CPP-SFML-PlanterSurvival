#include "ui/button.hpp"

Button::Button(std::vector<float>& rect) {
    area = {{rect[0], rect[1]}, {rect[2], rect[3]}};
}

bool Button::contains(sf::Vector2<float>& pos) {
    return area.contains(pos);
}
