#include <math.h>
#include "agent.hpp"

Agent::~Agent() { }

std::shared_ptr<Location>& Agent::getLocation(Environment env) {
    vector2D_shared_ptr<Location>& locations = env.getLocations();
    return locations[floor(pos_y)][floor(pos_x)]; 
}

std::shared_ptr<Location>& Agent::getTarget() {
    return target;
}