#include "environment.hpp"

Environment::Environment(int w, int h) : width(w), height(h) {
    for (int y=0; y<height; y++) {
        locations.push_back(vector_shared_ptr<Location>(width));
        for (int x=0; x<width; x++) {
            locations[y][x] = std::make_shared<Location>(x, y);
        }
    }
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