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

    // replace rows of locations with plants
    auto& rows = generatedEnvironment.getLocations();
    for (int i = 0; i < rows.size(); i += 2) {
        for (auto& location : rows[i]) {
            generatedEnvironment.changeLocation(location->getX(), location->getY(), 
                shared_ptr<Soybean>(std::make_shared<Soybean>(location->getX(), location->getY(), envColours.soybeanColour, envColours.nectarColour, envColours.pollenColour, soybeanOverlays)));
        }
    }

    return generatedEnvironment;
}
