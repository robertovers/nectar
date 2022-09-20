#include "hive.hpp"
#include "hive.hpp"

Hive::Hive(int x, int y) : Location(x, y)
{
    sprite->setFillColor(sf::Color::Red);
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