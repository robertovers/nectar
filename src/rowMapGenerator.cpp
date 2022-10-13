/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 *
 * @file rowMapGenerator.cpp
 * @brief MapGenerator for generating an Environment with Soybeans and empty Locations in alternating, horizontal, 1-block wide rows. Honeybees are randomly scattered around.
 * @date 2022-09-28
 */

#include "rowMapGenerator.hpp"

RowMapGenerator::RowMapGenerator(EnvColours envColours, SoybeanOverlays soybeanOverlays, int envSizeX, int envSizeY, int beeCount)
{
    if (envSizeX <= 0) {
        throw std::invalid_argument("X value must be positive integer");
    }
    if (envSizeY <= 0) {
        throw std::invalid_argument("Y value must be positive integer");
    }

    this->envSizeX = envSizeX;
    this->envSizeY = envSizeY;
    this->beeCount = beeCount;
    this->envColours = envColours;
    this->soybeanOverlays = soybeanOverlays;
}

Environment RowMapGenerator::generateEnvironment(AgentController& agentController)
{
    Environment generatedEnvironment = Environment(envSizeX, envSizeY, envColours.locationColour);
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
\
    // replace rows of locations with plants
    auto& rows = generatedEnvironment.getLocations();
    for (int i = 0; i < rows.size(); i += 2) {
        for (auto& location : rows[i]) {
            generatedEnvironment.changeLocation(location->getX(), location->getY(), 
                shared_ptr<Soybean>(std::make_shared<Soybean>(location->getX(), location->getY(), envColours.soybeanColour, envColours.nectarColour, envColours.pollenColour, soybeanOverlays)));
        }
    }

    // add a hive
    int hive_x = rand() % envSizeX;
    int hive_y = rand() % envSizeY;
    auto hive = shared_ptr<Hive>(std::make_shared<Hive>(hive_x, hive_y, envColours.hiveColour));
    generatedEnvironment.changeLocation(hive_x, hive_y, hive);
    generatedEnvironment.setHive(hive);

    return generatedEnvironment;
}
