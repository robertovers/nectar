#include "environment.hpp"

Environment::Environment(int w, int h) : width(w), height(h) {
    for (int y=0; y<height; y++) {
        locations.push_back(vector_shared_ptr<Location>(width));
        for (int x=0; x<width; x++) {
            locations[y][x] = std::make_shared<Location>(x, y);
        }
    }
    initLookupTable();
}

void Environment::draw(sf::RenderTarget & target, sf::RenderStates states) {
    for (auto row : locations) {
        for (auto loc : row) {
            target.draw(*loc, states);
        }
    }
}

vector2D_shared_ptr<Location>& Environment::getLocations() { 
    return locations; 
}

shared_ptr<Location> Environment::getLocation(int x, int y)
{
    return locations[y][x];
}

shared_ptr<Hive> Environment::getHive() {
    return hive;
}

void Environment::setHive(shared_ptr<Hive> h) {
    hive = h;
}

int Environment::getSize() const  {
    return width * height;
}

int Environment::getWidth() const  {
    return width;
}

int Environment::getHeight() const {
    return height;
}

int Environment::agentCount() {
    int count = 0;
    for (auto& row : getLocations()) {
        for (auto& location : row) {
            count += location->numAgents();
        }
    }
    return count;
}

int Environment::plantCount() {
    int count = 0;
    for (auto& row : getLocations()) {
        for (auto& location : row) {
            count += location->isPlant();
        }
    }
    return count;
}

void Environment::changeLocation(int x, int y, shared_ptr<Location> newLocation)
{
    locations[y][x] = newLocation;
}

void Environment::incPollinatedCount() {
    pollinated_count += 1;
}

int Environment::getPollinatedCount() {
    return pollinated_count;
}

void Environment::initLookupTable() {
    for (auto row : locations) {
        for (auto loc : row) {
            auto nearbyPlant = findNearbyPlant(loc);
            if (nearbyPlant) {
                plant_table.insert(std::make_pair(loc->getID(), *nearbyPlant));
            }
        }
    }
}

opt_shared_ptr<Plant> Environment::getNearbyPlant(shared_ptr<Location> loc) {
    auto result = plant_table.find(loc->getID());
    if (result != plant_table.end()) {
        return result->second;
    } else {
        return { };
    }
}

opt_shared_ptr<Plant> Environment::findNearbyPlant(shared_ptr<Location> loc) {

    for (int ix=-2; ix<=2; ix++) {
        for (int iy=-2; iy<=2; iy++) {

            int tile_x = loc->getX() + ix;
            int tile_y = loc->getY() + iy;

            if ( tile_x >= 0 && tile_x < this->getWidth() &&
                 tile_y >= 0 && tile_y < this->getHeight() ) 
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