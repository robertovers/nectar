#include <algorithm>
#include "mapGenerator.hpp"
#include "environment.hpp"
#include "location.hpp"

BasicMapGenerator::BasicMapGenerator(int envSizeX, int envSizeY,
                      int beeCount = 0, int waspCount = 0, int caterpillarCount = 0,
                      int flowerCount = 0, int cropCount = 0) {
    // determines map size
    this->envSizeX = envSizeX;
    this->envSizeY = envSizeY;

    // number of agents
    this->beeCount = beeCount;
    this->caterpillarCount = caterpillarCount;
    this->waspCount = waspCount;

    // Plants
    // Only want one plant per tile, so if there's more plants than tiles, 
    // reduce the number of crops and/or flowers
    const int NUMBER_OF_PLANT_TYPES = 2;  // crops and flowers
    int locationCount = this->envSizeX * this->envSizeY;  // number of tiles in map
    int excessPlants = totalPlants() - locationCount;   // number of plants that cannot fit on the map
    int* plantsCount[NUMBER_OF_PLANT_TYPES] = { &flowerCount, &cropCount };
 
    for (int i = 0; i < NUMBER_OF_PLANT_TYPES; i++) {
        if (excessPlants <= 0) {
            // no more plants to get rid of
            break;
        }

        int plantsToSubtract = std::min(excessPlants, *plantsCount[i]);
        *plantsCount[i] -= plantsToSubtract;
        excessPlants -= plantsToSubtract;         
    }
        
    this->cropCount = cropCount;
    this->flowerCount = flowerCount;
}

// return the number of plants to be generated on the map
int BasicMapGenerator::totalPlants() {
    return flowerCount + cropCount;
}

// return number of insects to be generated on the map
int BasicMapGenerator::totalAgents() {
    return waspCount + beeCount + caterpillarCount;
}

Environment BasicMapGenerator::generateEnvironment() {
    Environment generatedEnvironment = Environment();
    // randomly scatter insects
    // TODO: more than bees
    int placedBees = 0;
    while (placedBees <= beeCount) {
        float trueX = rand() / (static_cast <float> (RAND_MAX / envSizeX));
        float trueY = rand() / (static_cast <float> (RAND_MAX / envSizeY));
        // TODO: create bee with given x, y
    }

    int placedCrops = 0;
    int plantsTotal = totalPlants();
    int plantsPlaced = 0;
    
    // place plants on locations
    for (int tilesLeft = generatedEnvironment.getSize(); tilesLeft > 0; tilesLeft -= 1) {
        // TODO: properly iterate through tiles in environment
        Location currentLocation = Location();

        // random chance to place a plant
        float placeChance = (static_cast<float>(plantsTotal) - plantsPlaced) / tilesLeft;
        float rolledChance = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);  // 0.0 - 1.0
        if (placeChance >= rolledChance) {
            // randomly pick which plant to place
            rolledChance = static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
            float cropChance = (cropCount - static_cast<float>(placedCrops)) / (plantsTotal - plantsPlaced);
            if (cropChance >= rolledChance) {
                // TODO: currentLocation.addObject(Crop())
                placedCrops += 1;
            }
            else {
                // TODO: currentLocation.addObject(Flower)
            }

            plantsPlaced += 1;
        }
    }
    return generatedEnvironment;
}
