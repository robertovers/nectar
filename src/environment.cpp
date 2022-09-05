#include "environment.hpp"

Environment::Environment() : width(0), height(0) { }

Environment::Environment(int w, int h) : width(w), height(h) {
    for (int y=0; y<height; y++) {
        locations.push_back(vector_shared_ptr<Location>(width));
        for (int x=0; x<width; x++) {
            locations[y][x] = std::make_shared<Location>(x, y);
        }
    }

    int hive_x = rand() % w;
    int hive_y = rand() % h;
    hive = std::make_shared<Hive>(hive_x, hive_y);

    locations[hive_y][hive_x] = hive;
}

vector2D_shared_ptr<Location>& Environment::getLocations() { 
    return locations; 
}

shared_ptr<Location> Environment::getLocation(int x, int y)
{
    return locations[y][x];
}

shared_ptr<Location>& Environment::getHive() {
    return hive;
}

int Environment::getSize() {
    return width * height;
}

int Environment::getWidth() {
    return width;
}

int Environment::getHeight() {
    return height;
}

// manually iterates through locations to count agents.
int Environment::agentCount() {
    int count = 0;
    for (auto& row : getLocations()) {
        for (auto& location : row) {
            count += location->numAgents();
        }
    }
    return count;
}

// TODO: add when advanced bee behavior branch is merged
//int Environment::plantCount() {
//    int count = 0;
//    for (auto& row : getLocations()) {
//        for (auto& location : row) {
//            count += location.isPlant();
//        }
//    }
//}

void Environment::changeLocation(int x, int y, shared_ptr<Location> newLocation)
{
    locations[y][x] = newLocation;
}
