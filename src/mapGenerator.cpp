#include <algorithm>
#include <stdexcept>
#include "mapGenerator.hpp"
#include "environment.hpp"
#include "location.hpp"
#include "honeybee.hpp"
#include "soybean.hpp"

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
    Environment generatedEnvironment = Environment(envSizeX, envSizeY);
    // randomly scatter bees throughout map
    int placedBees = 0;
    while (placedBees < beeCount) {
        float trueX = rand() / (static_cast <float> (RAND_MAX / envSizeX));
        float trueY = rand() / (static_cast <float> (RAND_MAX / envSizeY));
        auto bee = shared_ptr<HoneyBee>(std::make_shared<HoneyBee>(trueX, trueY));
        agentController.addAgent(bee);
        // TODO: add to location?
        placedBees++;
    }

    // replace locations with plants
    float placeChance = cropChance / 100.0;
    for (auto& locationRow : generatedEnvironment.getLocations()) {
        for (auto& location : locationRow) {
            float rolledChance = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);  // 0.0 - 1.0
            if (placeChance >= rolledChance) {
                auto plant = shared_ptr<Soybean>(std::make_shared<Soybean>(location->getX(), location->getY()));
                generatedEnvironment.changeLocation(location->getX(), location->getY(), plant);
            }
        }
    }
    return generatedEnvironment;
}
