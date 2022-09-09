#include "plant.hpp"

Plant::~Plant() { }

Plant::Plant(int x, int y) : Location(x, y) {
}

void Plant::draw(sf::RenderWindow& window) {
    /*float d = 35;
     sf::ConvexShape c;
     c.setPointCount(12);
     c.setPoint(0, sf::Vector2f(x - d/6, y - d/2));
     c.setPoint(1, sf::Vector2f(x + d/6, y - d/2));
     c.setPoint(2, sf::Vector2f(x + d/6, y - d/6));
     c.setPoint(3, sf::Vector2f(x + d/2, y - d/6));
     c.setPoint(4, sf::Vector2f(x + d/2, y + d/6));
     c.setPoint(5, sf::Vector2f(x + d/6, y + d/6));
     c.setPoint(6, sf::Vector2f(x + d/6, y + d/2));
     c.setPoint(7, sf::Vector2f(x - d/6, y + d/2));
     c.setPoint(8, sf::Vector2f(x - d/6, y + d/6));
     c.setPoint(9, sf::Vector2f(x - d/2, y + d/6));
     c.setPoint(10, sf::Vector2f(x - d/2, y - d/6));
     c.setPoint(11, sf::Vector2f(x - d/6, y - d/6));
     c.setFillColor(sf::Color(100, 250, 50));
     window.draw(c);*/
    sf::RectangleShape r;
    r.setSize(sf::Vector2f(20, 20));
    r.setPosition(x * 20, y * 20);
    r.setFillColor(sf::Color(0, 50, 0));
    window.draw(r);
}

bool Plant::isPlant() {
    return true;
}

void Plant::pollinate(float amount) {
    pollen += amount;
}

bool Plant::hasNectar() {
    return nectar > 0;
}

float Plant::harvestNectar() {
    float amount = 0.1;
    if (nectar >= amount) {
        nectar -= amount;
        return amount;
    } else {
        return 0;
    }
}
