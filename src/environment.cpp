#include "environment.hpp"
#include "location.hpp"

Environment::Environment(int width, int height) {
    this->width = width;
    this->height = height;
    this->locations = std::vector<shared_ptr<Location>>(0);
    for (int i = 0; i < width * height; i++) {
        locations.push_back(shared_ptr<Location>(new Location()));
    }
    /*this->locations = locations[width][height];*/
}

int Environment::getSize()
{
    return locations.size();
}
