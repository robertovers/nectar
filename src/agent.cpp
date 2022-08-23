#include <SFML/Graphics.hpp>
#include "agent.hpp"

Agent::~Agent(){}

Agent::Agent(){}

Agent::Agent(float x, float y) {
    pos_x = x;
    pos_y = y;
}

shared_ptr<Location> Agent::getLocation(Environment env) {
    for (auto loc : env.getLocations()) {
        int tile_x = loc->getX()*loc->getWidth();
        int tile_y = loc->getY()*loc->getHeight();
        if ( 
            pos_x+display_width > tile_x and 
            pos_x+display_width <= tile_x + loc->getWidth() and
            pos_y+display_height > tile_y and 
            pos_y+display_height <= tile_y + loc->getHeight() )
            {
                return loc;
            }
    }
    return std::make_shared<Location>(); 
}

shared_ptr<Location> Agent::getTarget() {
    return target;
}