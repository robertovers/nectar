/**
 * FIT3161/3162 Computer Science Project
 * Insect Simulation for Improved Pollination and Pest Control
 * Group CS6
 * 
 * @file agent.cpp
 * @brief Abstract class for extension by simulation agents.
 * @date 2022-09-10
 */

#include <atomic>
#include <math.h>
#include <memory>
#include "agent.hpp"
#include "utility.hpp"

Agent::Agent() {
    id = ID::generateID();
}

Agent::~Agent() { }

shared_ptr<Location> Agent::getLocation(Environment& env) {
    vector2D_shared_ptr<Location>& locations = env.getLocations();
    int tile_x = floor(pos.x);
    int tile_y = floor(pos.y);

    // check coords are valid, then return corresponding Location pointer.
    if ( tile_x >= 0 && tile_x < env.getWidth() &&
         tile_y >= 0 && tile_y < env.getHeight() ) {
        return locations[tile_y][tile_x]; 
    };
    return nullptr;
}

shared_ptr<Location> Agent::getTarget() {
    return target;
}

void Agent::setTarget(shared_ptr<Location> t) {
    target = t;
}

int Agent::getID() {
    return id;
}

void Agent::moveRandomWalk() {
    // generate a random direction
    float dx = direction_u.x + (rand() % 3 - 1);
    float dy = direction_u.y + (rand() % 3 - 1);
    sf::Vector2f target_v = sf::Vector2f(dx, dy);

    // normalise to unit vector
    float dist = sqrt(pow(target_v.x, 2) + pow(target_v.y, 2));
    if (dist != 0) {
        sf::Vector2f target_u = target_v / dist; 
        direction_u = target_u;
    }
}

void Agent::moveToTarget() {
    // compute vector from current pos to target
    float target_x = target->getX() + 0.5; // offset by 0.5 to get center
    float target_y = target->getY() + 0.5;
    sf::Vector2f target_v = sf::Vector2f(target_x, target_y) - pos;

    // normalise to unit vector
    float dist = sqrt(pow(target_v.x, 2) + pow(target_v.y, 2));
    if (dist != 0) {
        sf::Vector2f target_u = target_v / dist; 
        direction_u = target_u;
    }
}

sf::Vector2f Agent::getPos() {
    return pos;
}
