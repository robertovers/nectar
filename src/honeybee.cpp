#include "honeybee.hpp"
#include "agent.hpp"
#include "honeybee.hpp"
#include "plant.hpp"
#include <iostream>

HoneyBee::HoneyBee() {
    pos.x = 0;
    pos.y = 0;
    direction_u = sf::Vector2f(0, 0);
}

HoneyBee::HoneyBee(float x, float y) {
    pos.x = x;
    pos.y = y;
    direction_u = sf::Vector2f(0, 0);
}

void HoneyBee::update(Environment env) {

    shared_ptr<Location> cur_loc = getLocation(env);

    if (target == nullptr and cur_loc != nullptr) { 

        auto found = scan(env);

        if (found == nullptr) {
            moveRandomWalk();
        } else {
            target = found;
        }

    } else if (cur_loc == target) {

        if (target == env.getHive()) {
            target = nullptr;
            moveRandomWalk();
        } else {
            target = env.getHive();
        }

    } else if (target != nullptr) {

        moveToTarget();

    } else {

        moveRandomWalk();

    }

    pos += direction_u * velocity;

    shared_ptr<Location> new_loc = getLocation(env);

    if (new_loc != nullptr && cur_loc != nullptr && new_loc != cur_loc) {
        cur_loc->removeAgent(*this);
        new_loc->addAgent(*this);
    }
}

void HoneyBee::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // add offset to existing transformations
    states.transform.translate(pos);

    sf::CircleShape c;
    c.setRadius(0.25);
    c.setFillColor(sf::Color::White);
    target.draw(c, states);
    

    //sf::Vertex line[] = {
    //    sf::Vertex(sf::Vector2f(1,1)),
    //    sf::Vertex(direction_u)
    //};
    //target.draw(line, 2, sf::Lines);
}

shared_ptr<Location> HoneyBee::scan(Environment env) {
    auto current_loc = getLocation(env);
    auto locations = env.getLocations();

    for (int ix=-2; ix<=2; ix++) {
        for (int iy=-2; iy<=2; iy++) {
            int tile_x = current_loc->getX() + ix;
            int tile_y = current_loc->getY() + iy;
            if ( tile_x >= 0 && tile_x < env.getWidth() &&
                 tile_y >= 0 && tile_y < env.getHeight() ) 
            {
                auto loc = locations[tile_y][tile_x]; 
                if (loc->isPlant()) return loc;
            }
        }
    }
    return nullptr;
} 
