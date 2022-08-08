#include <algorithm>
#include "mapGenerator.hpp"
#include "environment.hpp"


BasicMapGenerator::BasicMapGenerator(int envSizeX = 1, int envSizeY = 1,
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
    int excessPlants = cropCount + flowerCount - locationCount;   // number of plants that cannot fit on the map
    int* plantsCount[NUMBER_OF_PLANT_TYPES] = { &flowerCount, &cropCount };
 
    for (int i = 0; i++; i < NUMBER_OF_PLANT_TYPES) {
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

Environment BasicMapGenerator::generateEnvironment() {
    Environment generatedEnvironment = Environment();
    // crops and flowers can't share a tile
}
