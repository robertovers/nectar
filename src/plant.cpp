#include "plant.hpp"

Plant::~Plant() { }

Plant::Plant(int x, int y) : Location(x, y) {
}

void Plant::draw(sf::RenderWindow& window) {
    sf::RectangleShape r;
    r.setSize(sf::Vector2f(20, 20));
    r.setPosition(x * 20, y * 20);
    r.setFillColor(sf::Color(0, 50, 0));
    window.draw(r);
}

bool Plant::isPlant() {
    return true;
}

bool Plant::isPollinated() {
    return pollinated;
}

void Plant::pollinate() {
    pollinated = true;
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
