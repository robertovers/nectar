#include "hive.hpp"

void Hive::draw(sf::RenderWindow& window) {
    sf::RectangleShape r;
    auto windowSize = window.getSize();
    float width = 0;
    // set square to fit smallest window dimension
    if (windowSize.x < windowSize.y) {
        width = drawWidth * windowSize.x;
    }
    else {
        width = drawWidth * windowSize.y;
    }
    r.setFillColor(sf::Color::Red);
    window.draw(r);
}