#include "plant.hpp"

Plant::~Plant() { }

Plant::Plant(int x, int y) : Location(x, y) {
}

bool Plant::isPlant() {
    return true;
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
