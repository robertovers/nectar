#include "environment.hpp"
#include "location.hpp"

Environment::Environment(int width, int height) {
    this->width = width;
    this->height = height;
    /*this->locations = locations[width][height];*/
}

int Environment::getSize()
{
    return locations.size();
}
