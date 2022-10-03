#include "hive.hpp"
#include "hive.hpp"

bool Hive::isPlant() {
    return false;
}

void Hive::depositNectar(float amount) {
    nectar += amount;
}

float Hive::getNectar() {
    return nectar;
}