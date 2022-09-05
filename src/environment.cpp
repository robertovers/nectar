#include "environment.hpp"

Environment::Environment() : width(0), height(0) { }

Environment::Environment(int w, int h) : width(w), height(h) {
    for (int y=0; y<height; y++) {
        locations.push_back(vector_shared_ptr<Location>(width));
        for (int x=0; x<width; x++) {
            locations[y][x] = std::make_shared<Location>(x, y);
        }
    }
}

void Environment::draw(sf::RenderWindow &window) {
    for (auto row : locations) {
        for (auto loc : row) {
            loc->draw(window);
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

shared_ptr<Location>& Environment::getHive() {
    return hive;
}

void Environment::setHive(shared_ptr<Location> h) {
    hive = h;
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

void Environment::changeLocation(int x, int y, shared_ptr<Location> newLocation)
{
    locations[y][x] = newLocation;
}
