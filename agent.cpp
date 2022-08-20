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

void Agent::setTarget(shared_ptr<Location> t) {
    target = t;
}

int Agent::generateID() {
    static std::atomic<std::uint8_t> id { 0 };
    return id++;
}

int Agent::getID() {
    return id;
}

void Agent::moveRandomWalk() {
    pos_x += (rand() % 3 - 1) * velocity;
    pos_y += (rand() % 3 - 1) * velocity;
}

void Agent::moveToTarget() {
    float dx = target->getX() - pos_x;
    float dy = target->getY() - pos_y;
    float theta = atan(dy/dx);

    pos_x += ((dx > 0) - (dx < 0)) * cos(theta) * velocity;
    pos_y += ((dx > 0) - (dx < 0)) * sin(theta) * velocity;
}