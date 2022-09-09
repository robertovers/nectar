#include "hive.hpp"
#include <iostream>

void Hive::draw(sf::RenderWindow& window) {
    sf::RectangleShape r;
    r.setSize(sf::Vector2f(20, 20));
    r.setPosition(x * 20, y * 20);
    r.setFillColor(sf::Color::Red);
    window.draw(r);
}

bool Hive::isPlant() {
    return false;
}