#include "hive.hpp"
#include "hive.hpp"

Hive::Hive(int x, int y) : Location(x, y)
{
    sprite->setFillColor(sf::Color::Red);
}

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

void Hive::depositNectar(float amount) {
    nectar += amount;
}

float Hive::getNectar() {
    return nectar;
}