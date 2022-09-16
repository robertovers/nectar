#include "plantLookup.hpp"

void PlantLookup::initLookupTable(Environment env) {
    for (auto row : env.getLocations()) {
        for (auto loc : row) {
            auto nearbyPlant = findNearbyPlant(loc, env);
            if (nearbyPlant) {
                plant_table.insert(std::make_pair(loc->getID(), *nearbyPlant));
            }
        }
    }
}

opt_shared_ptr<Plant> PlantLookup::getNearbyPlant(shared_ptr<Location> loc) {
    auto result = plant_table.find(loc->getID());
    if (result != plant_table.end()) {
        return result->second;
    } else {
        return { };
    }
}


opt_shared_ptr<Plant> PlantLookup::findNearbyPlant(shared_ptr<Location> loc, Environment env) {
    auto locations = env.getLocations();

    for (int ix=-2; ix<=2; ix++) {
        for (int iy=-2; iy<=2; iy++) {

            int tile_x = loc->getX() + ix;
            int tile_y = loc->getY() + iy;

            if ( tile_x >= 0 && tile_x < env.getWidth() &&
                 tile_y >= 0 && tile_y < env.getHeight() ) 
            {
                auto target = locations[tile_y][tile_x]; 

                if (target->isPlant()) {
                    auto res = std::dynamic_pointer_cast<Plant>(target);
                    return res;
                }
            }
        }
    }
    return { };
}