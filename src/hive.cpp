/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file hive.cpp
 * @brief A class to represent the Honeybees' hive.
 * @date 2022-09-19
 */

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