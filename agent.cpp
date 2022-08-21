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
    int tile_x = floor(pos.x);
    int tile_y = floor(pos.y);
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
    direction_u = sf::Vector2f((rand() % 3 - 1) * velocity, (rand() % 3 - 1) * velocity);
}

void Agent::moveToTarget() {
    sf::Vector2f target_v = sf::Vector2f(target->getX() + 0.5, target->getY() + 0.5) - pos;
    sf::Vector2f target_u = target_v / (float) sqrt(pow(target_v.x, 2) + pow(target_v.y, 2));

    direction_u = target_u;
}