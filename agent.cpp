#include <atomic>
#include <math.h>
#include <memory>
#include "agent.hpp"

Agent::Agent() {
    id = generateID();
}

Agent::~Agent() { }

std::shared_ptr<Location> Agent::getLocation(Environment env) {
    vector2D_shared_ptr<Location>& locations = env.getLocations();
    int tile_x = floor(pos_x);
    int tile_y = floor(pos_y);
    if ( tile_x >= 0 && tile_x < env.getWidth() &&
         tile_y >= 0 && tile_y < env.getHeight() ) {
        return locations[tile_y][tile_x]; 
    };
    return std::make_shared<Location>();
}

std::shared_ptr<Location> Agent::getTarget() {
    return target;
}

int Agent::generateID() {
    static std::atomic<std::uint8_t> id { 0 };
    return id++;
}

int Agent::getID() {
    return id;
}