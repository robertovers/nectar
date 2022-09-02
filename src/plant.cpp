#ifndef PLANT_CPP
#define PLANT_CPP

#include "plant.hpp"

Plant::~Plant() { }

Plant::Plant(int x, int y) : Location(x, y) {
}

bool Plant::isPlant() {
    return false;
}

void Plant::pollinate(float amount) {
    pollen += amount;
}

bool Plant::hasNectar() {
    return nectar > 0;
}

float Plant::harvestNectar() {
    if (hasNectar()) {
        float amount = 0.1;
        nectar -= amount;
        return amount;
    } else {
        return 0;
    }
}

#endif