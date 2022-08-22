#include <algorithm>
#include <stdexcept>
#include "mapGenerator.hpp"
#include "environment.hpp"
#include "location.hpp"
#include "honeybee.hpp"

BasicMapGenerator::BasicMapGenerator(int envSizeX, int envSizeY, int beeCount = 0, int cropChance = 0) {
    if (envSizeX <= 0) {
        throw std::invalid_argument("X value must be positive integer");
    }
    if (envSizeY <= 0) {
        throw std::invalid_argument("Y value must be positive integer");
    }

    this->envSizeX = envSizeX;
    this->envSizeY = envSizeY;
    this->beeCount = beeCount;
    this->cropChance = cropChance;
}


Environment BasicMapGenerator::generateEnvironment(AgentController& agentController) {
    Environment generatedEnvironment = Environment();
    // randomly scatter bees throughout map
    int placedBees = 0;
    while (placedBees <= beeCount) {
        float trueX = rand() / (static_cast <float> (RAND_MAX / envSizeX));
        float trueY = rand() / (static_cast <float> (RAND_MAX / envSizeY));
        auto bee = shared_ptr<HoneyBee>(new HoneyBee(trueX, trueY));
        agentController.addAgentPtr(bee);

        placedBees++;
    }

    // place plants on locations
    float placeChance = cropChance / 100.0;
    for (int tilesLeft = generatedEnvironment.getSize(); tilesLeft > 0; tilesLeft -= 1) {
        // TODO: properly iterate through tiles in environment
        Location currentLocation = Location();

        float rolledChance = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);  // 0.0 - 1.0
        if (placeChance >= rolledChance) {
            // TODO: place crop
        }
    }
    return generatedEnvironment;
}
