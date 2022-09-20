#include "plant.hpp"

Plant::~Plant() { }

Plant::Plant(int x, int y) : Location(x, y) {
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

bool Plant::hasLotsOfNectar() {
    return nectar > 15;
}

float Plant::harvestNectar() {
    float amount = 1;
    if (nectar >= amount) {
        nectar -= amount;
        return amount;
    } else {
        nectar = 0;
        return nectar;
    }
}
